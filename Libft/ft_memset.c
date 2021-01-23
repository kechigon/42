/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:57:39 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/23 20:11:36 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *addr, int c, size_t n)
{
	unsigned char *s;
	unsigned char uc;

	s = (unsigned char *)addr;
	uc = (unsigned char)c;
	while (n--)
		*s++ = uc;
	return (addr);
}
