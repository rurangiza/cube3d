/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:28:22 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/23 15:56:56 by akorompa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_left(t_data *data, t_cam *cam)
{
	double	x;
	double	y;

	x = cam->pos_x - cam->plane_x * cam->speedwalking;
	y = cam->pos_y - cam->plane_y * cam->speedwalking;
	if (data->map[(int)cam->pos_y][(int)x] != 49
		&& data->map[(int)(cam->pos_y + 0.1)][(int)x] != 49
		&& data->map[(int)cam->pos_y][(int)(x + 0.1)] != 49
		&& data->map[(int)(cam->pos_y - 0.1)][(int)x] != 49
		&& data->map[(int)cam->pos_y][(int)(x - 0.1)] != 49)
		cam->pos_x -= cam->plane_x * cam->speedwalking;
	if (data->map[(int)y][(int)cam->pos_x] != 49
		&& data->map[(int)y][(int)(cam->pos_x + 0.1)] != 49
		&& data->map[(int)(y + 0.1)][(int)cam->pos_x] != 49
		&& data->map[(int)y][(int)(cam->pos_x - 0.1)] != 49
		&& data->map[(int)(y - 0.1)][(int)cam->pos_x] != 49)
		cam->pos_y -= cam->plane_y * cam->speedwalking;
}
