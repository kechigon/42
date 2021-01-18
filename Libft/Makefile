# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 18:21:23 by kkurita           #+#    #+#              #
#    Updated: 2021/01/18 20:56:51 by kkurita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAG = -Wall -Wextra -Werror -c
NAME = libft.a
SRCS = ft_memset.c
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
