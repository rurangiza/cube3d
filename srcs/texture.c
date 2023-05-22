/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:23:06 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/22 09:51:42 by akorompa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	texture_loader(t_data *data)
{
	int fd;

	data->texture.height = 64;
	data->texture.widht = 64;
	fd = open(data->texture.north, O_RDONLY);
	data->texture.tex = mlx_xpm_file_to_image(data->mlx.mlx, data->texture.north, &data->texture.widht, &data->texture.height);
	data->texture.tex_tab = mlx_get_data_addr(data->texture.tex, &data->mlx.bits_per_pixel, &data->mlx.line_lenght, &data->mlx.endian);
}

int	get_texture_color(t_data *data, int x, int y)
{
	int color;

	color = *(int *)(data->texture.tex_tab) + (y * data->mlx.line_lenght) + (x * (data->mlx.bits_per_pixel / 8));
	return (color);
}