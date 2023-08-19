# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsomrat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 22:36:19 by lsomrat           #+#    #+#              #
#    Updated: 2022/03/13 11:50:30 by lsomrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS	= -Wall -Wextra -Werror
NAME	= libft.a
SRCS	= ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_strlen.c \
	  ft_strchr.c \
	  ft_strncmp.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memmove.c \
	  ft_memcpy.c \
	  ft_strlcpy.c \
	  ft_strlcat.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_atoi.c \
	  ft_calloc.c \
	  ft_strdup.c \
	  ft_substr.c \
	  ft_putstr_fd.c \
	  ft_putchar_fd.c \
	  ft_putnbr_fd.c \
	  ft_putendl_fd.c \
	  ft_itoa.c \
	  ft_split.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_striteri.c \
	  ft_strmapi.c

SRCS_B	= ft_lstnew.c \
	  ft_lstadd_front.c \
	  ft_lstlast.c \
	  ft_lstsize.c \
	  ft_lstadd_back.c \
	  ft_lstdelone.c \
	  ft_lstclear.c \
	  ft_lstiter.c \
	  ft_lstmap.c 

OBJS	= ${SRCS:.c=.o}

OBJS_B    = ${SRCS_B:.c=.o}

%.o: %.c
	gcc ${FLAGS} -c $< -o $@
	
$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

bonus: ${OBJS_B}
	ar rcs ${NAME} ${OBJS_B}

norminette:
	norminette ${SRCS} ${SRCS_B}

all: ${NAME}

clean:
	rm -f ${OBJS} ${OBJS_B}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: norminette all
