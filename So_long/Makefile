# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_2                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 15:33:10 by gamaral           #+#    #+#              #
#    Updated: 2023/08/06 19:29:11 by gamaral          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME = ${shell uname}

NAME := so_long.a
CC := cc
CFLAGS := -Wall -Werror -Wextra
RM = rm -f

INCLUDE = -I
INCFOLDER = Includes

SRCFOLDER = Sources
OBJFOLDER = Objects

LIBFTPATH = Libft/
LIBFT = libft.a

MLXPATH = minilibx-linux/
MLXLIB = libmlx_${UNAME}.a

EXTRALIBS = -L/usr/lib -lXext -lX11 -lm -lz

SRC = ${wildcard ${SRCFOLDER}/*.c}

OBJS = ${SRC:.c=.o}

${NAME}: ${OBJS} Libft Minilibx
	mkdir ${OBJFOLDER}
	mv ${LIBFTPATH}${LIBFT} ${OBJFOLDER}
	mv ${MLXPATH}${MLXLIB} ${OBJFOLDER}
	cd ${OBJFOLDER}
	ar x ${MLXLIB} *
	ar x ${LIBFT} *
	ar -rcs ${NAME} ${OBJS}

.o:.c
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

Libft:
	${MAKE} bonus -C ${LIBFTPATH}

Minilibx:
	${MAKE} -C ${MLXPATH}

all: ${NAME}

clean:
		${RM} ${OBJS} ${BONUS_OBJS}
		${MAKE} -C ${LIBFTPATH} libft_clean

fclean: clean
		${RM} ${NAME}
		${MAKE} -C ${LIBFTPATH} libft_fclean

re: fclean all

.PHONY: all clean fclean re libft