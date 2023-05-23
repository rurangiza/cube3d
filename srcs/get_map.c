/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:35:25 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/23 13:22:31 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**get_map(char **file, t_data *data)
{
	char	**map;
	int		size;
	int		i;
	int		j;

	size = map_size(file, data);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	i = 0;
	j = data->file_size - size;
	while (i < size)
	{
		map[i] = get_map_line(file[j]);
		j++;
		i++;
	}
	map[i] = 0;
	return (map);
}
