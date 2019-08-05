/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:28:16 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/22 21:26:11 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free(void *lst, size_t n)
{
	free(lst);
	n = 0;
}

static t_list	*ft_help(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*begin;
	t_list	*new;

	if (!(new = f(ft_lstnew(lst->content, lst->content_size))))
		return (0);
	start = new;
	lst = lst->next;
	while (lst && new)
	{
		if (!(begin = f(ft_lstnew(lst->content, lst->content_size))))
			return (0);
		new->next = begin;
		new = new->next;
		lst = lst->next;
	}
	return (start);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;

	if (!lst || !f)
		return (0);
	if (!(start = f(ft_lstnew(lst->content, lst->content_size))))
		return (0);
	if (lst->next)
		lst = lst->next;
	else
		return (start);
	if (!(start->next = ft_help(lst, f)))
		ft_lstdel(&start, ft_free);
	return (start);
}
