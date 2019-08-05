/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_type_big_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:58:46 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/01 20:21:27 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		negative_big_x(t_spec spec, long long num, int len, char *str)
{
	sign_point(spec, num, 'A');
	if (len < spec.prec)
		while (len < spec.prec)
		{
			ft_putchar('0');
			len++;
		}
	if (spec.u.f.f4 & 1 && num != 0)
		len += 2;
	ft_putstr(str);
	if (len < spec.width)
		while (++len <= spec.width)
			ft_putchar(' ');
}

static void	null_support(t_spec spec, long long num, int len, char *str)
{
	if (len < spec.prec)
	{
		if (spec.u.f.f4 & 1 && num != 0)
			spec.width -= 2;
		while (--spec.width >= spec.prec)
			ft_putchar(' ');
		sign_point(spec, num, 'A');
		while (++len <= spec.prec)
			ft_putchar('0');
	}
	else
	{
		if (spec.u.f.f4 & 1 && num != 0)
			len += 2;
		while (++len <= spec.width)
			ft_putchar(' ');
		sign_point(spec, num, 'A');
	}
	ft_putstr(str);
}

void		null_big_x(t_spec spec, long long num, int len, char *str)
{
	if (spec.prec <= 0)
	{
		if (spec.u.f.f4 & 1 && num != 0)
			len += 2;
		sign_point(spec, num, 'A');
		if (len < spec.width)
			while (++len <= spec.width)
				ft_putchar('0');
		ft_putstr(str);
	}
	else
	{
		null_support(spec, num, len, str);
	}
}

void		none_big_x(t_spec spec, long long num, int len, char *str)
{
	if (len < spec.prec)
	{
		if (spec.u.f.f4 & 1 && num != 0)
			spec.width -= 2;
		if (spec.prec < spec.width)
			while (--spec.width >= spec.prec)
				ft_putchar(' ');
		sign_point(spec, num, 'A');
		while (++len <= spec.prec)
			ft_putchar('0');
	}
	else
	{
		if (spec.u.f.f4 & 1 && num != 0)
			len += 2;
		while (++len <= spec.width)
			ft_putchar(' ');
		sign_point(spec, num, 'A');
	}
	ft_putstr(str);
}
