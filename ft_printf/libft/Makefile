# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 21:28:12 by gamaral           #+#    #+#              #
#    Updated: 2023/05/20 17:56:08 by gamaral          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PART1 = ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c \
		ft_isdigit.c ft_isalpha.c ft_atoi.c ft_strlen.c ft_strlcat.c \
		ft_strncmp.c ft_strdup.c ft_calloc.c ft_memcpy.c ft_strchr.c \
		ft_strrchr.c ft_strnstr.c ft_bzero.c ft_memchr.c ft_memcmp.c \
		ft_memset.c ft_memmove.c ft_strlcpy.c

PART2 = ft_itoa.c ft_strjoin.c ft_split.c ft_striteri.c ft_strmapi.c \
		ft_substr.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c

EXTRA =	ft_putstr.c ft_strcmp.c ft_swap.c ft_decimal_to_hexadecimal.c \
		ft_putchar.c ft_putnbr.c ft_revstr.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRC = ${PART1} ${PART2} ${EXTRA}

OBJS = ${SRC:.c=.o}
BONUS_OBJS = ${BONUS:.c=.o}

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .

.o:.c
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

libft_all:	${NAME}

bonus:	${OBJS} ${BONUS_OBJS}
		ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

libft_clean:
		${RM} ${OBJS} ${BONUS_OBJS}

libft_fclean: libft_clean
		${RM} ${NAME}

libft_re: fclean all

.PHONY: libft_all libft_clean libft_fclean libft_re