/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 20:57:31 by krakharo          #+#    #+#             */
/*   Updated: 2018/11/23 20:57:32 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = (t_list*)malloc(sizeof(*tmp));
	if (!tmp)
		return (NULL);
	if (!content)
	{
		tmp->content_size = 0;
		tmp->content = NULL;
	}
	else
	{
		tmp->content_size = content_size;
		tmp->content = malloc(content_size++);
		if (!tmp->content)
			return (NULL);
		while (--content_size > 0)
			((unsigned char*)tmp->content)[content_size - 1] =
				((unsigned char*)content)[content_size - 1];
	}
	tmp->next = NULL;
	return (tmp);
}
