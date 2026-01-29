CC = cc

CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux

MLXF = -Lminilibx-linux -lmlx -lXext -lX11 -lm

NAME = fractol

SRCS = fractol.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

MLX = minilibx-linux/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXF) -o $(NAME)

$(LIBFT):
	make -C libft

$(MLX):
	make -C minilibx-linux

clean:
	rm -rf $(OBJS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re