/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:25:46 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/01 18:08:41 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_spec(va_list *ap, t_spec spec, char c)
{
	int	size;

	size = (spec.width > 1) ? spec.width : 1;
	if (c != 'Z' && c != 'R' && c != 'm' && c != '%' && c != '\n')
		c = (char)va_arg(*ap, int);
	if (spec.u.f.f1 == 1)
	{
		write(1, &c, 1);
		while (spec.width-- > 1)
			write(1, (spec.u.f.f5) ? "0" : " ", 1);
	}
	else
	{
		while (spec.width-- > 1)
			write(1, (spec.u.f.f5) ? "0" : " ", 1);
		write(1, &c, 1);
	}
	return (size);
}
