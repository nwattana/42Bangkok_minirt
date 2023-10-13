NAME=minirt

CC=gcc
CFLAG=-Wall -Wextra -Werror

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

# ---- TEST RT FILES ----
RT_DIR=scene
TEST_RT=$(shell find ./$(RT_DIR) -name "error*" -type f 2> /dev/null)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME) $(MLX_APATH) $(MLX_FLAGS) $(LIBFT_ARC)

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

# ALL BELOW case should exit with error status code != 0
test: $(TEST_RT) all
	@for item in $^ ; do \
	if [ -f $$item ] ; then \
		echo "TEST file $$item \nresult:$(SEP2)" && ./$(NAME) $$item && echo "$(SEP2)$(RED)FAIL$(RESET)" || echo "$(SEP2)$(GREEN)PASS$(RESET)" ; \
		echo "$(SEPERATOR)" ;\
	fi ;\
	done ;\

filename: all
	@echo  "TEST file temp \nresult:$(SEP2)" && ./$(NAME) temp || echo "$(SEP2)->$(GREEN)PASS$(RESET)" || echo "$(SEP2)->$(RED)FAIL$(RESET)"; 
	@echo  "$(SEPERATOR)"
	@echo  "TEST file .rt \nresult:$(SEP2)" && ./$(NAME) .rt || echo "$(SEP2)->$(GREEN)PASS$(RESET)" || echo "$(SEP2)->$(RED)FAIL$(RESET)"; 
	@echo  "$(SEPERATOR)"
	@echo  "TEST file rt \nresult:$(SEP2)" && ./$(NAME) rt || echo "$(SEP2)->$(GREEN)PASS$(RESET)" || echo "$(SEP2)->$(RED)FAIL$(RESET)"; 
	@echo  "$(SEPERATOR)"
	@echo  "TEST file r_t \nresult:$(SEP2)" && ./$(NAME) r_t || echo "$(SEP2)->$(GREEN)PASS$(RESET)" || echo "$(SEP2)->$(RED)FAIL$(RESET)"; 
	@echo  "$(SEPERATOR)"
	@echo  "TEST file plain.txt \nresult:$(SEP2)" && ./$(NAME) plain.txt || echo "$(SEP2)->$(GREEN)PASS$(RESET)" || echo "$(SEP2)->$(RED)FAIL$(RESET)"; 
	@echo  "$(SEPERATOR)"
	@echo  "TEST file not_exist.rt\nresult:$(SEP2)" && ./$(NAME) not_exist.rt || echo "$(SEP2)->$(GREEN)PASS$(RESET)" || echo "$(SEP2)->$(RED)FAIL$(RESET)"; 
	@echo "$(SEPERATOR)"
	@echo  "TEST file 'aa bb' \nresult:$(SEP2)" && ./$(NAME) aa bb || echo "$(SEP2)->$(GREEN)PASS$(RESET)" || echo "$(SEP2)->$(RED)FAIL$(RESET)"; 
	@echo "$(SEPERATOR)"
	@echo  "TEST file \nresult:$(SEP2)" && ./$(NAME)  || echo "$(SEP2)->$(GREEN)PASS$(RESET)" || echo "$(SEP2)->$(RED)FAIL$(RESET)"; 
	@echo "$(SEPERATOR)"


fclean: clean
	make -C zlib fclean
	-@rm -rf $(NAME)

re: fclean all

# COLORS
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
CYAN=\033[0;36m
RESET=\033[0m
SEPERATOR=\n----------------------------------------\n
SEP2=\n~~~~\n
.PHONY: all clean fclean re mlxx libft
