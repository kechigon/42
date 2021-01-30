/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurita <kkurita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:36:21 by kkurita           #+#    #+#             */
/*   Updated: 2021/01/30 21:01:04 by kkurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *res;
	t_list *element;

	res = NULL;
	if (!f)
		return (NULL);
	while (lst)
	{
		if (!(element = ft_lstnew((*f)(lst->content))))
		{
			if (!del)
				return (NULL);
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, element);
		lst = lst->next;
	}
	return (res);
}
