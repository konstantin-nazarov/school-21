/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:31:44 by krakharo          #+#    #+#             */
/*   Updated: 2018/11/21 23:04:28 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			i;

	tmp1 = (unsigned char*)src;
	tmp2 = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		tmp2[i] = tmp1[i];
		if (tmp1[i] == (unsigned char)c)
			return ((void *)tmp2 + i + 1);
		i++;
	}
	return (0);
}
