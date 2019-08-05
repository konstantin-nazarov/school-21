/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:26:49 by krakharo          #+#    #+#             */
/*   Updated: 2018/11/22 17:29:57 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void		*res;
	size_t		i;

	i = 0;
	if (!(res = malloc(size)))
		return (NULL);
	while (i < size)
	{
		((unsigned char*)res)[i] = 0;
		i++;
	}
	return (res);
}
