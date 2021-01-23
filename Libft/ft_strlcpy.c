/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:26:15 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/21 20:11:09 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t maxlen)
{
	size_t srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < maxlen)
	{
		ft_memcpy(dest, src, srclen + 1);
	}
	else if (maxlen)
	{
		ft_memcpy(dest, src, maxlen - 1);
		*(dest + maxlen - 1) = '\0';
	}
	return (srclen);
}
