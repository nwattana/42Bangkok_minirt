NAME=minirt

# ---------- DIRCTORY ----------
SRCS_DIR=srcs
ORBJ_DIR=objs

# ----------- SOURCES ----------
SRCS=$(shell find ./$(SRCS_DIR) -name "*.c" -type f 2> /dev/null)
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
LIBFT_DIR=zlib
LIBFT_ARC=./$(LIBFT_DIR)/libft.a
LIBFT=./$(LIBFT_DIR)/libft.a

%.o: %.c
	gcc -c $< -o $@ $(MLX_FLAGS)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	gcc -Wall -Wextra -Werror $(OBJS) -o $(NAME) $(MLX_APATH) $(MLX_FLAGS) $(LIBFT_ARC)

$(LIBFT):
	make -C zlib bonus

$(MLX_APATH): mlxx
	@echo $(MLX_APATH)

# Build minilibx
mlxx:
	-@rm -rf $(MLX_DIR) 2> /dev/null
	-@cd ziped && tar -xpf $(MLX_ZIP) -C ../ 2> /dev/null
	-@mv $(MLX_TARGET) mlx 2> /dev/null
	@make -C mlx > /dev/null 2> /dev/null

libft:
	@make -C $(LIBFT_DIR) bonus  > /dev/null


clean:
	-@rm -f $(OBJS)
	-@rm -rf $(ORBJ_DIR)/*

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) scene/test.rt


fclean: clean
	make -C zlib fclean
	-@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re mlxx libft
