NAME := libft.a
OBJS := $(patsubst %.c,%.o,$(wildcard *.c))
LIBHEADER := libft.h
CC := gcc
CFLAGS := -Wall -Wextra -Werror
vpath %h ../Headers

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS) $(LIBHEADER)

.PHONY: all clean fclean re

re: all fclean

all: $(NAME)

fclean: clean
	rm -f $(NAME)

clean:
	rm *.o