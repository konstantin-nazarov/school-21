/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 20:47:23 by krakharo          #+#    #+#             */
/*   Updated: 2018/11/02 20:47:25 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_infix(t_btree *root, void (*applyf)(void*))
{
	if (root && applyf)
	{
		ft_btree_apply_infix(root->left, applyf);
		(*applyf)(root->item);
		ft_btree_apply_infix(root->right, applyf);
	}
}
