/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:11:02 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/23 11:15:10 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../mlx/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

# define CGRAY     "\x1b[30m"
# define CRED     "\x1b[31m"
# define CGREEN   "\x1b[32m"
# define CYELLOW  "\x1b[33m"
# define CBLUE    "\x1b[34m"
# define CMAGENTA "\x1b[35m"
# define CCYAN    "\x1b[36m"
# define CWHITE    "\x1b[37m"
# define CBOLD   "\x1b[1m"
# define CRESET   "\x1b[0m"

# define BUFFER_SIZE 5
# define INVALID 1
# define VALID 0

typedef unsigned char t_number;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	
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

	int widht;
	int	height;
	void	*tex;
	char	*tex_tab;
	int	tex_color;

	int tex_x;
	int tex_y;
	double wall_x;
}	t_texture;

typedef struct s_ray
{
	double cam_x;
	
	double ray_pos_x;
	double ray_pos_y;
	
	double ray_dir_x;
	double ray_dir_y;

	double map_x;
	double map_y;

	double side_dist_x;
	double side_dist_y;
	
	double delta_dist_x;
	double delta_dist_y;
	
	int step_x;
	int step_y;
	
	int hit;
	int side;

	double wall_dist;
	
}	t_ray;

typedef struct s_cam
{
	double	pos_X;
	double	pos_Y;

	double dir_X;
	double dir_Y;
	
	double plane_X;
	double plane_Y;
	
	double	speedRotation;
	double	speedWalking;

	bool	move_up;
	bool move_back;
	bool move_right;
	bool move_left;
	bool turn;
	bool display;
}	t_cam;

typedef struct s_data
{
	t_mlx		mlx;
	t_texture	texture;
	t_cam		cam;
	t_ray		ray;
	
	char	*file;
	char	**map;
	int		file_size;
	
	int		c_color;	//ceilling
	int		f_color;	//floor
	int		color;
	
	int		screen_widht;
	int		screen_height;
	
	int x;
	int y;

	int	line_height;
	int	draw_start;
	int	draw_end;
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
void	get_player(t_data *data);


//~~~~~~~~~~~~~~~ UTILS ~~~~~~~~~~~~~~~~~~~~~~~//

char	*get_map_line(char *str);
void	ft_free_tab(char **tab);

void	texture_loader(t_data *data);
int	get_texture_color(t_data *data, int x, int y);

int	cub3d(t_data *data);

int	ft_key_press(int keycode, t_data *data);
int ft_key_release(int keycode, t_data *data);

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);

// NEW
int	errormsg(char *msg, int code);

#endif