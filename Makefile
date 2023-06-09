# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 13:24:37 by lupin             #+#    #+#              #
#    Updated: 2023/06/08 15:37:32 by arurangi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= 	srcs/main.c \
					srcs/cub3d.c \
					srcs/events.c \
					srcs/get_map.c \
					srcs/get_map_utils.c \
					srcs/get_colors.c \
					srcs/get_texture.c \
					srcs/player.c \
					srcs/utils.c \
					srcs/texture.c \
					srcs/move.c \
					srcs/cub3d_utils.c \
					srcs/move_utils.c \
					srcs/init.c \
					srcs/map_checker.c \
					srcs/checker.c \
					srcs/error_handling.c \
					srcs/calc.c \
					gnl/get_next_line.c \
					gnl/get_next_line_utils.c \

INCLUDES		= includes/cub3d.h

OBJS	= ${SRCS:.c=.o}

NAME 	= cub3D

LIBFT = libft

CC			= gcc $(CCFLAGS)
CCFLAGS 	= -Wall -Wextra -Werror -fsanitize=address -g
MLX		= ./mlx
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./mlx
MLX_LNK	= -L ./mlx -l mlx -framework OpenGL -framework AppKit
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft
RM = rm -f

%.o:srcs%.c
	$(CC) -o $@ -c $<

all:		$(FT_LIB) $(MLX_LIB) ${NAME}

$(FT_LIB):
	make -C $(FT)
$(MLX_LIB):
	make -C $(MLX)



${NAME}:	${OBJS}
			$(CC) $(OBJS) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)


bonus:		$(FT_LIB) $(BOBJS)
			$(CC) $(BOBJS) $(MLX_LNK) $(FT_LNK) -lm -o $(BNAME)

clean:
				rm -f ${OBJS} $(BOBJS)
				make clean -C $(LIBFT)
				make -C $(MLX) clean

fclean: 	clean
				rm -f ${NAME} $(BNAME)
				make fclean -C $(LIBFT)

re:				fclean all

.PHONY:			all clean fclean re