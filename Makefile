SRCS			= 	srcs/main.c \
					srcs/parsing.c \
					srcs/get_map.c \
					srcs/get_map_utils.c \
					srcs/get_colors.c \
					srcs/get_texture.c \
					srcs/utils.c \
					srcs/init_data.c \
					gnl/get_next_line.c \
					gnl/get_next_line_utils.c \

INCLUDES		= includes/cub3d.h

OBJS	= ${SRCS:.c=.o}

NAME 	= cub3d

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