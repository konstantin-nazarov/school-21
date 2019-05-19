/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:06:11 by ccolemon          #+#    #+#             */
/*   Updated: 2019/02/21 21:53:26 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_atoi_base(char *str, int base)
{
	int			n;
	unsigned	num;

	n = ft_countchars(str, 32, 0);
	num = 0;
	if (base <= 10)
		while (--n >= 0)
			num += (*str++ - 48) * ft_pow(base, n);
	else
	{
		if (*str == '0' && *(str + 1) == 'x')
			str += 2;
		n = ft_countchars(str, 32, 0);
		while (--n >= 0)
		{
			if (ft_isdigit(*str))
				num += (*str - 48) * ft_pow(base, n);
			else if (ft_isalpha(*str))
				num += (ft_toupper(*str) - 55) * ft_pow(base, n);
			else
				ERR;
			str++;
		}
	}
	return (num);
}
