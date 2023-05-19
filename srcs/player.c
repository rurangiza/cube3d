/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:28:31 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/16 15:42:50 by akorompa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	position_player(t_data *data, int i, int j, char c)
{
	data->cam.pos_X = (double)j + 0.5;
	data->cam.pos_Y = (double)i + 0.5;
	if (c == 'N')
	{
		data->cam.dir_X = 0;
		data->cam.dir_Y = -1;
		data->cam.plane_X = 1;
		data->cam.plane_Y = 0;
	}
	if (c == 'S')
	{
		data->cam.dir_X = 0;
		data->cam.dir_Y = 1;
		data->cam.plane_X = -1;
		data->cam.plane_Y = 0;
	}
	if (c == 'W')
	{
		data->cam.dir_X = -1;
		data->cam.dir_Y = 0;
		data->cam.plane_X = 0;
		data->cam.plane_Y = -1;
	}
	if (c == 'E')
	{
		data->cam.dir_X = 1;
		data->cam.dir_Y = 0;
		data->cam.plane_X = 0;
		data->cam.plane_Y = 1;
	}
}

void	get_player(t_data *data)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '0' || data->map[i][j] != '1' || data->map[i][j] != 32)
			{
				if (data->map[i][j] == 'N' || data->map[i][j] == 'E' || data->map[i][j] == 'S' || data->map[i][j] == 'W')
					position_player(data, i, j, data->map[i][j]);					
			}
			j++;
		}
		i++;
	}
}