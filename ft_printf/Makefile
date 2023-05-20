# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 19:21:12 by gamaral           #+#    #+#              #
#    Updated: 2023/05/20 18:35:07 by gamaral          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC := gcc
CFLAGS := -Wall -Werror -Wextra
RM = rm -f
INCLUDE = -I .
LDLIBS = -L . -L Libft -l ft_printf -l ft
LIBFTPATH = libft
LIBFT = libft/libft.a

SRC = ft_print_char.c ft_print_hex.c ft_print_nbr.c ft_print_ptr.c \
		ft_print_str.c ft_print_unsigned.c ft_printf.c


OBJS = ${SRC:.c=.o}

${NAME}: ${OBJS} Libft
	cp ${LIBFT} ${NAME}
	ar -rcs ${NAME} ${OBJS}

.o:.c
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

Libft:
	${MAKE} bonus -C ${LIBFTPATH}

all: ${NAME}

clean:
		${RM} ${OBJS} ${BONUS_OBJS}
		${MAKE} -C ${LIBFTPATH} libft_clean

fclean: clean
		${RM} ${NAME}
		${MAKE} -C ${LIBFTPATH} libft_fclean

re: fclean all

.PHONY: all clean fclean re libft