/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:01:52 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/26 15:54:23 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(const char *s, char c)
{
	size_t	len;
	size_t	count;

	len = 0;
	count = 0;
	while (*s)
	{
		if (*s++ == c)
		{
			if (len > 0)
				count++;
			len = 0;
		}
		else
			len++;
	}
	if (len > 0)
		count++;
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	if (!(res = (char**)calloc(count(s, c) + 1, sizeof(char *))))
		return (NULL);
	while (*(s + i))
	{
		while (*(s + i) == c)
			i++;
		start = i;
		while (*(s + i) != c && *(s + i))
			i++;
		if (i > start)
		{
			if (!(*(res + j++) = ft_substr(s, start, i - start)))
				return (NULL);
		}
	}
	*(res + j) = NULL;
	return (res);
}
