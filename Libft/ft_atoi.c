/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:11:50 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/24 15:45:37 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	char sign;
	long ans;
	long ov_div;
	long ov_mod;

	sign = 1;
	ans = 0;
	ov_div = LONG_MAX / 10;
	ov_mod = LONG_MAX % 10;
	while (('\t' <= *s && *s <= '\r') || *s == ' ')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s++ == '-')
			sign = -1;
	}
	while ('0' <= *s && *s <= '9')
	{
		if (ans > ov_div || (ans == ov_div && *s > ov_mod))
			return ((int)LONG_MAX);
		ans = ans * 10 + (*s++ - '0');
	}
	return ((int)ans * sign);
}
