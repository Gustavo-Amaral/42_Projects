
##### Compilation #####
CC = cc
CFLAGS = -Wall -Werror -Wextra

##### Commands #####
RM = rm -rf

###### Files #####
SRCS = 	ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strdup.c \
		ft_calloc.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_split.c

BONUSSRC = 	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \

OBJS = $(SRCS:.c=.o)
OBJSBONUS = $(BONUSSRC:.c=.o)

NAME = libft.a
all: $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJSBONUS)
	ar rc $(NAME) $(OBJS) $(OBJSBONUS)

clean:
	$(RM) $(OBJS) $(OBJSBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

#NOTES
#$< gives the name of the first prerequisite.
#$@ represents the name fo the target being built in the current rule.
#$^ prints the name of all the prerequisites
#%.o : %.c
#	$(CC) $(CFLAGS) -c $< -o $@