/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:16:59 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/21 12:34:04 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *addr1, const void *addr2, size_t n)
{
	const unsigned char *s1;
	const unsigned char *s2;

	s1 = (const unsigned char *)addr1;
	s2 = (const unsigned char *)addr2;
	while (n--)
	{
		if (*s1++ != *s2++)
		{
			return (*(s1 - 1) < *(s2 - 1) ? -1 : 1);
		}
	}
	return (0);
}
