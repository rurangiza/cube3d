/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:38:36 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/23 12:09:26 by akorompa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_up(t_data *data, t_cam *cam)
{
	double	x;
	double	y;

	x = cam->pos_x + cam->dir_x * cam->speedwalking;
	y = cam->pos_y + cam->dir_y * cam->speedwalking;
	if (data->map[(int)(x)][(int)cam->pos_y] != 49
		&& data->map[(int)((x) + 0.1)][(int)cam->pos_y] != 49
		&& data->map[(int)(x)][(int)(cam->pos_y + 0.1)] != 49
		&& data->map[(int)((x) - 0.1)][(int)cam->pos_y] != 49
		&& data->map[(int)(x)][(int)(cam->pos_y - 0.1)] != 49)
		cam->pos_x += cam->dir_x * cam->speedwalking;
	if (data->map[(int)cam->pos_x][(int)(y)] != 49
		&& data->map[(int)(cam->pos_x + 0.1)][(int)(y)] != 49
		&& data->map[(int)cam->pos_x][(int)((y) + 0.1)] != 49
		&& data->map[(int)(cam->pos_x - 0.1)][(int)(y)] != 49
		&& data->map[(int)cam->pos_x][(int)((y) - 0.1)] != 49)
		cam->pos_y += cam->dir_y * cam->speedwalking;
}

void	move_back(t_data *data, t_cam *cam)
{
	double	x;
	double	y;

	x = cam->pos_x - cam->dir_x * cam->speedwalking;
	y = cam->pos_y - cam->dir_y * cam->speedwalking;
	if (data->map[(int)(x)][(int)cam->pos_y] != 49
		&& data->map[(int)(x)][(int)(cam->pos_y + 0.1)] != 49
		&& data->map[(int)((x) + 0.1)][(int)cam->pos_y] != 49
		&& data->map[(int)(x)][(int)(cam->pos_y - 0.1)] != 49
		&& data->map[(int)((x) - 0.1)][(int)cam->pos_y] != 49)
		cam->pos_x -= cam->dir_x * cam->speedwalking;
	if (data->map[(int)cam->pos_x][(int)(y)] != 49
		&& data->map[(int)(cam->pos_x + 0.1)][(int)(y)] != 49
		&& data->map[(int)cam->pos_x][(int)((y) + 0.1)] != 49
		&& data->map[(int)(cam->pos_x - 0.1)][(int)(y)] != 49
		&& data->map[(int)cam->pos_x][(int)((y) - 0.1)] != 49)
		cam->pos_y -= cam->dir_y * cam->speedwalking;
}

void	turn(t_cam *cam)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cam->dir_x;
	cam->dir_x = cam->dir_x * cos(-cam->speedrotation)
		- cam->dir_y * sin(-cam->speedrotation);
	cam->dir_y = old_dir_x * sin(-cam->speedrotation)
		+ cam->dir_y * cos(-cam->speedrotation);
	old_plane_x = cam->plane_x;
	cam->plane_x = cam->plane_x * cos(-cam->speedrotation)
		- cam->plane_y * sin(-cam->speedrotation);
	cam->plane_y = old_plane_x * sin(-cam->speedrotation)
		+ cam->plane_y * cos(-cam->speedrotation);
}

void	move_right(t_data *data, t_cam *cam)
{
	double	x;
	double	y;

	x = cam->pos_x + cam->plane_x * cam->speedwalking;
	y = cam->pos_y + cam->plane_y * cam->speedwalking;
	if (data->map[(int)(x)][(int)cam->pos_y] != 49
		&& data->map[(int)(x)][(int)(cam->pos_y + 0.1)] != 49
		&& data->map[(int)((x) + 0.1)][(int)cam->pos_y] != 49
		&& data->map[(int)(x)][(int)(cam->pos_y - 0.1)] != 49
		&& data->map[(int)((x) - 0.1)][(int)cam->pos_y] != 49)
		cam->pos_x += cam->plane_x * cam->speedwalking;
	if (data->map[(int)cam->pos_x][(int)(y)] != 49
		&& data->map[(int)(cam->pos_x + 0.1)][(int)(y)] != 49
		&& data->map[(int)cam->pos_x][(int)((y) + 0.1)] != 49
		&& data->map[(int)(cam->pos_x - 0.1)][(int)(y)] != 49
		&& data->map[(int)cam->pos_x][(int)((y) - 0.1)] != 49)
		cam->pos_y += cam->plane_y * cam->speedwalking;
}

void	move(t_data *data, t_cam *cam)
{
	if (cam->move_up)
		move_up(data, cam);
	if (cam->move_back)
		move_back(data, cam);
	if (cam->turn)
		turn(cam);
	if (cam->move_right)
		move_right(data, cam);
	if (cam->move_left)
		move_left(data, cam);
}
