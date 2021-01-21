/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:55:10 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/21 12:17:45 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*s1;
	const unsigned char	*s2;
	unsigned char		uc;

	s1 = (unsigned char *)dest;
	s2 = (const unsigned char *)src;
	uc = (unsigned char)c;
	while (n--)
	{
		if ((*s1++ = *s2++) == uc)
		{
			return (s1);
		}
	}
	return (NULL);
}
