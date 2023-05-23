/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:43:55 by lupin             #+#    #+#             */
/*   Updated: 2023/05/23 14:59:55 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	invalid_map(char **map)
{
	int	index;
	int	mapstart;
	int	prev_line_start;
	int prev_line_end;

	mapstart = find_map_start(map);
	if (mapstart == -1)
		return (errormsg("map: can't find map", INVALID));
	map = &map[mapstart];
	prev_line_start = 0;
	prev_line_end = calc_maxwidth(map);
	index = 0;
	while (map[index])
	{
		if (invalid_characters(map[index], index))
			return (TRUE);
		if (not_surrounded_by_walls(map, index, &prev_line_start, &prev_line_end))
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

// 0 1 N S E W
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

int not_surrounded_by_walls(char **map, int current_line, int *prev_start, int *prev_end)
{
	char *line;
    int i;
    int block_start;
    int block_end;
    
    line = map[current_line];
	i = 0;
    block_start = ignore_leading_spaces(line, i);
	block_end = block_start;
	while (line[block_end+1] && !ft_isspace(line[block_end+1]))
		block_end++;	
	while (line[i] && !ft_isspace(line[i]))
	{
		if (line[i] != '1')
		{
			if (i == block_start || i == block_end) // handle edges (first and last)
				return (errormsg("no wall at: block start or end", TRUE));
			else if (current_line == 0 || !map[current_line + 1]) // handle 1st and last line
				return (errormsg("no wall at: first or last row", TRUE));
			else if (i < *prev_start || i > *prev_end) // handle previous narrow blocks
				return (errormsg("no wall compared to prev_start", TRUE));
            if (next_line_missmatch())
                return (errormsg("map: narrow block: next_start", TRUE));
		}
		i++;
	}
    if (ignore_tailing_spaces())
        return (errormsg("map: detached block", TRUE));
	*prev_start = block_start;
	*prev_end = block_end;
	return (FALSE);
}

int ignore_leading_spaces(char *line, int *i)
{
    while (ft_isspace(line[*i]))
        *i += 1;
}

int next_line_missmatch(char **map, int current_line, int i)
{
    if (map[current_line + 1])
    { 
        int next_start = 0;
        while (map[current_line+1][next_start]
            && ft_isspace(map[current_line+1][next_start]))
            next_start++;
        if (i <= next_start)
            return (TRUE);
        int next_end = next_start;
        while (map[current_line+1][next_end]
            && !ft_isspace(map[current_line+1][next_end]))
            next_end++;
        if (i >= next_end)
            return (TRUE);
    }
    return (FALSE);
}

int ignore_tailing_spcaes(char *line, int *i)
{
    while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (1);
		i++;
	}
    return (0);
}




