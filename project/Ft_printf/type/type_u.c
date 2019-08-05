/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 12:24:47 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/08 20:00:47 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	llu_spec(va_list *ap, t_spec spec)
{
	unsigned long long	i;
	int					len;

	i = va_arg(*ap, unsigned long long);
	len = (i == 0) ? 1 : digit_number_u(i);
	if (spec.u.f.f1 & 1)
		negative_u(spec, i, len);
	else if (spec.u.f.f5 & 1)
		null_u(spec, i, len);
	else
		none_u(spec, i, len);
	shift(spec, &len, i, 'u');
	return (len);
}

int	lu_spec(va_list *ap, t_spec spec)
{
	long	i;
	int		len;

	i = va_arg(*ap, unsigned long);
	len = (i == 0) ? 1 : digit_number_u(i);
	if (spec.u.f.f1 & 1)
		negative_u(spec, i, len);
	else if (spec.u.f.f5 & 1)
		null_u(spec, i, len);
	else
		none_u(spec, i, len);
	shift(spec, &len, i, 'u');
	return (len);
}

int	hhu_spec(va_list *ap, t_spec spec)
{
	unsigned char	i;
	int				len;

	i = (unsigned char)va_arg(*ap, int);
	len = (i == 0) ? 1 : digit_number(i);
	if (spec.u.f.f1 & 1)
		negative_u(spec, i, len);
	else if (spec.u.f.f5 & 1)
		null_u(spec, i, len);
	else
		none_u(spec, i, len);
	shift(spec, &len, i, 'i');
	return (len);
}

int	hu_spec(va_list *ap, t_spec spec)
{
	unsigned short	i;
	int				len;

	i = (unsigned short)va_arg(*ap, int);
	len = (i == 0) ? 1 : digit_number(i);
	if (spec.u.f.f1 & 1)
		negative_u(spec, i, len);
	else if (spec.u.f.f5 & 1)
		null_u(spec, i, len);
	else
		none_u(spec, i, len);
	shift(spec, &len, i, 'i');
	return (len);
}

int	u_spec(va_list *ap, t_spec spec)
{
	unsigned int	i;
	int				len;

	if (ft_strstr(spec.mod, "ll") || spec.mod[0] == 'j' || spec.mod[0] == 'z')
		return (llu_spec(ap, spec));
	else if (spec.mod[0] == 'l')
		return (lu_spec(ap, spec));
	else if (ft_strstr(spec.mod, "hh"))
		return (hhu_spec(ap, spec));
	else if (spec.mod[0] == 'h')
		return (hu_spec(ap, spec));
	i = va_arg(*ap, unsigned int);
	if (spec.prec == 0 && i == 0)
		return (0);
	len = (i == 0) ? 1 : digit_number_u(i);
	if (spec.u.f.f1 & 1)
		negative_u(spec, i, len);
	else if (spec.u.f.f5 & 1)
		null_u(spec, i, len);
	else
		none_u(spec, i, len);
	shift(spec, &len, i, 'u');
	return (len);
}
