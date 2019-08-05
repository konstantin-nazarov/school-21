/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:15:27 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/01 19:29:12 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_spec(va_list *ap, t_spec spec)
{
	void	*p;
	char	*s;
	int		len;

	p = va_arg(*ap, void*);
	s = (!p && spec.prec == 0) ? ft_strnew(0)
		: ft_lutoa_16((long long int)p, 'a');
	len = ft_strlen(s);
	spec.u.f.f4 = 1;
	if (spec.u.f.f1 & 1)
		negative_pxo(spec, -2, len, s);
	else if (spec.u.f.f5 & 1)
		null_pxo(spec, -2, len, s);
	else
		none_pxo(spec, -2, len, s);
	len = (spec.prec > len) ? spec.prec : len;
	len += (spec.u.f.f4 & 1) ? 2 : 0;
	len = (spec.width > len) ? spec.width : len;
	free(s);
	return (len);
}
