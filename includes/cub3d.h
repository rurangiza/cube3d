/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:11:02 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/11 13:22:53 by akorompa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

# define BUFFER_SIZE 5

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	
}	t_mlx;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
}	t_texture;

typedef struct s_raycaster
{
	
}	t_raycaster;

typedef struct s_data
{
	t_mlx		mlx;
	t_texture	texture;
	t_raycaster	ray;
	
	char	*file;
	char	**map;
	int		file_size;
	
	int		c_color;	//ceilling
	int		f_color;	//floor
	
}	t_data;


//~~~~~~~~~~~~~~~ PARSING ~~~~~~~~~~~~~~~~~~~~~~~//

int		parsing(t_data *data, char *map);
char	**get_map(char **file, t_data *data);
int	ft_strlen_mod(char *str);
int	map_size(char **file, t_data *data);
int	is_map_line(char *line);
int	is_empty_line(char *line);
int	is_map_char(char c);
int	get_colors(t_data *data, char **file);
int	get_texture(t_data *data, char **file);
void	init_data(t_data *data);


//~~~~~~~~~~~~~~~ UTILS ~~~~~~~~~~~~~~~~~~~~~~~//

char	*get_map_line(char *str);
void	ft_free_tab(char **tab);

#endif