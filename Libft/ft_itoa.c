/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:09:39 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/26 20:56:43 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(long n)
{
	int ans;

	ans = 0;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		ans++;
	}
	return (ans);
}

static char	*convert(char *addr, long n, int i)
{
	*(addr + i + 1) = '\0';
	while (i)
	{
		*(addr + i--) = '0' + n % 10;
		n /= 10;
	}
	*(addr) = '0' + n;
	return (addr);
}

char		*ft_itoa(int n)
{
	long	cast;
	char	*res;
	int		digit;

	cast = (long)n;
	digit = count_digit(cast);
	if (n < 0)
	{
		if (!(res = (char *)calloc(digit + 3, sizeof(char))))
			return (NULL);
		*res = '-';
		convert(res + 1, -cast, digit);
		return (res);
	}
	else
	{
		if (!(res = (char *)calloc(digit + 2, sizeof(char))))
			return (NULL);
		return (convert(res, cast, digit));
	}
}
