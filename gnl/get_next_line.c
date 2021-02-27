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

char	pre_create_string(char *line, char *stock)
{
	char	retval;
	size_t	n;
	char	*tmp;

	n = ft_strchr(stock, '\n');
	if (!(tmp = ft_strjoin(line, stock, n)))
		return (mult_free_ret_minus(line, stock, NULL));
	free(line);
	line = tmp;
	tmp = NULL;
	retval = 0;
	if (*(stock + n) == '\n')
	{
		if (!(tmp = ft_strdup(stock + n + 1)))
			return (mult_free_ret_minus(line, stock, NULL));
		retval = 1;
	}
	free(stock);
	stock = tmp;
	return (retval);
}

char	create_string(char *line, char *stock, char *buf)
{
	char	retval;
	size_t	n;
	char	*tmp;

	n = ft_strchr(buf, '\n');
	if (!(tmp = ft_strjoin(line, buf, n)))
		return (mult_free_ret_minus(line, NULL, buf));
	free(line);
	line = tmp;
	retval = 0;
	if (*(buf + n) == '\n')
	{
		if (!(stock = ft_strdup(buf + n + 1)))
			return (mult_free_ret_minus(line, NULL, buf));
		retval = 1;
	}
	return (retval);
}

int		get_next_line(int fd, char **line)
{
	static char	*stock;
	char		*buf;
	//char		*endl;
	//size_t		endl_index;
	ssize_t		read_res;
	//char		*tmp;
	char		retval;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || !(*line = (char *)malloc(sizeof(char))))
		return (-1);
	**line = 0;
	if (stock)
	 retval = pre_create_string(*line, stock);
	/*{
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
	}*/
	if (!(buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (mult_free_ret_minus(*line, NULL, NULL));
	while ((read_res = read(fd, buf, BUFFER_SIZE)) > 0 && retval == 0)
	{
		*(buf + read_res) = 0;
		retval = create_string(*line, stock, buf);
	}
	free(buf);
	if (read_res == -1)
		return (-1);
	return (retval);
	/*free(buf);
	if (retval == -1)
		return (mult_free_ret_minus);
	return (retval);*/
	/*while (1)
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
	}*/
}
