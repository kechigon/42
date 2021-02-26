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

int		mult_free_ret_minus(char *stock, char *buf, char *pre_line, char *line)
{
	if (stock)
		free(stock);
	if (buf)
		free(buf);
	if (pre_line)
		free(pre_line);
	if (line)
		free(line);
	return (-1);
}

/*char*	put_string(char *stock, char *buf, char *endl, size_t stock_count)
{
	size_t	endl_index;
	char	*tmp;
	char	*res;

	(void)buf;
	(void)stock_count;
	endl_index = endl - stock;
	//resに改行までコピー
	if (!(res= (char *)malloc((endl_index + 1) * sizeof(char))))
	{
		mult_free_ret_minus(stock, NULL, NULL, NULL);
		return (NULL);
	}
	ft_memcpy(res, stock, endl_index);
	*(res + endl_index) = '\0';
	//残りをまたstockとする
	if (!(tmp = ft_strdup(stock + endl_index + 1)))
	{
		mult_free_ret_minus(stock, NULL, NULL, res);
		return (NULL);
	}
	free(stock);
	stock = tmp;
	return (res);
}*/

int		get_next_line(int fd, char **line)
{
	static char	*stock;
	char		*buf;
	char		*endl;
	size_t		endl_index;
	size_t		stock_count;
	ssize_t		read_res;
	size_t		stock_len;
	char		*pre_line;
	char		*tmp;

	//例外処理
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	pre_line = NULL;
	//stock_count = 0;
	//ストックから読み込む
	if (stock)
	{
		stock_len = ft_strlen(stock);
		//stockに改行が含まれていた場合
		if ((endl = ft_strchr(stock, '\n')))
		{
			endl_index = endl - stock;
			// *lineに改行までコピー
			if (!(*line = (char *)malloc((endl_index + 1) * sizeof(char))))
				return (mult_free_ret_minus(stock, NULL, NULL, NULL));
			ft_memcpy(*line, stock, endl_index);
			*(*line + endl_index) = '\0';
			//残りをまたstockとする
			if (!(tmp = ft_strdup(stock + endl_index + 1)))
				return (mult_free_ret_minus(stock, NULL, NULL, *line));
			free(stock);
			stock = tmp;
			/*if (!(*line = create_string(stock, NULL, endl, stock_count)))
				return (-1);*/
			return (1);
		}
		if (!(pre_line = ft_strdup(stock)))
			return (mult_free_ret_minus(stock, NULL, NULL, NULL));
		free(stock);
	}
	if (!(buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (mult_free_ret_minus(NULL, NULL, pre_line, NULL));
	if (!(stock = (char *)malloc(sizeof(char))))
		return (mult_free_ret_minus(NULL, buf, pre_line, NULL));
	*stock = '\0';
	stock_count = 0;
	//改行や読み終わるまでBUFFER_SIZE分呼び込む
	while (1)
	{
		if ((read_res = read(fd, buf, BUFFER_SIZE)) == -1)
			return (mult_free_ret_minus(stock, buf, pre_line, NULL));
		//読み終わったら
		if (read_res == 0)
		{
			if (!(*line = ft_strdup(stock)))
				return (mult_free_ret_minus(stock, buf, pre_line, NULL));
			free(buf);
			free(stock);
			stock = NULL;
			if (pre_line)
			{
				if (!(*line = ft_strjoin(pre_line, *line)))
					return (mult_free_ret_minus(NULL, NULL, pre_line, *line));
			}
			return (0);
		}
		*(buf + read_res) = '\0';
		//改行があった場合
		if ((endl = ft_strchr(buf, '\n')))
		{
			endl_index = endl - buf;
			if (!(*line = (char *)malloc((BUFFER_SIZE * stock_count + endl_index + 1) * sizeof(char))))
				return (mult_free_ret_minus(stock, buf, pre_line, NULL));
			//stockとbufの\nまでをlineにコピー
			ft_memcpy(*line, stock, BUFFER_SIZE * stock_count);
			ft_memcpy(*line + BUFFER_SIZE * stock_count, buf, endl_index);
			*(*line + BUFFER_SIZE * stock_count + endl_index) = '\0';
			free(stock);
			//改行以降をstockにコピー
			if (!(stock = ft_strdup(buf + endl_index + 1)))
				return (mult_free_ret_minus(NULL, buf, pre_line, *line));
			free(buf);
			//前回のgnlで読み取った分とstrjoin
			if (pre_line)
			{
				if (!(*line = ft_strjoin(pre_line, *line)))
					return (mult_free_ret_minus(NULL, NULL, pre_line, *line));
			}
			return (1);
		}
		//なかった場合
		else
		{
			if (!(stock = ft_strjoin(stock, buf)))
				return (mult_free_ret_minus(stock, buf, pre_line, NULL));
			stock_count++;
			if (!(buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
				return (mult_free_ret_minus(stock, NULL, pre_line, NULL));
		}
	}
}