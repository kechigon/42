/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:14:55 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/23 20:11:06 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*s1;
	const char	*s2;

	s1 = (char *)dest;
	s2 = (const char *)src;
	while (n--)
		*s1++ = *s2++;
	return (dest);
}
