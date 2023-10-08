# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 19:05:59 by gamaral           #+#    #+#              #
#    Updated: 2023/10/08 19:41:38 by gamaral          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Standard

NAME := so_long
NAME_BONUS := so_long_bonus
CC := cc 
RM = rm -rf
INCLUDE = -I . -I ./Includes
LDLIBS = -L . -L Libft -l ft_printf -l ft
LIBFTPATH = Libft
LIBFT = Libft/libft.a
MLXFLAGS = -lmlx -lXext -lX11 -lm

#Sources

SRC = main.c ${wildcard Src/*.c}
SRC_BONUS = ${wildcard Bonus/*.c}

#Objects

OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRC_BONUS:.c=.o}

all: ${NAME}

$(NAME): $(OBJS) $(Libft)
	${MAKE} -C ${LIBFTPATH} bonus
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBFT)
	${RM} ${OBJS}
	${MAKE} -C ${LIBFTPATH} fclean

Libft:
	${MAKE} -C ${LIBFTPATH} bonus

bonus: $(OBJS_BONUS) $(Libft)
	${MAKE} -C ${LIBFTPATH} bonus
	$(CC) $(OBJS_BONUS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME_BONUS) $(LIBFT)
	${RM} ${OBJS_BONUS}
	${MAKE} -C ${LIBFTPATH} fclean

clean:
	${RM} ${OBJS} ${NAME}
	${MAKE} -C ${LIBFTPATH} clean 

fclean:
	${RM} ${OBJS} ${NAME}
	${MAKE} -C ${LIBFTPATH} fclean

re: fclean all