/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:14:55 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/20 12:40:06 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*s;
	const char	*s2;

	s = (char *)dest;
	s2 = (const char *)src;
	while (n--)
	{
		*s++ = *s2++;
	}
	return (dest);
}
