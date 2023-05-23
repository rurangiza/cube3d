/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:14:53 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/23 11:20:35 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	int_to_color(t_rgb *rgb)
{
	int	color;

	color = (rgb->r << 16) + (rgb->g << 8) + rgb->b;
	return (color);
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
	ft_free_tab(tmp);
	rgb.r = ft_atoi(line[0]);
	rgb.g = ft_atoi(line[1]);
	rgb.b = ft_atoi(line[2]);
	color = int_to_color(&rgb);
	ft_free_tab(line);
	return(color);
}

int	get_colors(t_data *data, char **file)
{
	int	i;
	int	floor = 0, ceiling = 0;
	
	i = 0;
	while(file[i])
	{
		if (ft_strncmp(file[i], "F", 1) == 0) {
			data->f_color = store_color(file[i]);
			floor++;
		}
		if (ft_strncmp(file[i], "C", 1) == 0) {
			data->c_color = store_color(file[i]);
			ceiling++;
		}
		i++;
	}
	if (floor == 0 || ceiling == 0)
		return (errormsg("missing Floor/Celing colors", INVALID));
	return (VALID);
}