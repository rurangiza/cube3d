/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:11:23 by akorompa          #+#    #+#             */
/*   Updated: 2023/04/28 16:59:48 by akorompa         ###   ########.fr       */
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
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx, 1280, 1024, "cub3d");
	if (!data->mlx.mlx_win)
		return (0);
	return (1);
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
	cub3d(data);
	return (0);
}
