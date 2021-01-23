/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 23:20:03 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/24 01:29:53 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	s2len;
	size_t	i;
	size_t	j;

	s2len = ft_strlen(s2);
	i = 0;
	j = 0;
	if (s2len == 0)
		return ((char *)s1);
	while (*(s1 + i) && i < len)
	{
		while (*(s1 + i + j) == *(s2 + j) && i + j < len)
		{
			if (j == s2len - 1)
				return ((char *)(s1 + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
