/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:09:39 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/30 15:12:06 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(long n)
{
	int ans;

	ans = 1;
	if (n < 0)
		ans++;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		ans++;
	}
	return (ans);
}

char		*ft_itoa(int n)
{
	long	cast;
	char	*res;
	int		len;

	cast = (long)n;
	len = count_len(cast);
	if (!(res = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	*(res + len) = '\0';
	if (cast < 0)
		cast *= -1;
	while (len)
	{
		*(res + --len) = '0' + cast % 10;
		cast /= 10;
	}
	if (n < 0)
		*res = '-';
	return (res);
}
