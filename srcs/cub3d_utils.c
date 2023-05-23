/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:03:14 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/23 12:00:20 by akorompa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	fill_roof_ceilling(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->screen_height / 2)
	{
		j = 0;
		while (j < data->screen_widht)
		{
			my_mlx_pixel_put(&data->mlx, j, i, data->c_color);
			j++;
		}
		i++;
	}
	while (i < data->screen_height)
	{
		j = 0;
		while (j < data->screen_widht)
		{
			my_mlx_pixel_put(&data->mlx, j, i, data->f_color);
			j++;
		}
		i++;
	}
}

void	raycast_init(t_data *data)
{
	data->ray.cam_x = (2 * (double)data->x / (double)data->screen_widht) - 1;
	data->ray.ray_pos_x = data->cam.pos_x;
	data->ray.ray_pos_y = data->cam.pos_y;
	data->ray.ray_dir_x = data->cam.dir_x + data->cam.plane_x * data->ray.cam_x;
	data->ray.ray_dir_y = data->cam.dir_y + data->cam.plane_y * data->ray.cam_x;
	data->ray.map_x = (int)data->ray.ray_pos_x;
	data->ray.map_y = (int)data->ray.ray_pos_y;
	data->ray.delta_dist_x = sqrt(1 + (data->ray.ray_dir_y
				* data->ray.ray_dir_y) / (data->ray.ray_dir_x
				* data->ray.ray_dir_x));
	data->ray.delta_dist_y = sqrt(1 + (data->ray.ray_dir_x
				* data->ray.ray_dir_x) / (data->ray.ray_dir_y
				* data->ray.ray_dir_y));
	data->ray.hit = 0;
}

void	raycast_vector_dir(t_data *data)
{
	if (data->ray.ray_dir_x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_dist_x = (data->ray.ray_pos_x - data->ray.map_x)
			* data->ray.delta_dist_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_dist_x = (data->ray.map_x + 1.0 - data->ray.ray_pos_x)
			* data->ray.delta_dist_x;
	}
	if (data->ray.ray_dir_y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_dist_y = (data->ray.ray_pos_y - data->ray.map_y)
			* data->ray.delta_dist_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_dist_y = (data->ray.map_y + 1.0 - data->ray.ray_pos_y)
			* data->ray.delta_dist_y;
	}
}

void	raycast_find_wall(t_data *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.side_dist_x < data->ray.side_dist_y)
		{
			data->ray.side_dist_x += data->ray.delta_dist_x;
			data->ray.map_x += data->ray.step_x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dist_y += data->ray.delta_dist_y;
			data->ray.map_y += data->ray.step_y;
			data->ray.side = 1;
		}
		if (data->map[(int)data->ray.map_x][(int)data->ray.map_y] == '1')
			data->ray.hit = 1;
	}
}
