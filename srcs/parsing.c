/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:10:32 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/23 12:01:10 by akorompa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	errormsg(char *type, int code)
{
	printf("Error: ");
	printf("%s\n",type);
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

int	is_start_of_map(char **map, int i)
{
	if (!ft_strncmp("01", map[i], 2) || !ft_strncmp("10", map[i], 2) || !ft_strncmp("11", map[i], 2))
		return (1);
	return (0);
			
}

int	invalid_characters(char *str)
{
	printf("---> Checking: invalid characters\n");
	int i = 0;
	while (str[i])
	{
		if (str[i] != '0'
			&& str[i] != '1'
			&& str[i] != 'N'
			&& str[i] != 'S'
			&& str[i] != 'E'
			&& str[i] != 'W'
			&& str[i] != ' ')
		{
			printf("Error: invalid character (%c) at col [%d]\n", str[i], i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	find_last_row(char **map, int i)
{
	while (map[i])
		i++;
	return (i);
}

#define ERROR 1
#define SUCCESS 0

int	not_surrounded_by_walls(char *row, int i, int first_row_index, int last_row_index)
{
	int k = 0;
	
	printf("---> Checking: surrounded by walls\n");
	while (row[k] && row[k] == ' ')
		k++;

	if (i == first_row_index || i == last_row_index)
	{
		while (row[k]) {
			if (row[k] != '1')
				return (errormsg("not surrounded by walls", ERROR));
		}
	}
	else
	{
		if (row[k] != '1')
			return (errormsg("not surrounded by walls", ERROR));
		while (row[k])
			k++;
		if (row[k - 1] != '1')
			return (errormsg("not surrounded by walls", ERROR));
	}

	while (row[k])
	{
		if (row[k] != ' ')
			return (errormsg("not surrounded by walls", ERROR));
		k++;
	}

	return (SUCCESS);

	// if ((row[0] && row[0] == '1') && (row[last] && row[last] == '1'))
	// return (1);
	
}

int	invalid_map(char **map)
{
	// Map is composed of only 6 possible characters
	// 0 1 N S E W
	printf("---> Checking if map is valid\n");
	int i = 0, first_row, last_row;
	while (map[i])
	{
		// Find start of map
		if (is_start_of_map(map, i))
		{
			printf("---> Found start of map\n");
			first_row = i;
			last_row = find_last_row(map, i);
			// Traverse it
			while (map[i])
			{
				if (invalid_characters(map[i])
					|| not_surrounded_by_walls(map[i], i, first_row, last_row))
					return (1);
				// check for valid characters
				i++;
			}
			return (0);
		}
		i++;
	}
	return (0);
}

int	parsing(t_data *data, char *map)
{
	char	**file;

	file = get_file(map, data);
	if (!file)
		return (0);
	// if (invalid_map(file))
	// 	return (errormsg("Invalid map", 0));
	// for (int i = 0; file[i] != NULL; i++)
	// 	printf("%s", file[i]);
	
	//exit(0);

	data->map = get_map(file, data);
	get_colors(data, file);
	get_texture(data, file);
	data->cam.move_back = false;
	data->cam.move_up = false;
	data->cam.move_left = false;
	data->cam.move_right = false;
	data->cam.turn = false;
	data->cam.display = true;
	data->cam.speedwalking = 0.1;
	data->screen_height = 640;
	data->screen_widht = 800;
	get_player(data);
	return (1);
}