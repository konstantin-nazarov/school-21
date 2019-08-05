/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:30:38 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/08 19:59:41 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			shift_u(t_spec spec, int *len, unsigned long long num, char c)
{
	if (spec.prec > *len)
		*len = spec.prec;
	if (c == 'o')
	{
		if (spec.prec == 0 && num == 0)
			*len += (spec.u.f.f4 & 1) ? 1 : spec.width;
	}
	if (spec.u.f.f4 == 1 && num != 0)
		(*len) += 2;
	if (spec.prec < spec.width && spec.width > *len)
		*len = spec.width;
}

void			shift(t_spec spec, int *len, long long int num, char c)
{
	if (spec.prec >= spec.width && spec.prec > *len)
		*len = spec.prec;
	if (c == 'o')
	{
		if (spec.prec == 0 && num == 0)
			*len += (spec.u.f.f4 & 1) ? 1 : spec.width;
		else if (spec.u.f.f4 == 1 && num != 0)
			(*len)++;
	}
	else if (c != 'u')
		if (num < 0 || spec.u.f.f2 == 1 || spec.u.f.f3 == 1)
			(*len)++;
	if (c != 'o' && spec.u.f.f4 == 1 && num != 0)
		(*len) += 2;
	if (spec.prec < spec.width && spec.width > *len)
		*len = spec.width;
}

int				digit_number_u(unsigned long long result)
{
	if (result != 0)
		return (digit_number(result / 10) + 1);
	else
		return (0);
}

int				digit_number(long long result)
{
	if (result != 0)
		return (digit_number(result / 10) + 1);
	else
		return (0);
}

unsigned int	digit_number_ui(unsigned int nbr)
{
	if (nbr > 0)
		return (digit_number(nbr / 10) + 1);
	else
		return (0);
}
