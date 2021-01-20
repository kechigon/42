/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:21:33 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/20 19:47:50 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*s;
	const char	*s2;

	s = (char *)dest;
	s2 = (const char *)src;
	if (s > s2)
	{
		while (n--)
		{
			*(s + n) = *(s2 + n);
		}
	}
	else if (s < s2)
	{
		while (n--)
		{
			*s++ = *s2++;
		}
	}
	return (dest);
}
