/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_type_pxo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:17:28 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/01 19:50:01 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		negative_pxo(t_spec spec, long long num, int len, char *str)
{
	sign_point(spec, num, 'a');
	len += (num == -1 && spec.u.f.f4) ? 1 : 0;
	if (len < spec.prec)
		while (len < spec.prec)
		{
			ft_putchar('0');
			len++;
		}
	if (spec.u.f.f4 & 1 && num != 0)
		len += (num == -1) ? 0 : 2;
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
			spec.width -= (num == -1) ? 1 : 2;
		while (--spec.width >= spec.prec)
			ft_putchar(' ');
		sign_point(spec, num, 'a');
		len += (num == -1 && spec.u.f.f4) ? 1 : 0;
		while (++len <= spec.prec)
			ft_putchar('0');
	}
	else
	{
		if (spec.u.f.f4 & 1 && num != 0)
			len += (num == -1) ? 1 : 2;
		while (++len <= spec.width)
			ft_putchar(' ');
		sign_point(spec, num, 'a');
	}
	ft_putstr(str);
}

void		null_pxo(t_spec spec, long long num, int len, char *str)
{
	if (spec.prec <= 0)
	{
		if (spec.u.f.f4 & 1 && num != 0)
			len += (num == -1) ? 1 : 2;
		sign_point(spec, num, 'a');
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

void		none_pxo(t_spec spec, long long num, int len, char *str)
{
	if (len < spec.prec)
	{
		if (spec.u.f.f4 & 1 && num != 0)
			spec.width -= (num == -1) ? 1 : 2;
		if (spec.prec < spec.width)
			while (--spec.width >= spec.prec)
				ft_putchar(' ');
		sign_point(spec, num, 'a');
		len += (num == -1 && spec.u.f.f4) ? 1 : 0;
		while (++len <= spec.prec)
			ft_putchar('0');
	}
	else
	{
		if (spec.u.f.f4 & 1 && num != 0)
			len += (num == -1) ? 1 : 2;
		while (++len <= spec.width)
			ft_putchar(' ');
		sign_point(spec, num, 'a');
	}
	ft_putstr(str);
}
