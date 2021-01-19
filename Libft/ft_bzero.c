/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:25:54 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/19 20:08:55 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *addr, size_t n)
{
	unsigned char *s;

	s = (unsigned char *)addr;
	while (n--)
	{
		*s = 0;
		s++;
	}
}
