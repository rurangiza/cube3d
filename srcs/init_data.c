/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:45:07 by akorompa          #+#    #+#             */
/*   Updated: 2023/04/28 16:49:39 by akorompa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N')
			{
				data->ray.pos_x = i;
				data->ray.pos_y = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	init_data(t_data *data)
{
	get_pos(data);
	data->ray.dir_x = -1;
	data->ray.dir_y = 0;
	data->ray.plane_x = 0;
	data->ray.plane_y = 0.66;
	data->ray.time = 0;
	data->ray.old_time = 0;
}