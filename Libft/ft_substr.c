/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:44:37 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/30 01:19:33 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *cpy;

	if (!(cpy = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	if (ft_strlen(s) < start)
	{
		*cpy = '\0';
		return (cpy);
	}
	ft_memcpy(cpy, s + start, len);
	*(cpy + len + 1) = '\0';
	return (cpy);
}
