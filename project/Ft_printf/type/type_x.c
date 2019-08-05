/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:26:48 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/01 19:30:33 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	llx_spec(va_list *ap, t_spec spec)
{
	unsigned long long int	i;
	int						len;
	char					*s;

	i = va_arg(*ap, unsigned long long int);
	s = ft_lutoa_16(i, 'a');
	len = ft_strlen(s);
	if (spec.u.f.f1 & 1)
		negative_pxo(spec, i, len, s);
	else if (spec.u.f.f5 & 1)
		null_pxo(spec, i, len, s);
	else
		none_pxo(spec, i, len, s);
	shift_u(spec, &len, i, 'x');
	free(s);
	return (len);
}

int	lx_spec(va_list *ap, t_spec spec)
{
	long		i;
	int			len;
	char		*s;

	i = va_arg(*ap, unsigned long int);
	s = ft_lutoa_16(i, 'a');
	len = ft_strlen(s);
	if (spec.u.f.f1 & 1)
		negative_pxo(spec, i, len, s);
	else if (spec.u.f.f5 & 1)
		null_pxo(spec, i, len, s);
	else
		none_pxo(spec, i, len, s);
	shift_u(spec, &len, i, 'x');
	free(s);
	return (len);
}

int	hhx_spec(va_list *ap, t_spec spec)
{
	unsigned char		i;
	int					len;
	char				*s;

	i = (unsigned char)va_arg(*ap, int);
	s = ft_lutoa_16(i, 'a');
	len = ft_strlen(s);
	if (spec.u.f.f1 & 1)
		negative_pxo(spec, i, len, s);
	else if (spec.u.f.f5 & 1)
		null_pxo(spec, i, len, s);
	else
		none_pxo(spec, i, len, s);
	shift_u(spec, &len, i, 'x');
	free(s);
	return (len);
}

int	hx_spec(va_list *ap, t_spec spec)
{
	short		i;
	int			len;
	char		*s;

	i = (unsigned short int)va_arg(*ap, int);
	s = ft_sutoa_16(i, 'a');
	len = ft_strlen(s);
	if (spec.u.f.f1 & 1)
		negative_pxo(spec, i, len, s);
	else if (spec.u.f.f5 & 1)
		null_pxo(spec, i, len, s);
	else
		none_pxo(spec, i, len, s);
	shift_u(spec, &len, i, 'x');
	free(s);
	return (len);
}

int	x_spec(va_list *ap, t_spec spec)
{
	int		i;
	int		len;
	char	*s;

	if (ft_strstr(spec.mod, "ll") || spec.mod[0] == 'j' || spec.mod[0] == 'z')
		return (llx_spec(ap, spec));
	else if (spec.mod[0] == 'l')
		return (lx_spec(ap, spec));
	else if (ft_strstr(spec.mod, "hh"))
		return (hhx_spec(ap, spec));
	else if (spec.mod[0] == 'h')
		return (hx_spec(ap, spec));
	i = va_arg(*ap, unsigned int);
	s = (spec.prec == 0 && i == 0)
		? ft_strnew(0) : ft_itoa_base_letter(i, 16, 'a');
	len = ft_strlen(s);
	if (spec.u.f.f1 & 1)
		negative_pxo(spec, i, len, s);
	else if (spec.u.f.f5 & 1)
		null_pxo(spec, i, len, s);
	else
		none_pxo(spec, i, len, s);
	shift_u(spec, &len, (i < 0) ? 1 : i, 'x');
	free(s);
	return (len);
}
