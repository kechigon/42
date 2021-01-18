CFLAG = -Wall -Wextra -Werror -c
NAME = libft.a
SRCS =
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

.PHONY: all, clean, fclean, re