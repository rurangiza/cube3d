/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:41:53 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/23 11:15:23 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*store_texture(char *str)
{
	char **tmp;
	char	*texture;

	tmp = ft_split(str, ' ');
	if (!tmp)
		return (NULL);
	texture = get_map_line(tmp[1]);
	if(!texture)
		return (NULL);
	ft_free_tab(tmp);
	return (texture);
}

int	get_texture(t_data *data, char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (ft_strncmp(file[i], "NO", 2) == 0)
			data->texture.north = store_texture(file[i]);	
		// else if (ft_strncmp(file[i], "SO", 2) == 0)
		// 	data->texture.south = store_texture(file[i]);
		// else if (ft_strncmp(file[i], "WE", 2) == 0)
		// 	data->texture.west = store_texture(file[i]);
		// else if (ft_strncmp(file[i], "EA", 2) == 0)
		// 	data->texture.east = store_texture(file[i]);	
		i++;
	}
	
	return (VALID);
}