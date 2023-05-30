/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:14:14 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/30 13:27:51 by akorompa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_map_char(char c)
{
	if (c == ' ' || c == '\n' || (c >= 9 && c <= 13))
		return (1);
	else if (c == '1' || c == '0')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (i);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	if (is_empty_line(line))
		return (0);
	while (line[i])
	{
		if (!is_map_char(line[i]))
			break ;
		i++;
	}
	if (i == (int)ft_strlen(line))
		return (i);
	return (0);
}

int	map_size(char **file, t_data *data)
{
	int	i;
	int	size;

	size = 0;
	i = data->file_size - 1;
	while (file[i] && is_map_line(file[i]))
	{
		size++;
		i--;
	}
	return (size);
}

int	ft_strlen_mod(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	return (len);
}
