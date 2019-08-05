/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 18:07:53 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/01 19:31:42 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	llo_spec(va_list *ap, t_spec spec)
{
	long long	i;
	int			len;
	char		*s;

	i = va_arg(*ap, unsigned long long);
	s = ft_lutoa_8(i);
	len = ft_strlen(s);
	if (spec.u.f.f1 & 1)
		negative_pxo(spec, -1, len, s);
	else if (spec.u.f.f5 & 1)
		null_pxo(spec, -1, len, s);
	else
		none_pxo(spec, -1, len, s);
	shift(spec, &len, i, 'o');
	free(s);
	return (len);
}

int	lo_spec(va_list *ap, t_spec spec)
{
	long		i;
	int			len;
	char		*s;

	i = va_arg(*ap, unsigned long);
	s = (spec.prec == 0 && i == 0) ? ft_strnew(0) : ft_lutoa_8(i);
	len = ft_strlen(s);
	if (spec.u.f.f1 & 1)
		negative_pxo(spec, -1, len, s);
	else if (spec.u.f.f5 & 1)
		null_pxo(spec, -1, len, s);
	else
		none_pxo(spec, -1, len, s);
	shift(spec, &len, i, 'o');
	free(s);
	return (len);
}

int	hho_spec(va_list *ap, t_spec spec)
{
	unsigned char		i;
	int					len;
	char				*s;

	i = (unsigned char)va_arg(*ap, int);
	s = ft_lutoa_8(i);
	len = ft_strlen(s);
	if (spec.u.f.f1 & 1)
		negative_pxo(spec, -1, len, s);
	else if (spec.u.f.f5 & 1)
		null_pxo(spec, -1, len, s);
	else
		none_pxo(spec, -1, len, s);
	shift(spec, &len, i, 'o');
	free(s);
	return (len);
}

int	ho_spec(va_list *ap, t_spec spec)
{
	short		i;
	int			len;
	char		*s;

	i = (short)va_arg(*ap, int);
	s = ft_sutoa_8(i);
	len = ft_strlen(s);
	if (spec.u.f.f1 & 1)
		negative_pxo(spec, -1, len, s);
	else if (spec.u.f.f5 & 1)
		null_pxo(spec, -1, len, s);
	else
		none_pxo(spec, -1, len, s);
	shift(spec, &len, i, 'o');
	free(s);
	return (len);
}

int	o_spec(va_list *ap, t_spec f)
{
	int		i;
	int		len;
	char	*s;

	if ((i = type_o_support(ap, f)) != -1)
		return (i);
	i = va_arg(*ap, unsigned int);
	if (f.u.f.f4 && i == 0)
	{
		write(1, "0", 1);
		return ((f.width > 0) ? f.width : 1);
	}
	s = (f.prec == 0 && i == 0) ? ft_strnew(0) : ft_itoa_base_letter(i, 8, 'a');
	len = ft_strlen(s);
	if (f.u.f.f1 & 1)
		negative_pxo(f, -1, len, s);
	else if (f.u.f.f5 & 1)
		null_pxo(f, -1, len, s);
	else
		none_pxo(f, -1, len, s);
	len = (f.width < f.prec && f.prec > (int)ft_strlen(s)) ? f.prec : len;
	if (f.width >= f.prec || (int)ft_strlen(s) >= f.prec)
		shift(f, &len, i, 'o');
	free(s);
	return (len);
}
