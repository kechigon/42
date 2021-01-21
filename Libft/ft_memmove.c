/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:21:33 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/21 12:18:32 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*s1;
	const char	*s2;

	s1 = (char *)dest;
	s2 = (const char *)src;
	if (s1 > s2)
	{
		while (n--)
		{
			*(s1 + n) = *(s2 + n);
		}
	}
	else if (s1 < s2)
	{
		while (n--)
		{
			*s1++ = *s2++;
		}
	}
	return (dest);
}
