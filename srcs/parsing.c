/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:10:32 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/23 13:49:02 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#define ERROR 1
#define SUCCESS 0
#define TRUE	1
#define FALSE	0
#define MATCH	0

int	errormsg(char *msg, int code)
{
	printf(CRED"Error\n"CRESET);
	printf("%s\n", msg);
	return (code);
}

int	maperror(char *msg, t_number code, t_number line, t_number col)
{
	printf(CRED"Error: "CRESET);
	printf("%s at ln %d, col %d\n", msg, line, col);
	return (code);
}

int	file_size(int fd)
{
	char	buffer[5000000];
	int		size;
	int		byte_read;
	int		i;
	
	size = 1;
	i = 0;
	byte_read = read(fd, buffer, 5000000);
	if (byte_read <= 0)
	{
		printf("Empty file\n");
		return(0);
	}
	buffer[byte_read + 1] = '\0';
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			size++;
		i++;
	}
	return (size);
}

char	**fill_file(int size, int fd)
{
	char	**file;
	int		i;

	file = malloc(sizeof(char *) * (size + 1));
	if (!file)
		return (NULL);
	i = 0;
	while (i < size)
	{
		file[i] = get_next_line(fd);
		if (!file[i] && i < size)
			return (NULL);
		i++;
	}
	file[i] = 0;
	return (file);
}

char	**get_file(char *map, t_data *data)
{
	char	**file;
	int		fd;

	file = NULL;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	data->file_size = file_size(fd);
	close(fd);
	fd = open(map, O_RDONLY);
	file = fill_file(data->file_size, fd);
	if (!file)
		return (NULL);
	return (file);
}

int	ft_isspace(char ch)
{
	if ((ch >= 9 && ch <= 13) || ch == 32)
		return (1);
	return (0);
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
// Map is composed of only 6 possible characters
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

int	find_last_row(char **map)
{
	int i = 0;
	while (map[i])
		i++;
	return (i);
}


/*
first index must be '1'
last index must be '1'
Pseudocode:
	- calculate maximum width of the map {map_width, prev_start, prev_end}
	- initialize prev_start = 0 : anything before start must be '1' (wall)
	- initialize prev_end = map_width
	- traverse each line of the map
		- ignore leading spaces
		- calculate block_width (until `\0` or `space`)
		- check character until reach `\0` or `space`
			- if index < prev_start -> must be a wall
			- if index > prev_end -> must be a wall
		- ignore tailing spaces, report detached walls
*/
int not_surrounded_by_walls(char **map, int current_line, int __unused map_width, int *prev_start, int *prev_end)
{
	char *line = map[current_line];
	//  ignore leading spaces
	int i = 0;
	while (ft_isspace(line[i]))
		i++;
	int block_start = i;
	
	// 	calculate block_width (until `\0` or `space`)
	int block_end = i;
	while (line[block_end+1] && !ft_isspace(line[block_end+1]))
		block_end++;
	
	// 	check character until reach `\0` or `space`
	while (line[i] && !ft_isspace(line[i]))
	{
		if (line[i] != '1')
		{
			// handle edges (first and last)
			if (i == block_start || i == block_end)
				return (errormsg("no wall at: block start or end", TRUE));

			// handle 1st and last line
			else if (current_line == 0 || !map[current_line + 1])
				return (errormsg("no wall at: first or last row", TRUE));

			// handle previous narrow blocks
			else if (i < *prev_start || i > *prev_end)
				return (errormsg("no wall compared to prev_start", TRUE));

			// handdle next narrow blocks
			if (map[current_line + 1]) {
				int next_start = 0;
				while (map[current_line+1][next_start] && ft_isspace(map[current_line+1][next_start]))
					next_start++;
				if (i <= next_start)
					return (errormsg("map: narrow block: next_start", TRUE));

				int next_end = next_start;
				while (map[current_line+1][next_end] && !ft_isspace(map[current_line+1][next_end]))
					next_end++;
				//printf("> current: %c\n", line[i]);
				//printf("|.... nxt_End: %c\n", map[current_line+1][next_end-1]);
				if (i >= next_end)
				{
					//printf("ln %d, col %d\n", current_line+1, i);
					return (errormsg("map: narrow block: next_end", TRUE));
				}
			}
		}
		i++;
	}

	// 	ignore tailing spaces, report detached walls
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (errormsg("map: detached block", TRUE));
		i++;
	}
	*prev_start = block_start;
	*prev_end = block_end;
	return (FALSE);
}

int calc_width(char **map)
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

int	invalid_map(char **map)
{
	printf("---> parsing map\n");

	printf("Before: %s\n", map[0]);
	
	int	mapstart = find_map_start(map);
	if (mapstart == -1)
		return (errormsg("map: can't find map", INVALID));
	map = &map[mapstart];

	printf("After: %s\n", map[0]);

	// Checking
	int i = 0;
	int map_width = calc_width(map);
	int prev_start = 0;
	int prev_end = map_width;

	int __unused last_row = find_last_row(map);
	
	while (map[i])
	{
		if (invalid_characters(map[i], i))
			return (INVALID);
		if (not_surrounded_by_walls(map, i, map_width, &prev_start, &prev_end))
			return (INVALID);
		i++;
	}
	return (VALID);
}

int	parsing(t_data *data, char *map)
{
	char	**file;

	file = get_file(map, data);
	if (!file)
		return (0);
	if (invalid_map(file))
		return (errormsg("Invalid map", 0));
	data->map = get_map(file, data);
	if (get_colors(data, file))
		return (0);
	if (get_texture(data, file))
		return (0);
	printf(CGREEN"✓ Valid map\n"CRESET);
	data->cam.move_back = false;
	data->cam.move_up = false;
	data->cam.move_left = false;
	data->cam.move_right = false;
	data->cam.turn = false;
	data->cam.display = true;
	data->cam.speedwalking = 0.05;
	data->screen_height = 640;
	data->screen_widht = 800;
	get_player(data);
	return (1);
}