CFLAG = -Wall -Wextra -Werror -c -g
NAME = libft.a
SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c
OBJS = ${SRCS:.c=.o}
AR = ar rc
RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

${OBJS}: ${SRCS}
	gcc ${CFLAG} ${SRCS}

clean:
	${RM} ${OBJS}

fclean:
	${RM} ${NAME}

re: fclean all

exe: ${NAME} main.o
	gcc main.o ${NAME} -o exe

main.o: main.c
	gcc -c -g main.c

.PHONY: all, clean, fclean, re
