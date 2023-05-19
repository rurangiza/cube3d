/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:59:59 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/19 14:09:23 by akorompa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move(t_data *data, t_cam *cam)
{
	double	old_dir_x;
	double	old_plane_x;

	if (cam->move_up)
	{
		if (data->map[(int)(cam->pos_X + cam->dir_X * cam->speedWalking)][(int)cam->pos_Y] != 49 
			&& data->map[(int)((cam->pos_X + cam->dir_X * cam->speedWalking) + 0.1)][(int)cam->pos_Y] != 49
			&& data->map[(int)(cam->pos_X + cam->dir_X * cam->speedWalking)][(int)(cam->pos_Y + 0.1)] != 49
			&& data->map[(int)((cam->pos_X + cam->dir_X * cam->speedWalking) - 0.1)][(int)cam->pos_Y] != 49
			&& data->map[(int)(cam->pos_X + cam->dir_X * cam->speedWalking)][(int)(cam->pos_Y - 0.1)] != 49)
		{
			cam->pos_X += cam->dir_X * cam->speedWalking;
		}
		if (data->map[(int)cam->pos_X][(int)(cam->pos_Y + cam->dir_Y * cam->speedWalking)] != 49
			&& data->map[(int)(cam->pos_X + 0.1)][(int)(cam->pos_Y + cam->dir_Y * cam->speedWalking)] != 49
			&& data->map[(int)cam->pos_X][(int)((cam->pos_Y + cam->dir_Y * cam->speedWalking) + 0.1)] != 49
			&& data->map[(int)(cam->pos_X - 0.1)][(int)(cam->pos_Y + cam->dir_Y * cam->speedWalking)] != 49
			&& data->map[(int)cam->pos_X][(int)((cam->pos_Y + cam->dir_Y * cam->speedWalking) - 0.1)] != 49)
			cam->pos_Y += cam->dir_Y * cam->speedWalking;
	}
	if (cam->move_back)
	{
		if (data->map[(int)(cam->pos_X - cam->dir_X * cam->speedWalking)][(int)cam->pos_Y] != 49
			&& data->map[(int)(cam->pos_X - cam->dir_X * cam->speedWalking)][(int)(cam->pos_Y + 0.1)] != 49
			&& data->map[(int)((cam->pos_X - cam->dir_X * cam->speedWalking) + 0.1)][(int)cam->pos_Y] != 49
			&& data->map[(int)(cam->pos_X - cam->dir_X * cam->speedWalking)][(int)(cam->pos_Y - 0.1)] != 49
			&& data->map[(int)((cam->pos_X - cam->dir_X * cam->speedWalking) - 0.1)][(int)cam->pos_Y] != 49)
			cam->pos_X -= cam->dir_X * cam->speedWalking;
		if (data->map[(int)cam->pos_X][(int)(cam->pos_Y - cam->dir_Y * cam->speedWalking)] != 49
			&& data->map[(int)(cam->pos_X + 0.1)][(int)(cam->pos_Y - cam->dir_Y * cam->speedWalking)] != 49
			&& data->map[(int)cam->pos_X][(int)((cam->pos_Y - cam->dir_Y * cam->speedWalking) + 0.1)] != 49
			&& data->map[(int)(cam->pos_X - 0.1)][(int)(cam->pos_Y - cam->dir_Y * cam->speedWalking)] != 49
			&& data->map[(int)cam->pos_X][(int)((cam->pos_Y - cam->dir_Y * cam->speedWalking) - 0.1)] != 49)
			cam->pos_Y -= cam->dir_Y * cam->speedWalking;
	}
	if (cam->turn)
	{
		old_dir_x = cam->dir_X;
		cam->dir_X = cam->dir_X * cos(-cam->speedRotation) - cam->dir_Y * sin(-cam->speedRotation);
		cam->dir_Y = old_dir_x * sin(-cam->speedRotation) + cam->dir_Y * cos(-cam->speedRotation);
		old_plane_x = cam->plane_X;
		cam->plane_X = cam->plane_X * cos(-cam->speedRotation) - cam->plane_Y * sin(-cam->speedRotation);
		cam->plane_Y = old_plane_x * sin(-cam->speedRotation) + cam->plane_Y * cos(-cam->speedRotation);  
	}
	if (cam->move_right)
	{
		if (data->map[(int)(cam->pos_X + cam->plane_X * cam->speedWalking)][(int)cam->pos_Y] != 49
			&& data->map[(int)(cam->pos_X + cam->plane_X * cam->speedWalking)][(int)(cam->pos_Y + 0.1)] != 49
			&& data->map[(int)((cam->pos_X + cam->plane_X * cam->speedWalking) + 0.1)][(int)cam->pos_Y] != 49
			&& data->map[(int)(cam->pos_X + cam->plane_X * cam->speedWalking)][(int)(cam->pos_Y - 0.1)] != 49
			&& data->map[(int)((cam->pos_X + cam->plane_X * cam->speedWalking) - 0.1)][(int)cam->pos_Y] != 49)
			cam->pos_X += cam->plane_X * cam->speedWalking;
		if (data->map[(int)cam->pos_X][(int)(cam->pos_Y + cam->plane_Y * cam->speedWalking)] != 49
			&& data->map[(int)(cam->pos_X + 0.1)][(int)(cam->pos_Y + cam->plane_Y * cam->speedWalking)] != 49
			&& data->map[(int)cam->pos_X][(int)((cam->pos_Y + cam->plane_Y * cam->speedWalking) + 0.1)] != 49
			&& data->map[(int)(cam->pos_X - 0.1)][(int)(cam->pos_Y + cam->plane_Y * cam->speedWalking)] != 49
			&& data->map[(int)cam->pos_X][(int)((cam->pos_Y + cam->plane_Y * cam->speedWalking) - 0.1)] != 49)
			cam->pos_Y += cam->plane_Y * cam->speedWalking;
	}
	if (cam->move_left)
	{
		if (data->map[(int)(cam->pos_X - cam->plane_X * cam->speedWalking)][(int)cam->pos_Y] != 49
			&& data->map[(int)(cam->pos_X - cam->plane_X * cam->speedWalking)][(int)(cam->pos_Y + 0.1)] != 49
			&& data->map[(int)((cam->pos_X - cam->plane_X * cam->speedWalking) + 0.1)][(int)cam->pos_Y] != 49
			&& data->map[(int)(cam->pos_X - cam->plane_X * cam->speedWalking)][(int)(cam->pos_Y - 0.1)] != 49
			&& data->map[(int)((cam->pos_X - cam->plane_X * cam->speedWalking) - 0.1)][(int)cam->pos_Y] != 49)
			cam->pos_X -= cam->plane_X * cam->speedWalking;
		if (data->map[(int)cam->pos_X][(int)(cam->pos_Y - cam->plane_Y * cam->speedWalking)] != 49
			&& data->map[(int)(cam->pos_X + 0.1)][(int)(cam->pos_Y - cam->plane_Y * cam->speedWalking)] != 49
			&& data->map[(int)cam->pos_X][(int)((cam->pos_Y - cam->plane_Y * cam->speedWalking) + 0.1)] != 49
			&& data->map[(int)(cam->pos_X - 0.1)][(int)(cam->pos_Y - cam->plane_Y * cam->speedWalking)] != 49
			&& data->map[(int)cam->pos_X][(int)((cam->pos_Y - cam->plane_Y * cam->speedWalking) - 0.1)] != 49)
			cam->pos_Y -= cam->plane_Y * cam->speedWalking;
	}
}

void	fill_black(t_data *data)
{
	int i;
	
	i = 0;
	while(i < data->screen_height / 2)
	{
		for(int j = 0; j < data->screen_widht; j++)
			my_mlx_pixel_put(&data->mlx, j, i, data->c_color);
		i++;
	}
	while( i < data->screen_height )
	{
		for (int j = 0; j < data->screen_widht; j++)
			my_mlx_pixel_put(&data->mlx, j, i, data->f_color);
		i++;
	}
}

int	cub3d(t_data *data)
{
	if (data->cam.move_up || data->cam.move_back || data->cam.move_right || data->cam.move_left || data->cam.turn || data->cam.display)
	{
		data->cam.display = false;
		data->x = 0;
		data->y = 0;
		fill_black(data);
		move(data, &data->cam);
		while(data->x <= data->screen_widht)
		{
			data->ray.cam_x = (2 * (double)data->x / (double)data->screen_widht) - 1;
			data->ray.ray_pos_x = data->cam.pos_X;
			data->ray.ray_pos_y = data->cam.pos_Y;
			data->ray.ray_dir_x = data->cam.dir_X + data->cam.plane_X * data->ray.cam_x;
			data->ray.ray_dir_y = data->cam.dir_Y + data->cam.plane_Y * data->ray.cam_x;
			data->ray.map_x = (int)data->ray.ray_pos_x;
			data->ray.map_y = (int)data->ray.ray_pos_y;
			data->ray.delta_dist_x = sqrt(1 + (data->ray.ray_dir_y * data->ray.ray_dir_y)/(data->ray.ray_dir_x * data->ray.ray_dir_x));
			data->ray.delta_dist_y = sqrt(1 + (data->ray.ray_dir_x * data->ray.ray_dir_x)/(data->ray.ray_dir_y * data->ray.ray_dir_y));
			data->ray.hit = 0;
			
			if (data->ray.ray_dir_x < 0)
			{
				data->ray.step_x = -1;
				data->ray.side_dist_x = (data->ray.ray_pos_x - data->ray.map_x) * data->ray.delta_dist_x;
			}
			else
			{
				data->ray.step_x = 1;
				data->ray.side_dist_x = (data->ray.map_x + 1.0 - data->ray.ray_pos_x) * data->ray.delta_dist_x;
			}
			if (data->ray.ray_dir_y < 0)
			{
				data->ray.step_y = -1;
				data->ray.side_dist_y = (data->ray.ray_pos_y - data->ray.map_y) * data->ray.delta_dist_y;
			}
			else
			{
				data->ray.step_y = 1;
				data->ray.side_dist_y = (data->ray.map_y + 1.0 - data->ray.ray_pos_y) * data->ray.delta_dist_y;
			}
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
			if (data->ray.side == 0)
				data->ray.wall_dist = fabs((data->ray.map_x - data->ray.ray_pos_x + (1 - data->ray.step_x) / 2) / data->ray.ray_dir_x);
			else
				data->ray.wall_dist = fabs((data->ray.map_y - data->ray.ray_pos_y + (1 - data->ray.step_y) / 2) / data->ray.ray_dir_y);
			data->line_height = abs((int)((double)data->screen_height / data->ray.wall_dist));
			data->draw_start = -data->line_height / 2 + (double)data->screen_height / 2;
			data->draw_end = data->line_height / 2 + (double)data->screen_height / 2;
			if (data->draw_start < 0)
				data->draw_start = 0;
			if (data->draw_end >= data->screen_height)
				data->draw_end = data->screen_height - 1;
			data->y = data->draw_start;
			while (data->y < data->draw_end)
			{
				data->color = 0xf2f2f2;
				if (data->ray.side == 1)
					data->color = 0xCCCCCC;
				my_mlx_pixel_put(&data->mlx, data->x, data->y, data->color);
				data->y++;
			}
			data->x++;
		}
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->mlx.img, 0, 0);
	return(0);
}
