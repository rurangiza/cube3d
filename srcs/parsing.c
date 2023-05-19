/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:10:32 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/17 13:42:11 by akorompa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int	parsing(t_data *data, char *map)
{
	char	**file;

	file = get_file(map, data);
	if (!file)
		return (0);
	data->map = get_map(file, data);
	get_colors(data, file);
	get_texture(data, file);
	data->cam.move_back = false;
	data->cam.move_up = false;
	data->cam.move_left = false;
	data->cam.move_right = false;
	data->cam.turn = false;
	data->cam.display = true;
	data->cam.speedWalking = 0.1;
	data->screen_height = 640;
	data->screen_widht = 800;
	get_player(data);
	return (1);
}