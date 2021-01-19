/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:04:59 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/19 20:15:59 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "stdlib.h"

void	*ft_memset(void *addr, int c, size_t n);
void	ft_bzero(void *addr, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
