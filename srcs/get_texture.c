/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:41:53 by akorompa          #+#    #+#             */
/*   Updated: 2023/06/07 12:29:20 by akorompa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*store_texture(char *str)
{
	char	**tmp;
	char	*texture;

	tmp = ft_split(str, ' ');
	if (!tmp)
		return (NULL);
	texture = get_map_line(tmp[1]);
	if (!texture)
		return (NULL);
	ft_free_tab(tmp);
	return (texture);
}

void	init_texture(char **tab, t_data *data)
{
	int	j;

	j = -1;
	while (++j < 4)
		data->count[j] = 0;
	tab[0] = NULL;
	tab[1] = NULL;
	tab[2] = NULL;
	tab[3] = NULL;
}

int	exist_texture(char **tab)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!tab[i])
			return (0);
		i++;
	}
	return (1);
}

void	texture(t_data *data, char **file, int i)
{
	if (ft_strncmp(file[i], "NO", 2) == 0)
	{
		data->texture.texture[0] = store_texture(file[i]);
		data->count[0]++;
	}
	if (ft_strncmp(file[i], "SO", 2) == 0)
	{
		data->texture.texture[1] = store_texture(file[i]);
		data->count[1]++;
	}
	if (ft_strncmp(file[i], "WE", 2) == 0)
	{
		data->texture.texture[2] = store_texture(file[i]);
		data->count[2]++;
	}
	if (ft_strncmp(file[i], "EA", 2) == 0)
	{
		data->texture.texture[3] = store_texture(file[i]);
		data->count[3]++;
	}
}

int	get_texture(t_data *data, char **file)
{
	int	i;

	i = 0;
	data->texture.texture = malloc(sizeof(char *) * 5);
	if (!data->texture.texture)
		return (0);
	init_texture(data->texture.texture, data);
	while (file[i])
	{
		texture(data, file, i);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (data->count[i] != 1)
			return (1);
		i++;
	}
	data->texture.texture[4] = 0;
	if (!exist_texture(data->texture.texture))
		return (1);
	ft_free_tab(file);
	return (0);
}
