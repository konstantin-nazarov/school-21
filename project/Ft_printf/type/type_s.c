/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:13:29 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/01 18:29:16 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	s_out(char *s, t_spec spec)
{
	int		anc;
	int		len;

	len = ft_strlen(s);
	len = (spec.prec == -1 || len < spec.prec) ? len : spec.prec;
	anc = len;
	if (spec.u.f.f1 == 1)
	{
		putstring(s, anc);
		while (spec.width > len++)
			write(1, (spec.u.f.f5) ? "0" : " ", 1);
	}
	else
	{
		while (spec.width > len++)
			write(1, (spec.u.f.f5) ? "0" : " ", 1);
		putstring(s, anc);
	}
	return (len);
}

int			s_spec(va_list *ap, t_spec spec)
{
	int		len;
	char	*s;

	if (!(s = (char *)va_arg(*ap, void*)))
	{
		s = ft_strdup("(null)");
		len = s_out(s, spec);
		free(s);
	}
	else
		len = s_out(s, spec);
	return (--len);
}
