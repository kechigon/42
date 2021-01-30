/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:09:39 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/30 14:45:47 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static int	count_digit(long n)
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
}*/
static int	digit_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while ((n = n / 10))
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		index;
	int		flag;
	long	nl;

	nl = (long)n;
	index = digit_len(n);
	flag = 0;
	if (!(str = (char *)malloc(sizeof(char) * index + 1)))
		return (0);
	str[index] = '\0';
	if (nl < 0)
	{
		flag = 1;
		nl *= -1;
	}
	while (0 < index)
	{
		str[--index] = nl % 10 + '0';
		nl /= 10;
	}
	if (flag)
		str[0] = '-';
	return (str);
	/*long	cast;
	char	*res;
	int		digit;

	cast = (long)n;
	digit = count_digit(cast);
	if (n < 0)
	{
		if (!(res = (char *)ft_calloc(digit + 3, sizeof(char))))
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
	}*/
}
