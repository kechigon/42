NAME = get_next_line
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=4 -g -fsanitize=address
RM = rm -rf

all: ${NAME}

${NAME}: main.c get_next_line.c get_next_line_utils.c
	gcc ${CFLAGS} -o $@ $^

flean:
	${RM} ${NAME}

re: fclean all


.PHONY: all, flean, re