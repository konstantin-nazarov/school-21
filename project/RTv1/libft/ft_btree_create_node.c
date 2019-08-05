/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 20:01:35 by krakharo          #+#    #+#             */
/*   Updated: 2018/11/02 20:01:36 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_create_node(void *item)
{
	t_btree	*node;

	if (!item)
		return (NULL);
	node = malloc(sizeof(t_btree));
	if (!node)
		return (NULL);
	node->item = item;
	node->left = 0;
	node->right = 0;
	return (node);
}
