/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x_big.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:55:44 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/01 19:57:58 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	llx_big_spec(va_list *ap, t_spec spec)
{
	long long	i;
	int			len;
	char		*s;

	i = va_arg(*ap, unsigned long long);
	s = ft_lutoa_16(i, 'A');
	len = ft_strlen(s);
	if (spec.u.f.f1 & 1)
		negative_big_x(spec, i, len, s);
	else if (spec.u.f.f5 & 1)
		null_big_x(spec, i, len, s);
	else
		none_big_x(spec, i, len, s);
	shift_u(spec, &len, i, 'X');
	free(s);
	return (len);
}

int	lx_big_spec(va_list *ap, t_spec spec)
{
	long		i;
	int			len;
	char		*s;

	i = va_arg(*ap, unsigned long);
	s = ft_lutoa_16(i, 'A');
	len = ft_strlen(s);
	if (spec.u.f.f1 & 1)
		negative_big_x(spec, i, len, s);
	else if (spec.u.f.f5 & 1)
		null_big_x(spec, i, len, s);
	else
		none_big_x(spec, i, len, s);
	shift_u(spec, &len, i, 'X');
	free(s);
	return (len);
}

int	hhx_big_spec(va_list *ap, t_spec spec)
{
	unsigned char		i;
	int					len;
	char				*s;

	i = (unsigned char)va_arg(*ap, int);
	s = ft_lutoa_16(i, 'A');
	len = ft_strlen(s);
	if (spec.u.f.f1 & 1)
		negative_big_x(spec, i, len, s);
	else if (spec.u.f.f5 & 1)
		null_big_x(spec, i, len, s);
	else
		none_big_x(spec, i, len, s);
	shift_u(spec, &len, i, 'X');
	free(s);
	return (len);
}

int	hx_big_spec(va_list *ap, t_spec spec)
{
	short		i;
	int			len;
	char		*s;

	i = (unsigned short int)va_arg(*ap, int);
	s = ft_sutoa_16(i, 'A');
	len = ft_strlen(s);
	if (spec.u.f.f1 & 1)
		negative_big_x(spec, i, len, s);
	else if (spec.u.f.f5 & 1)
		null_big_x(spec, i, len, s);
	else
		none_big_x(spec, i, len, s);
	shift_u(spec, &len, i, 'X');
	free(s);
	return (len);
}

int	x_big_spec(va_list *ap, t_spec spec)
{
	int		i;
	int		len;
	char	*s;

	if (ft_strstr(spec.mod, "ll") || spec.mod[0] == 'j' || spec.mod[0] == 'z')
		return (llx_big_spec(ap, spec));
	else if (spec.mod[0] == 'l')
		return (lx_big_spec(ap, spec));
	else if (ft_strstr(spec.mod, "hh"))
		return (hhx_big_spec(ap, spec));
	else if (ft_strstr(spec.mod, "h"))
		return (hx_big_spec(ap, spec));
	if ((i = va_arg(*ap, unsigned int)) == 0 && spec.prec == 0)
		return (0);
	s = ft_itoa_base_letter(i, 16, 'A');
	len = ft_strlen(s);
	if (spec.u.f.f1 & 1)
		negative_big_x(spec, i, len, s);
	else if (spec.u.f.f5 & 1)
		null_big_x(spec, i, len, s);
	else
		none_big_x(spec, i, len, s);
	shift_u(spec, &len, (i < 0) ? 1 : i, 'X');
	free(s);
	return (len);
}
