/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:14:53 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/30 11:33:44 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	int_to_color(t_rgb *rgb)
{
	int	color;

	color = (rgb->r << 16) + (rgb->g << 8) + rgb->b;
	return (color);
}

int	ft_tablen(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

int	store_color(char *str)
{
	t_rgb	rgb;
	int		color;
	char	**tmp;
	char	**line;

	color = 0;
	tmp = ft_split(str, ' ');
	if (!tmp)
		return (0);
	line = ft_split(tmp[1], ',');
	if (!line)
		return (0);
	if (ft_tablen(line) > 3 || ft_tablen(tmp) > 2)
	{
		ft_free_tab(tmp);
		ft_free_tab(line);
		return (errormsg("map: store_color(): too many values", -1));
	}
	ft_free_tab(tmp);
	rgb.r = ft_atoi(line[0]);
	rgb.g = ft_atoi(line[1]);
	rgb.b = ft_atoi(line[2]);
	color = int_to_color(&rgb);
	ft_free_tab(line);
	return (color);
}

int	get_colors(t_data *data, char **file)
{
	int	i;
	int	floor;
	int	ceiling;

	i = 0;
	floor = 0;
	ceiling = 0;
	while (file[i])
	{
		if (ft_strncmp(file[i], "F ", 2) == 0)
		{
			data->f_color = store_color(file[i]);
			floor++;
		}
		if (ft_strncmp(file[i], "C ", 2) == 0)
		{
			data->c_color = store_color(file[i]);
			ceiling++;
		}
		i++;
	}
	if (floor == 0 || ceiling == 0 || data->c_color == -1 || data->f_color == -1)
		return (errormsg("related to Floor or Celing colors", INVALID));
	return (VALID);
}
