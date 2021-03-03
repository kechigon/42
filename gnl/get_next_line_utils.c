/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:35:43 by kkurita           #+#    #+#             */
/*   Updated: 2021/03/03 15:58:33 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned char	uc;
	size_t			res;

	str = (char *)s;
	uc = (unsigned char)c;
	res = 0;
	while (*(str + res))
	{
		if (*(str + res) == uc)
			return (res);
		res++;
	}
	return (res);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*s1;
	const char	*s2;

	if (!dest && !src)
		return (NULL);
	s1 = (char *)dest;
	s2 = (const char *)src;
	while (n--)
		*s1++ = *s2++;
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*cpy;

	len = ft_strlen(s) + 1;
	if (!(cpy = malloc(len)))
		return (NULL);
	return ((char *)ft_memcpy(cpy, s, len));
}

char	*ft_strjoin(char *s1, char *s2, size_t s2len)
{
	char	*cpy;
	size_t	s1len;

	s1len = ft_strlen(s1);
	if (!(cpy = malloc(s1len + s2len + 1)))
		return (NULL);
	ft_memcpy(cpy, s1, s1len);
	ft_memcpy(cpy + s1len, s2, s2len);
	*(cpy + s1len + s2len) = 0;
	return (cpy);
}
