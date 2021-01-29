/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:50:57 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/30 03:23:18 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char c;
	long l;

	l = n;
	if (l < 0)
	{
		write(fd, "-", 1);
		l *= -1;
	}
	if (l < 10)
	{
		c = '0' + l;
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(l / 10, fd);
		ft_putnbr_fd(l % 10, fd);
	}
}
