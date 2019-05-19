/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 23:23:36 by ccolemon          #+#    #+#             */
/*   Updated: 2019/02/21 22:41:57 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strstr_num(const char *str, const char *to_find)
{
	int	i;
	int	z;
	int	size;
	int	num;

	i = 0;
	z = 0;
	num = 0;
	if (!(size = ft_strlen(to_find)))
		return (0);
	while (str[i])
	{
		while (to_find[z] == str[i + z])
		{
			if (z == size - 1)
				num++;
			z++;
		}
		z = 0;
		i++;
	}
	return (num);
}
