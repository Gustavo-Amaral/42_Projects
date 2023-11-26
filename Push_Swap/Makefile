# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 16:42:46 by gamaral           #+#    #+#              #
#    Updated: 2023/11/26 20:21:46 by gamaral          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Standard

NAME := push_swap
NAME_BONUS := checker
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

MAIN = main.c
SRC = ${wildcard Src/*.c}
SRC_BONUS = ${wildcard Bonus/*.c}

#Objects

MAIN_OBJ = ${MAIN:.c=.o}
OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRC_BONUS:.c=.o}

all: ${NAME}

$(NAME): $(MAIN_OBJ) $(OBJS) $(Libft)
	${MAKE} -C ${LIBFTPATH} bonus
	$(CC) $(CFLAGS) $(OBJS) $(MAIN) -o $(NAME) $(LIBFT)
	${RM} ${OBJS}
	${MAKE} -C ${LIBFTPATH} fclean

Libft:
	${MAKE} -C ${LIBFTPATH} bonus

bonus: $(OBJS) $(OBJS_BONUS) $(Libft)
	${MAKE} -C ${LIBFTPATH} bonus
	$(CC) $(CFLAGS) $(OBJS) $(MAIN) -o $(NAME) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_BONUS) -o $(NAME_BONUS) $(LIBFT)
	${RM} $(MAIN_OBJ) ${OBJS} ${OBJS_BONUS}
	${MAKE} -C ${LIBFTPATH} fclean

clean:
	${RM} $(MAIN_OBJ) ${OBJS} ${NAME}
	${MAKE} -C ${LIBFTPATH} clean 

fclean:
	${RM} $(MAIN_OBJ) ${OBJS} ${NAME} ${NAME_BONUS}
	${MAKE} -C ${LIBFTPATH} fclean

re: fclean all