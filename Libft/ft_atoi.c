/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:11:50 by kkurita           #+#    #+#             */
/*   Updated: 2021/02/01 03:18:46 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	char sign;
	long ans;

	sign = 1;
	ans = 0;
	while (('\t' <= *s && *s <= '\r') || *s == ' ')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s++ == '-')
			sign = -1;
	}
	while (ft_isdigit(*s))
	{
		ans = ans * 10 + (*s++ - '0');
	}
	return ((int)ans * sign);
}
