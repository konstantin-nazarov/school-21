/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 00:22:03 by krakharo          #+#    #+#             */
/*   Updated: 2018/11/26 03:12:54 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*res;
	t_list	*start;

	if (!lst || !f)
		return (0);
	res = (*f)(lst);
	if (!(res = ft_lstnew(res->content, res->content_size)))
		return (0);
	start = res;
	lst = lst->next;
	while (lst)
	{
		tmp = (*f)(lst);
		res->next = ft_lstnew(tmp->content, tmp->content_size);
		res = res->next;
		lst = lst->next;
		free(tmp);
	}
	return (start);
}
