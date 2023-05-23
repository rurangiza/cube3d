/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:23:06 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/23 13:20:48 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_texture(t_data *data)
{
	int	fd;
	int	i;

	i = 0;
	while (data->texture.texture[i])
	{
		fd = open(data->texture.texture[i], O_RDONLY);
		if (fd < 0)
			return (0);
		close(fd);
		i++;
	}
	return (1);
}

int	texture_loader(t_data *data)
{
	int	i;

	data->texture.height = 64;
	data->texture.widht = 64;
	if (!check_texture(data))
		return (0);
	data->texture.tex = malloc(sizeof(void *) * 4);
	if (!data->texture.tex)
		return (0);
	data->texture.tex_tab = malloc(sizeof(char *) * 4);
	if (!data->texture.tex_tab)
		return (0);
	i = -1;
	while (++i < 4)
	{
		data->texture.tex[i] = mlx_xpm_file_to_image(data->mlx.mlx,
				data->texture.texture[i], &data->texture.widht,
				&data->texture.height);
		data->texture.tex_tab[i] = mlx_get_data_addr(data->texture.tex[i],
				&data->mlx.bits_per_pixel, &data->mlx.line_lenght,
				&data->mlx.endian);
	}
	return (1);
}
