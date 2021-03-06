/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:15:43 by kkurita           #+#    #+#             */
/*   Updated: 2021/02/15 00:36:57 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cpy;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!(cpy = (char *)ft_calloc(s1len + s2len + 1, sizeof(char))))
		return (NULL);
	ft_memcpy(cpy, s1, s1len);
	free(s1);
	ft_memcpy(cpy + s1len, s2, s2len);
	*(cpy + s1len + s2len + 1) = '\0';
	return (cpy);
}
