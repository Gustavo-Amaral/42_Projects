# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 16:42:46 by gamaral           #+#    #+#              #
#    Updated: 2023/10/22 17:57:44 by gamaral          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Standard

NAME := push_swap
NAME_BONUS := $(addsuffix _bonus, $(NAME))
CC := cc 
CFLAGS := -Wall -Wextra -Werror -g
RM = rm -rf
INCLUDE = -I . -I ./Includes
LDLIBS = -L . -L Libft -l ft_printf -l ft
LIBFTPATH = Libft
LIBFT = Libft/libft.a

ifdef DEBUG
	CFLAGS += -fsanitize=address
endif

#Sources

SRC = main.c ${wildcard Src/*.c}
SRC_BONUS = ${wildcard Bonus/*.c}

#Objects

OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRC_BONUS:.c=.o}

all: ${NAME}

$(NAME): $(OBJS) $(Libft)
	${MAKE} -C ${LIBFTPATH} bonus
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)
	${RM} ${OBJS}
	${MAKE} -C ${LIBFTPATH} fclean

Libft:
	${MAKE} -C ${LIBFTPATH} bonus

bonus: $(OBJS) $(OBJS_BONUS) $(Libft)
	${MAKE} -C ${LIBFTPATH} bonus
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS) $(LIBFT)
	${RM} ${OBJS} ${OBJS_BONUS}
	${MAKE} -C ${LIBFTPATH} fclean

clean:
	${RM} ${OBJS} ${NAME}
	${MAKE} -C ${LIBFTPATH} clean 

fclean:
	${RM} ${OBJS} ${NAME} ${NAME_BONUS}
	${MAKE} -C ${LIBFTPATH} fclean

re: fclean all