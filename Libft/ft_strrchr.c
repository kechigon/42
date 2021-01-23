/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 22:23:00 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/23 22:58:06 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	unsigned char	uc;
	char			*ans;

	str = (char *)s;
	uc = (unsigned char)c;
	ans = NULL;
	while (*str)
	{
		if (*str == uc)
			ans = str;
		str++;
	}
	if (uc == '\0')
		ans = str;
	return (ans);
}
