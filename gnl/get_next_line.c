/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:33:39 by kkurita           #+#    #+#             */
/*   Updated: 2021/03/12 16:49:20 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		mult_free_ret_minus(char *line, char *stock, char *buf)
{
	if (line)
		free(line);
	if (stock)
		free(stock);
	if (buf)
		free(buf);
	return (-1);
}

char	pre_create_string(char **line, char **stockp)
{
	char	retval;
	size_t	n;
	char	*tmp;

	n = ft_strchr(*stockp, '\n');
	if (!(tmp = ft_strjoin(*line, *stockp, n)))
		return (mult_free_ret_minus(*line, *stockp, NULL));
	free(*line);
	*line = tmp;
	tmp = NULL;
	retval = 0;
	if (*(*stockp + n) == '\n')
	{
		if (!(tmp = ft_strdup(*stockp + n + 1)))
			return (mult_free_ret_minus(*line, *stockp, NULL));
		retval = 1;
	}
	free(*stockp);
	*stockp = tmp;
	return (retval);
}

char	create_string(char **line, char **stockp, char *buf)
{
	char	retval;
	size_t	n;
	char	*tmp;

	n = ft_strchr(buf, '\n');
	if (!(tmp = ft_strjoin(*line, buf, n)))
		return (mult_free_ret_minus(*line, NULL, buf));
	free(*line);
	*line = tmp;
	tmp = NULL;
	retval = 0;
	if (*(buf + n) == '\n')
	{
		if (!(*stockp = ft_strdup(buf + n + 1)))
			return (mult_free_ret_minus(*line, NULL, buf));
		retval = 1;
	}
	return (retval);
}

int		get_next_line(int fd, char **line)
{
	static char	*stock;
	char		*buf;
	ssize_t		read_res;
	char		retval;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || !(*line = malloc(1)))
		return (-1);
	**line = 0;
	retval = 0;
	if (stock)
		retval = pre_create_string(line, &stock);
	if (!(buf = malloc((long long)BUFFER_SIZE + 1)))
		return (mult_free_ret_minus(*line, NULL, NULL));
	while (retval == 0 && (read_res = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		*(buf + read_res) = 0;
		retval = create_string(line, &stock, buf);
	}
	free(buf);
	if (read_res == -1)
		return (mult_free_ret_minus(*line, stock, NULL));
	return (retval);
}
