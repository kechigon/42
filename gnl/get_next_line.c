/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:33:39 by kkurita           #+#    #+#             */
/*   Updated: 2021/02/24 00:56:35 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		mult_free_ret_minus(char *stock, char *buf, char *line)
{
	if (stock)
		free(stock);
	if (buf)
		free(buf);
	if (line)
		free(line);
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char	*stock;
	char		*buf;
	char		*endl;
	size_t		endl_index;
	ssize_t		read_res;
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || !(*line = (char *)malloc(sizeof(char))))
		return (-1);
	**line = 0;
	if (stock)
	{
		if ((endl = ft_strchr(stock, '\n')))
		{
			endl_index = endl - stock;
			if (!(tmp = ft_strjoin(*line, stock, endl_index)))
				return (mult_free_ret_minus(stock, NULL, *line));
			free(*line);
			*line = tmp;
			tmp = NULL;
			if (!(tmp = ft_strdup(stock + endl_index + 1)))
				return (mult_free_ret_minus(stock, NULL, *line));
			free(stock);
			stock = tmp;
			tmp = NULL;
			return (1);
		}
		if (!(tmp = ft_strjoin(*line, stock, ft_strlen(stock))))
			return (mult_free_ret_minus(stock, NULL, *line));
		free(*line);
		*line = tmp;
		tmp = NULL;
		stock = NULL;
		free(stock);
	}
	if (!(buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (mult_free_ret_minus(NULL, NULL, *line));
	while (1)
	{
		if ((read_res = read(fd, buf, BUFFER_SIZE)) == -1)
			return (mult_free_ret_minus(NULL, buf, *line));
		if (read_res == 0)
		{
			free(buf);
			return (0);
		}
		*(buf + read_res) = 0;
		if ((endl = ft_strchr(buf, '\n')))
		{
			endl_index = endl - buf;
			if (!(tmp = ft_strjoin(*line, buf, endl_index)))
				return (mult_free_ret_minus(NULL, buf, *line));
			free(*line);
			*line = tmp;
			tmp = NULL;
			if (!(stock = ft_strdup(buf + endl_index + 1)))
				return (mult_free_ret_minus(NULL, buf, *line));
			free(buf);
			return (1);
		}
		else
		{
			if (!(tmp = ft_strjoin(*line, buf, ft_strlen(buf))))
				return (mult_free_ret_minus(NULL, buf, *line));
			free(*line);
			*line = tmp;
			tmp = NULL;
		}
	}
}
