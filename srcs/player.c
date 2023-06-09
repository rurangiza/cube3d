/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:28:31 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/23 15:31:50 by akorompa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	position_player_2(t_data *data, char c)
{
	if (c == 'W')
	{
		data->cam.dir_x = -1;
		data->cam.dir_y = 0;
		data->cam.plane_x = 0;
		data->cam.plane_y = -1;
	}
	if (c == 'E')
	{
		data->cam.dir_x = 1;
		data->cam.dir_y = 0;
		data->cam.plane_x = 0;
		data->cam.plane_y = 1;
	}
}

void	position_player(t_data *data, int i, int j, char c)
{
	data->cam.pos_x = (double)j + 0.5;
	data->cam.pos_y = (double)i + 0.5;
	if (c == 'N')
	{
		data->cam.dir_x = 0;
		data->cam.dir_y = -1;
		data->cam.plane_x = 1;
		data->cam.plane_y = 0;
	}
	if (c == 'S')
	{
		data->cam.dir_x = 0;
		data->cam.dir_y = 1;
		data->cam.plane_x = -1;
		data->cam.plane_y = 0;
	}
	position_player_2(data, c);
}

void	get_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '0' || data->map[i][j] != '1'
				|| data->map[i][j] != 32)
			{
				if (data->map[i][j] == 'N' || data->map[i][j] == 'E'
					|| data->map[i][j] == 'S' || data->map[i][j] == 'W')
					position_player(data, i, j, data->map[i][j]);
			}
			j++;
		}
		i++;
	}
}
