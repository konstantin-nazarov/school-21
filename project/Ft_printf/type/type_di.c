/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 12:23:44 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/08 16:58:14 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lli_spec(va_list *ap, t_spec spec)
{
	long long	i;
	int			len;

	i = va_arg(*ap, long long);
	len = (i == 0) ? 1 : digit_number(i);
	if (spec.u.f.f1 & 1)
		negative_diu(spec, i, len);
	else if (spec.u.f.f5 & 1)
		null_diu(spec, i, len);
	else
		none_diu(spec, i, len);
	shift(spec, &len, i, 'i');
	return (len);
}

int	li_spec(va_list *ap, t_spec spec)
{
	long	i;
	int		len;

	i = va_arg(*ap, long);
	len = (i == 0) ? 1 : digit_number(i);
	if (spec.u.f.f1 & 1)
		negative_diu(spec, i, len);
	else if (spec.u.f.f5 & 1)
		null_diu(spec, i, len);
	else
		none_diu(spec, i, len);
	shift(spec, &len, i, 'i');
	return (len);
}

int	hhi_spec(va_list *ap, t_spec spec)
{
	char	i;
	int		len;

	i = (char)va_arg(*ap, int);
	len = (i == 0) ? 1 : digit_number(i);
	if (spec.u.f.f1 & 1)
		negative_diu(spec, i, len);
	else if (spec.u.f.f5 & 1)
		null_diu(spec, i, len);
	else
		none_diu(spec, i, len);
	shift(spec, &len, i, 'i');
	return (len);
}

int	hi_spec(va_list *ap, t_spec spec)
{
	short	i;
	int		len;

	i = (short)va_arg(*ap, int);
	len = (i == 0) ? 1 : digit_number(i);
	if (spec.u.f.f1 & 1)
		negative_diu(spec, i, len);
	else if (spec.u.f.f5 & 1)
		null_diu(spec, i, len);
	else
		none_diu(spec, i, len);
	shift(spec, &len, i, 'i');
	return (len);
}

int	di_spec(va_list *ap, t_spec spec)
{
	int	i;
	int	len;

	if (ft_strstr(spec.mod, "ll") || spec.mod[0] == 'j' || spec.mod[0] == 'z')
		return (lli_spec(ap, spec));
	else if (spec.mod[0] == 'l')
		return (li_spec(ap, spec));
	else if (ft_strstr(spec.mod, "hh"))
		return (hhi_spec(ap, spec));
	else if (spec.mod[0] == 'h')
		return (hi_spec(ap, spec));
	i = va_arg(*ap, int);
	len = (spec.prec != 0 && i == 0) ? 1 : digit_number(i);
	if (spec.u.f.f1 & 1)
		negative_diu(spec, i, len);
	else if (spec.u.f.f5 & 1)
		null_diu(spec, i, len);
	else
		none_diu(spec, i, len);
	shift(spec, &len, i, 'i');
	return (len);
}
