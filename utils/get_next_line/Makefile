# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 13:40:46 by creyt             #+#    #+#              #
#    Updated: 2023/01/14 14:03:18 by vferraro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wall -Wextra
NAME = libgnl.a
AR = @ar rcs
SRC =	get_next_line.c \
		get_next_line_utils.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
	@${AR} ${NAME} ${OBJ}

clean:
	@rm -rf ${OBJ}

fclean: clean
	@rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean
