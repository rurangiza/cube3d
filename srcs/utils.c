/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:43:53 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/30 11:48:10 by akorompa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*get_map_line(char *str)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen_mod(str);
	line = malloc(sizeof(char *) * (len + 1));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_all(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	i = 0;
	while (data->texture.texture[i])
	{
		free(data->texture.texture[i]);
		i++;
	}
	free(data->map);
	free(data->texture.tex);
	free(data->texture.texture);
	free(data->texture.tex_tab);
}
