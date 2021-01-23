/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:15:21 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/23 21:28:08 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_index;

	dest_index = ft_strlen(dest);
	while (*src && dest_index + 1 < size)
		*(dest + dest_index++) = *src++;
	*(dest + dest_index) = '\0';
	return (ft_strlen(src) + (dest_index < size ? dest_index : size));
}
