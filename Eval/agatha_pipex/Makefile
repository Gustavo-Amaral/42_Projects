# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 20:22:01 by agathabarro       #+#    #+#              #
#    Updated: 2023/08/19 17:19:52 by agathabarro      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGRAM = pipex

SRC = src/pipex.c src/pipex_utils.c
OBJS = $(SRC:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I include
MAKE = make -C 
LIBFT_PATH = libft
LIBFT = ${LIBFT_PATH}/libft.a

#valgrind --leak-check=full --trace-children=yes

.c.o:
					${CC} ${CFLAGS} ${INCLUDE} -c $< -o $(<:.c=.o)

$(PROGRAM): ${OBJS}
		${MAKE} ${LIBFT_PATH} all
		${CC} ${OBJS} ${LIBFT} -o ${PROGRAM}

all:	${PROGRAM}

clean:
		${MAKE} ${LIBFT_PATH} clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} ${PROGRAM}

re: fclean all

.PHONY: all clean fclean re