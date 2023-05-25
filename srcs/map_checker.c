/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:43:55 by lupin             #+#    #+#             */
/*   Updated: 2023/05/25 12:41:12 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	invalid_map(char **map)
{
	int	index;
	int	mapstart;
	int	foundplayer;

	mapstart = find_map_start(map);
	if (mapstart == -1)
		return (errormsg("map: can't find map", TRUE));
	map = &map[mapstart];
	index = 0;
	foundplayer = FALSE;
	while (map[index])
	{
		if (invalid_characters(map[index], index, &foundplayer))
			return (TRUE);
		if (!is_surrounded_by_walls(map, index))
			return (TRUE);
		index++;
	}
	if (foundplayer == 0)
		return (errormsg("\x1b[1mmap:\033[0m no player found", TRUE));
	else if (foundplayer > 1)
		return (errormsg("\x1b[1mmap:\033[m too many players", TRUE));
	return (FALSE);
}

int	find_map_start(char **map)
{
	int	row;
	int	col;

	if (!map)
		return (-1);
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col] && ft_isspace(map[row][col]))
			col++;
		if (ft_strlen(map[row] + col) >= 2
			&& ((map[row][col] == '0' && map[row][col + 1] == '1')
			|| (map[row][col] == '0' && map[row][col + 1] == '0')
			|| (map[row][col] == '1' && map[row][col + 1] == '1')
			|| (map[row][col] == '1' && map[row][col + 1] == '1')))
			return (row);
		row++;
	}
	return (-1);
}

int	is_surrounded_by_walls(char **map, int current_row)
{
	int	i;

	i = 0;
	while (map[current_row][i] && map[current_row][i] != '\n')
	{
		while (ft_isspace(map[current_row][i]))
			i++;
		if (i > calc_linewidth(map, current_row, 0))
			return (FALSE);
		if (map[current_row][i] != '1' && not_surrounded(map, current_row, i))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	not_surrounded(char **map, int current_row, int i)
{
	if (current_row == 0 || current_row == lastrow(map))
		return (maperror(current_row, i));
	else if (i == 0)
		return (maperror(current_row, i));
	else
	{
		if (calc_linewidth(map, current_row, -1) < i
			|| (calc_linewidth(map, current_row, -1) >= i
				&& isvoid(map[current_row - 1][i])))
			return (maperror(current_row, i));
		else if (calc_linewidth(map, current_row, +1) < i
			|| (calc_linewidth(map, current_row, +1) >= i
				&& isvoid(map[current_row + 1][i])))
			return (maperror(current_row, i));
		else if (map[current_row][i + 1] && isvoid(map[current_row][i + 1]))
			return (maperror(current_row, i));
		else if (map[current_row][i - 1] && isvoid(map[current_row][i - 1]))
			return (maperror(current_row, i));
	}
	return (FALSE);
}
