/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_type_diu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:12:37 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/01 19:49:53 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		negative_diu(t_spec spec, long long num, int len)
{
	sign(spec, num);
	if (len < spec.prec)
		while (len < spec.prec)
		{
			ft_putchar('0');
			len++;
		}
	if (num < 0 || spec.u.f.f2 & 1 || spec.u.f.f3 & 1)
		len++;
	if (!(spec.prec == 0 && num == 0))
		putnumber(num);
	if (len < spec.width)
		while (++len <= spec.width)
			ft_putchar(' ');
}

static void	null_support(t_spec spec, long long num, int len)
{
	if (len < spec.prec)
	{
		if (num < 0 || spec.u.f.f2 & 1 || spec.u.f.f3 & 1)
			spec.width--;
		while (--spec.width >= spec.prec)
			ft_putchar(' ');
		sign(spec, num);
		while (++len <= spec.prec)
			ft_putchar('0');
	}
	else
	{
		if (num < 0 || spec.u.f.f2 & 1 || spec.u.f.f3 & 1)
			len++;
		while (++len <= spec.width)
			ft_putchar(' ');
		sign(spec, num);
	}
	if (!(spec.prec == 0 && num == 0))
		putnumber(num);
}

void		null_diu(t_spec spec, long long num, int len)
{
	if (spec.prec <= 0)
	{
		if (num < 0 || spec.u.f.f2 & 1 || spec.u.f.f3 & 1)
			len++;
		sign(spec, num);
		if (len < spec.width)
			while (++len <= spec.width)
				ft_putchar('0');
		if (!(spec.prec == 0 && num == 0))
			putnumber(num);
	}
	else
	{
		null_support(spec, num, len);
	}
}

void		none_diu(t_spec spec, long long num, int len)
{
	if (len < spec.prec)
	{
		if (num < 0 || spec.u.f.f2 & 1 || spec.u.f.f3 & 1)
			spec.width--;
		if (spec.prec < spec.width)
			while (--spec.width >= spec.prec)
				ft_putchar(' ');
		sign(spec, num);
		while (++len <= spec.prec)
			ft_putchar('0');
	}
	else
	{
		if (num < 0 || spec.u.f.f2 & 1 || spec.u.f.f3 & 1)
			len++;
		while (++len <= spec.width)
			ft_putchar(' ');
		sign(spec, num);
	}
	if (!(spec.prec == 0 && num == 0))
		putnumber(num);
}
