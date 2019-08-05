/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 22:48:36 by krakharo          #+#    #+#             */
/*   Updated: 2018/11/02 22:48:37 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	if (!root || !cmpf)
		return (NULL);
	else if ((*cmpf)(data_ref, root->item) == 0)
		return (root->item);
	else
	{
		ft_btree_search_item(root->left, data_ref, cmpf);
		ft_btree_search_item(root->right, data_ref, cmpf);
	}
	return (NULL);
}
