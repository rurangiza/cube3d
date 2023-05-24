/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:11:02 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/24 16:53:00 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

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
# define ERROR 1
# define SUCCESS 0
# define TRUE	1
# define FALSE	0
# define MATCH	0

typedef unsigned char	t_number;

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
	void	**tex;
	char	**tex_tab;
	char	**texture;

	void	*test;
	char	*test1;

	int		widht;
	int		height;

	int		tex_color;
	int		tex_x;
	int		tex_y;
	double	wall_x;

}	t_texture;

typedef struct s_ray
{
	double	cam_x;

	double	ray_pos_x;
	double	ray_pos_y;

	double	ray_dir_x;
	double	ray_dir_y;

	double	map_x;
	double	map_y;

	double	side_dist_x;
	double	side_dist_y;

	double	delta_dist_x;
	double	delta_dist_y;

	int		step_x;
	int		step_y;

	int		hit;
	int		side;

	double	wall_dist;
}	t_ray;

typedef struct s_cam
{
	double	pos_x;
	double	pos_y;

	double	dir_x;
	double	dir_y;

	double	plane_x;
	double	plane_y;

	double	speedrotation;
	double	speedwalking;

	bool	move_up;
	bool	move_back;
	bool	move_right;
	bool	move_left;
	bool	turn;
	bool	display;
}	t_cam;

typedef struct s_data
{
	t_mlx		mlx;
	t_texture	texture;
	t_cam		cam;
	t_ray		ray;

	char		*file;
	char		**map;
	int			file_size;

	int			c_color;
	int			f_color;
	int			color;

	int			screen_widht;
	int			screen_height;

	int			x;
	int			y;

	int			line_height;
	int			draw_start;
	int			draw_end;
}	t_data;

//~~~~~~~~~~~~~~~ PARSING ~~~~~~~~~~~~~~~~~~~~~~~//

int		init_data(t_data *data, char *map);
char	**get_map(char **file, t_data *data);
int		ft_strlen_mod(char *str);
int		map_size(char **file, t_data *data);
int		is_map_line(char *line);
int		is_empty_line(char *line);
int		is_map_char(char c);
int		get_colors(t_data *data, char **file);
int		get_texture(t_data *data, char **file);
void	get_player(t_data *data);

//~~~~~~~~~~~~~~~ UTILS ~~~~~~~~~~~~~~~~~~~~~~~//

char	*get_map_line(char *str);
void	ft_free_tab(char **tab);
void	ft_free_all(t_data *data);
char	**reverse(t_data *data);

int		texture_loader(t_data *data);

int		cub3d(t_data *data);
void	raycast_init(t_data *data);
void	raycast_vector_dir(t_data *data);
void	raycast_find_wall(t_data *data);
void	move(t_data *data, t_cam *cam);
void	move_left(t_data *data, t_cam *cam);
void	fill_roof_ceilling(t_data *data);

int		ft_key_press(int keycode, t_data *data);
int		ft_key_release(int keycode, t_data *data);

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);

// NEW
char	**get_file(char *map, t_data *data);
int		file_size(int fd);
char	**fill_file(int size, int fd);

/* ~~~~~~~~~~~~~~~~~ ERROR HANDLING ~~~~~~~~~~~~~~~~ */

int		errormsg(char *msg, int code);
int		maperror(t_number line, t_number col);
int		maperror_v2(char *msg, t_number line, t_number col);
int		ft_isspace(char ch);

/* ~~~~~~~~~~~~~~~~~~~ MAP CHECKING ~~~~~~~~~~~~~~~~~~~~~ */

int		invalid_map(char **map);

int		invalid_characters(char *str, int row);
int		is_surrounded_by_walls(char **map, int current_row);
int		not_surrounded(char **map, int current_row, int i);

int		lastrow(char **map);
int		find_map_start(char **map);
int		isvoid(char ch);
int		calc_linewidth(char **map, int index, int offset);
void	ignore_leading_spaces(char *line, int *i);

#endif