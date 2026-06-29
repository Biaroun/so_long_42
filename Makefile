NAME = so_long

LIB_NAME = so_long.a

CC = gcc

FLAG = -Wall -Wextra -Werror -g

SRC = so_long.c error.c move.c parsing.c player_down.c player_up.c player_left.c player_right.c map_aff.c is_solvable.c

AR = ar -rcs

OBJ = $(addprefix src/,$(SRC:.c=.o))

# Detect OS
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	MLX_DIR = mlx
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
	MLX_INC = -I$(MLX_DIR)
else
	# macOS
	MLX_DIR = mlx
	ifeq ($(wildcard $(MLX_DIR)),)
		MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
		MLX_INC = -Imlx
	else
		MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
		MLX_INC = -I$(MLX_DIR)
	endif
endif

src/%.o: src/%.c
		$(CC) $(FLAG) $(MLX_INC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	@if [ -d "$(MLX_DIR)" ]; then \
		make -C $(MLX_DIR); \
	fi
	mv libft/libft.a src/$(LIB_NAME)
	$(AR) src/$(LIB_NAME) $(OBJ)
	$(CC) src/$(LIB_NAME) $(MLX_FLAGS) -o $(NAME)

clean:
	make -C libft/ clean
	@if [ -d "$(MLX_DIR)" ]; then \
		make -C $(MLX_DIR) clean; \
	fi
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean	
	rm -f $(NAME) src/$(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re
