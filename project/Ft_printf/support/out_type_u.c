/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_type_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:15:18 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/01 19:50:12 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	negative_u(t_spec spec, unsigned long long num, int len)
{
	if (len < spec.prec)
		while (len < spec.prec)
		{
			ft_putchar('0');
			len++;
		}
	putnumber_u(num);
	if (len < spec.width)
		while (++len <= spec.width)
			ft_putchar(' ');
}

void	null_u(t_spec spec, unsigned long long num, int len)
{
	if (spec.prec <= 0)
	{
		if (len < spec.width)
			while (++len <= spec.width)
				ft_putchar('0');
		putnumber_u(num);
	}
	else
	{
		if (len < spec.prec)
		{
			while (--spec.width >= spec.prec)
				ft_putchar(' ');
			while (++len <= spec.prec)
				ft_putchar('0');
		}
		else
		{
			while (++len <= spec.width)
				ft_putchar(' ');
		}
		putnumber_u(num);
	}
}

void	none_u(t_spec spec, unsigned long long num, int len)
{
	if (len < spec.prec)
	{
		if (spec.prec < spec.width)
			while (--spec.width >= spec.prec)
				ft_putchar(' ');
		while (++len <= spec.prec)
			ft_putchar('0');
	}
	else
	{
		while (++len <= spec.width)
			ft_putchar(' ');
	}
	putnumber_u(num);
}
