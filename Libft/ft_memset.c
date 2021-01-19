/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:57:39 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/19 15:27:08 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *addr, int ch, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)addr + i) = (unsigned char)ch;
		i++;
	}
	return (addr);
}
