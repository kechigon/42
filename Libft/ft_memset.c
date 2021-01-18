/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:57:39 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/18 17:57:39 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void *ft_memset(void *addr, int ch, size_t n)
{
    int i;

    i = 0;
    while(i < n)
    {
        *((int *)addr + i) = ch;
        i++;
    }
    return (addr);
}