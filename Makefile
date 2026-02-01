CC = cc

CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -Ilibft

MLXF = -Lminilibx-linux -Llibft -lmlx -lXext -lX11 -lm 

NAME = fractol

SRCS = fractol.c fractals.c hooks.c parsing.c utils.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

MLX = minilibx-linux/libmlx.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXF) -o $(NAME)

$(LIBFT):
	make -C libft

$(MLX):
	make -C minilibx-linux

clean:
	rm -rf $(OBJS)
	make clean -C libft
	make clean -C minilibx-linux

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re