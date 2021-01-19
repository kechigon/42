/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:14:55 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/19 20:30:45 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *s;
	unsigned char *s2;

	s = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	while (n--)
	{
		*s = *s2;
		s++;
		s2++;
	}
	return (dest);
}
