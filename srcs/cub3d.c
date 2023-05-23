/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:59:59 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/23 11:06:15 by akorompa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	raycast_optcor_col_height(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.wall_dist = fabs((data->ray.map_x - data->ray.ray_pos_x
					+ (1 - data->ray.step_x) / 2) / data->ray.ray_dir_x);
	else
		data->ray.wall_dist = fabs((data->ray.map_y - data->ray.ray_pos_y
					+ (1 - data->ray.step_y) / 2) / data->ray.ray_dir_y);
	data->line_height = abs((int)((double)data->screen_height
				/ data->ray.wall_dist));
	data->draw_start = -data->line_height / 2 + (double)data->screen_height / 2;
	data->draw_end = data->line_height / 2 + (double)data->screen_height / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	if (data->draw_end >= data->screen_height)
		data->draw_end = data->screen_height - 1;
}

void	raycast_tex_pos(t_data *data)
{
	if (data->ray.side == 1)
	{
		data->texture.wall_x = data->ray.ray_pos_x + data->ray.wall_dist
			* data->ray.ray_dir_x;
	}
	else
	{
		data->texture.wall_x = data->ray.ray_pos_y + data->ray.wall_dist
			* data->ray.ray_dir_y;
	}
	data->texture.wall_x -= floor(data->texture.wall_x);
	data->texture.tex_x = (int)(data->texture.wall_x * data->texture.widht);
	if (data->ray.side == 0 && data->ray.ray_dir_x > 0)
		data->texture.tex_x = data->texture.widht - data->texture.tex_x - 1;
	if (data->ray.side == 1 && data->ray.ray_dir_y < 0)
		data->texture.tex_x = data->texture.widht - data->texture.tex_x - 1;
}

int	get_tex_color(t_data *data)
{
	return (((unsigned int *)data->texture.tex_tab[data->color])
		[(data->texture.widht * data->texture.tex_y + data->texture.tex_x)]);
}

void	raycast_draw(t_data *data)
{
	data->y = data->draw_start;
	while (data->y < data->draw_end)
	{
		data->texture.tex_y = (int)((data->y * 2 - data->screen_height
					+ data->line_height) * (data->texture.height / 2)
				/ data->line_height);
		if (data->ray.side == 0 && data->ray.ray_dir_x < 0)
			data->color = 2;
		if (data->ray.side == 0 && data->ray.ray_dir_x > 0)
			data->color = 3;
		if (data->ray.side == 1 && data->ray.ray_dir_y < 0)
			data->color = 0;
		if (data->ray.side == 1 && data->ray.ray_dir_y > 0)
			data->color = 1;
		data->texture.tex_color = get_tex_color(data);
		my_mlx_pixel_put(&data->mlx, data->x, data->y, data->texture.tex_color);
		data->y++;
	}
}

int	cub3d(t_data *data)
{
	if (data->cam.move_up || data->cam.move_back || data->cam.move_right
		|| data->cam.move_left || data->cam.turn || data->cam.display)
	{
		data->cam.display = false;
		data->x = 0;
		data->y = 0;
		fill_roof_ceilling(data);
		move(data, &data->cam);
		while (data->x <= data->screen_widht)
		{
			raycast_init(data);
			raycast_vector_dir(data);
			raycast_find_wall(data);
			raycast_optcor_col_height(data);
			raycast_tex_pos(data);
			raycast_draw(data);
			data->x++;
		}
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->mlx.img, 0, 0);
	return (0);
}
