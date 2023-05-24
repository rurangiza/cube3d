/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:43:55 by lupin             #+#    #+#             */
/*   Updated: 2023/05/24 16:07:06 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	lastrow(char **map);
int	find_map_start(char **map);
int calc_maxwidth(char **map);
int	invalid_characters(char *str, int row);
int isvoid(char ch);
int calc_linewidth(char **map, int index, int offset);
void ignore_leading_spaces(char *line, int *i);
int not_surrounded_by_walls(char **map, int current_row);

int	invalid_map(char **map)
{
	int	index;
	int	mapstart;

	mapstart = find_map_start(map);
	if (mapstart == -1)
		return (errormsg("map: can't find map", INVALID));
	map = &map[mapstart];
	index = 0;
	while (map[index])
	{
		if (invalid_characters(map[index], index))
			return (TRUE);
		if (not_surrounded_by_walls(map, index))
			return (TRUE);
		index++;
	}
	return (FALSE);
}

int	find_map_start(char **map)
{
	int	row = 0;

	if (!map)
		return (-1);
	while (map[row])
	{
		int col = 0;
		while (map[row][col] && ft_isspace(map[row][col]))
			col++;
		if (ft_strlen(map[row]+col) >= 2
			&& ((map[row][col] == '0' && map[row][col+1] == '1')
			|| (map[row][col] == '0' && map[row][col+1] == '0')
			|| (map[row][col] == '1' && map[row][col+1] == '1')
			|| (map[row][col] == '1' && map[row][col+1] == '1')))
			return (row);
		row++;
	}
	return (-1);
}

int calc_maxwidth(char **map)
{
	int	max_width;
	int	current_width;
	int	index;

	max_width = 0;
	index = 0;
	while (map[index]) {
		current_width = ft_strlen(map[index]);
		if (current_width > max_width)
			max_width = current_width;
		index++;
	}
	return (max_width - 1);
}

int	invalid_characters(char *str, int row)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] != '0'
			&& str[i] != '1'
			&& str[i] != 'N'
			&& str[i] != 'S'
			&& str[i] != 'E'
			&& str[i] != 'W'
			&& !ft_isspace(str[i]))
		{
			printf("line = %s\n", str);
			printf("%sError:%s invalid character %s(%c)%s at %s(ln %d, col %d)%s\n",
				CRED, CRESET, CBLUE, str[i], CRESET, CBLUE, row+1, i, CRESET);
			return (1);
		}
		i++;
	}
	return (0);
}

int isvoid(char ch)
{
    if (ft_isspace(ch) || ch == '\n')
        return (TRUE);
    return (FALSE);   
}

int calc_linewidth(char **map, int index, int offset) {
	int width;

	width = 0;
	if (!map[index + offset])
		return (width);
	while (map[index + offset][width] && map[index + offset][width] != '\n')
		width++;
	return (width - 1);
}

void ignore_leading_spaces(char *line, int *i) {
    while (ft_isspace(line[*i]))
        *i += 1;
}

int	lastrow(char **map) {
	int i = 0;
	while (map[i])
		i++;
	return (i - 1);
}

int not_surrounded_by_walls(char **map, int current_row)
{
    int i;

	i = 0;
    while (map[current_row][i] && map[current_row][i] != '\n')
	{
        ignore_leading_spaces(map[current_row], &i);
		if (i > calc_linewidth(map, current_row, 0))
			return (FALSE);
        if (map[current_row][i] != '1')
		{
            if (current_row == 0 || current_row == lastrow(map))
                return (maperror(current_row, i));
			else if (i == 0)
				return (maperror(current_row, i));
            else
            {
                if (calc_linewidth(map, current_row, -1) < i
					|| (calc_linewidth(map, current_row, -1) >= i && isvoid(map[current_row-1][i])))
                    return (maperror(current_row, i));
                else if (calc_linewidth(map, current_row, +1) < i
					|| (calc_linewidth(map, current_row, +1) >= i && isvoid(map[current_row+1][i])))
                    return (maperror(current_row, i));
                else if (map[current_row][i + 1] && isvoid(map[current_row][i + 1]))
					return (maperror(current_row, i));
                else if (map[current_row][i - 1] && isvoid(map[current_row][i - 1]))
                    return (maperror(current_row, i));
            }
        }
        i++;
    }
	return (FALSE);
}
