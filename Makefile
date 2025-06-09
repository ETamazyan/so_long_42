CC = cc

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

# MacOS
# MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lm

# Linux
MLX_DIR = ./mlx


MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lGL -lGLU


SRCS =  main.c get_next_line.c get_next_line_utils.c parsing.c \
		ft_trim.c trim_start_end.c ft_split.c exit.c \
		validation.c validation_pt2.c flood_fill.c start_game.c \
		press_key.c itoa.c init_map.c

INCS = so_long.h get_next_line.h

NAME = so_long

OBJS_DIR = objects/

OBJS_NAME = $(SRCS:.c=.o)

OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))

all: $(NAME)

$(NAME): $(OBJS) Makefile so_long.h
		$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(OBJS_DIR)%.o: %.c $(HEADERS) Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	@rm -rf $(OBJS_DIR)

.PHONY: all re clean fclean