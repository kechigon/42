/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:35:43 by kkurita           #+#    #+#             */
/*   Updated: 2021/02/20 13:18:50 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned char	uc;

	str = (char *)s;
	uc = (unsigned char)c;
	while (*str)
	{
		if (*str == uc)
			return (str);
		str++;
	}
	return (NULL);
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

//s1,s2は動的確保と仮定
char	*ft_strjoin(char *s1, char *s2)
{
	char	*cpy;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!(cpy = (char *)malloc((s1len + s2len + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy(cpy, s1, s1len);
	ft_memcpy(cpy + s1len, s2, s2len);
	*(cpy + s1len + s2len) = '\0';
	free(s1);
	free(s2);
	return (cpy);
}
