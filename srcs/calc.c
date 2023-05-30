/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:36:41 by lupin             #+#    #+#             */
/*   Updated: 2023/05/30 11:28:19 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	calc_linewidth(char **map, int index, int offset)
{
	int	width;

	width = 0;
	if (!map[index + offset])
		return (width);
	while (map[index + offset][width] && map[index + offset][width] != '\n')
		width++;
	return (width - 1);
}

int	lastrow(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i - 1);
}
