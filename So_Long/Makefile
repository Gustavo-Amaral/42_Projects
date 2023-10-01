# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 19:05:59 by gamaral           #+#    #+#              #
#    Updated: 2023/10/01 21:01:23 by gamaral          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Standard

NAME := so_long
CC := cc 
RM = rm -rf
INCLUDE = -I . -I ./Includes
LDLIBS = -L . -L Libft -l ft_printf -l ft
LIBFTPATH = Libft
LIBFT = Libft/libft.a
MLXFLAGS = -lmlx -lXext -lX11 -lm

#Sources

SRC = main.c ${wildcard Src/*.c}

#Objects

OBJS = ${SRC:.c=.o}

all: ${NAME}

$(NAME): $(OBJS) $(Libft)
	${MAKE} -C ${LIBFTPATH} bonus
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBFT)
	${RM} ${OBJS}
	${MAKE} -C ${LIBFTPATH} fclean

Libft:
	${MAKE} -C ${LIBFTPATH} bonus

clean:
	${RM} ${OBJS} ${NAME}
	${MAKE} -C ${LIBFTPATH} clean 

fclean:
	${RM} ${OBJS} ${NAME}
	${MAKE} -C ${LIBFTPATH} fclean

re: fclean all