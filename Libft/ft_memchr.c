/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:59:45 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/21 12:21:49 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *addr, int c, size_t n)
{
	const unsigned char	*s;
	unsigned char		uc;

	s = (const unsigned char *)addr;
	uc = (unsigned char)c;
	while (n--)
	{
		if (*s++ == uc)
		{
			return ((void *)(s - 1));
		}
	}
	return (NULL);
}
