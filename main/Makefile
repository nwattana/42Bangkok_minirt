NAME=minirt

# ---------- DIRCTORY ----------
SRCS_DIR=srcs
ORBJ_DIR=objs

# ----------- SOURCES ----------
# TODO srcs = all .c in srcs folder
SRCS=srcs/main.c
OBJS=$(SRCS:.c=.o)

# ----------- MINILIBX ----------
MLX_DIR=mlx
# linux
ifeq ("$(shell uname)","Linux")
	MLX_FLAGS= -lXext -lX11 -lm
	MLX_NAME=minilibx-linux
	MLX_ZIP=$(MLX_NAME).tgz
endif
# mac
ifeq ("$(shell uname)","Darwin")
	MLX_FLAGS= -lmlx -framework OpenGL -framework AppKit
	MLX_NAME=minilibx-opengl
	MLX_ZIP=$(MLX_NAME).tgz
endif
MLX_APATH=$(MLX_DIR)/libmlx.a

# TODO move .o to obj folder
%.o: %.c
	gcc -c $< -o $@ $(MLX_FLAGS)

all: $(NAME)

$(NAME): mlxx $(OBJS) $(MLX) 
	gcc -Wall -Wextra -Werror $(OBJS) -o $(NAME) $(MLX_APATH) $(MLX_FLAGS)

# Build minilibx
mlxx:
	-@rm -rf $(MLX_DIR) 2> /dev/null
	-@cd ziped && tar -xpf $(MLX_ZIP) -C ../ 2> /dev/null
	-@mv $(MLX_NAME) mlx 2> /dev/null
	-@make -C mlx > /dev/null 2> /dev/null

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(MLX_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re mlxx