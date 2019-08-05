/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:41:43 by krakharo          #+#    #+#             */
/*   Updated: 2018/11/20 23:55:17 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi_2(const char *str)
{
	int		i;
	long	res;
	int		sign;
	long	tmp;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == '0' || str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1 + (i++) * 0;
	else if (str[i] == '+')
		sign = 1 + (i++) * 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = res;
		res = res * 10 + (str[i++] - '0') * sign;
		if (tmp < 0 && res > tmp)
			return (0);
		if (tmp > 0 && res < tmp)
			return (-1);
	}
	return (res);
}
