/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:15:43 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/30 03:00:55 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	/*char	*str;
	char	*head;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	head = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (head);*/
	char	*cpy;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!(cpy = (char *)ft_calloc(s1len + s2len + 1, sizeof(char))))
		return (NULL);
	ft_memcpy(cpy, s1, s1len);
	ft_memcpy(cpy + s1len, s2, s2len);
	*(cpy + s1len + s2len + 1) = '\0';
	return (cpy);*/
}
