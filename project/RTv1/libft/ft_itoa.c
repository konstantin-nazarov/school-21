/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:12:05 by krakharo          #+#    #+#             */
/*   Updated: 2018/11/22 20:12:07 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		tmp;
	int		sign;

	tmp = n;
	i = 1;
	sign = 1;
	while (tmp != 0)
		tmp = tmp / 10 + (i++) * 0;
	if (n < 0 || n == 0)
		i++;
	if (!(res = (char*)malloc(sizeof(char) * i)))
		return (0);
	if (n < 0 && (sign = -1))
		res[0] = '-' + (tmp++) * 0;
	res[--i] = '\0';
	while (i > tmp)
	{
		res[--i] = n % 10 * sign + '0';
		n = n / 10;
	}
	return (res);
}
