/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:35:25 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/30 14:15:09 by akorompa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_char_map(char **map)
{
	int	j;
	int	i;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_map_char(map[i][j]))
			{
				ft_free_tab(map);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

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
