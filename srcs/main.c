/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:11:23 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/16 16:19:13 by akorompa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_mlx(t_data *data, char *map)
{
	int	i;
	
	data->file = NULL;
	i = ft_strlen(map) - 1;
	while (map[i--] == 'b')
	{
		if (map[i--] == 'u')
		{
			if (map[i--] == 'c')
			{
				if (map[i--] == '.')
					data->file = map;
			}
		}
	}
	if (!data->file)
	{
		printf("Map must end with .cub\n");
		return(0);
	}
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		return (0);
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx, 800, 640, "cub3d");
	if (!data->mlx.mlx_win)
		return (0);
	return (1);
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_create_img(t_data *data)
{
	data->mlx.img = mlx_new_image(data->mlx.mlx, 800, 640);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel, &data->mlx.line_lenght, &data->mlx.endian);
}

int	main(int ac, char **av)
{
	t_data data;

	if (ac != 2)
		return (printf("Usage: ./cub3d 'map.cub'.\n"));
	if (!init_mlx(&data, av[1]))
		return (printf("Error in init.\n"));
	if (!parsing(&data, av[1]))
		return(printf("Error in parsing\n"));
	ft_create_img(&data);
	mlx_hook(data.mlx.mlx_win, 2, 1L << 0, ft_key_press, &data);
	mlx_hook(data.mlx.mlx_win, 3, 1L << 1, ft_key_release, &data);
	mlx_loop_hook(data.mlx.mlx, cub3d, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
