/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:45:20 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/26 02:01:11 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*(s1 + i) && ft_strchr(set, *(s1 + i)))
		i++;
	j = ft_strlen(s1 + i);
	while (j && ft_strchr(set, *(s1 + i + j)))
		j--;
	return (ft_substr(s1, i, j + 1));
}
