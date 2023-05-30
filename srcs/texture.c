/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:23:06 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/25 14:58:35 by akorompa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_xpm2(char *texture)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	i = ft_strlen(texture) - 1;
	while (texture[i--] == 'm')
	{
		if (texture[i--] == 'p')
		{
			if (texture[i--] == 'x')
			{
				if (texture[i--] == '.')
					return (1);
			}
		}
	}
	return (0);
}

int	check_xpm(t_data *data)
{
	int		i;

	i = 0;
	while (data->texture.texture[i])
	{
		if (!check_xpm2(data->texture.texture[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_texture(t_data *data)
{
	int	fd;
	int	i;

	i = 0;
	if (!check_xpm(data))
		return (0);
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
