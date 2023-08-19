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
	MLX_TARGET=$(MLX_NAME)
endif
# mac
ifeq ("$(shell uname)","Darwin")
	MLX_FLAGS=-framework OpenGL -framework AppKit
	MLX_NAME=minilibx-opengl
	MLX_ZIP=$(MLX_NAME).tgz
	MLX_TARGET=minilibx_opengl_20191021
endif
MLX_APATH=$(MLX_DIR)/libmlx.a

# ----------- Libft ----------
LIBFT_ARC=./lib/libft.a

# TODO move .o to obj folder
%.o: %.c
	gcc -c $< -o $@ $(MLX_FLAGS)

all: $(NAME)

$(NAME): mlxx libft $(OBJS) $(MLX) 
	gcc -Wall -Wextra -Werror $(OBJS) -o $(NAME) $(MLX_APATH) $(MLX_FLAGS) $(LIBFT_ARC)

# Build minilibx
mlxx:
	-@rm -rf $(MLX_DIR) 2> /dev/null
	-@cd ziped && tar -xpf $(MLX_ZIP) -C ../ 2> /dev/null
	-@mv $(MLX_TARGET) mlx 2> /dev/null
	-@make -C mlx > /dev/null 2> /dev/null

libft:
	@make -C lib bonus  > /dev/null


clean:
	-@rm -f $(OBJS) 
	-@[ -d "mlx" ] && cd mlx && make clean > /dev/null && echo "Clean MLX OBJ" || echo "mlx not found"

fclean: clean
	-@rm -rf $(MLX_DIR) 
	-@rm -rf $(NAME)  
	-@make -C lib fclean  > /dev/null 2> /dev/null

re: fclean all

.PHONY: all clean fclean re mlxx libft
