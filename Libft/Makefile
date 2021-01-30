CFLAG = -Wall -Wextra -Werror -g
NAME = libft.a
SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_atoi.c ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
B_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c
OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)
AR = ar rc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(B_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

exe: $(NAME) main.o
	gcc main.o $(NAME) -o exe

main.o: main.c
	gcc -c -g main.c

test:
	bash ../../Libftest/grademe.sh

bonus: $(OBJS) $(B_OBJS)
	$(AR) $(NAME) $^

.PHONY: all, clean, fclean, re, test, bonus
