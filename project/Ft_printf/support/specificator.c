/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specificator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:52:25 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/01 19:49:36 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_flags(t_spec *spec, char c)
{
	if (c == '-')
		spec->u.f.f1 |= 1;
	else if (c == '+')
		spec->u.f.f2 |= 1;
	else if (c == ' ')
		spec->u.f.f3 |= 1;
	else if (c == '#')
		spec->u.f.f4 |= 1;
	else if (c == '0')
		spec->u.f.f5 |= 1;
}

void		spec_support(t_spec *spec, char *str, int *i)
{
	spec->prec = 0;
	spec->u.f.dot_for_prec = 1;
	if (str[++(*i)] >= '0' && str[*i] <= '9')
	{
		spec->prec = ft_atoi(&str[*i]);
		*i += (digit_number(spec->prec) > 0) ? digit_number(spec->prec) : 1;
	}
}

int			create_spec(t_spec *spec, char *str)
{
	int	i;

	i = 0;
	spec->prec = -1;
	while (str[i] == '-' || str[i] == '+'
		|| str[i] == ' ' || str[i] == '#' || str[i] == '0')
	{
		check_flags(spec, str[i]);
		i++;
	}
	if (str[i] >= '1' && str[i] <= '9')
	{
		spec->width = ft_atoi(&str[i]);
		i += digit_number(spec->width);
	}
	if (str[i] == '.')
		spec_support(spec, str, &i);
	if (str[i] == 'h' || str[i] == 'l'
		|| str[i] == 'L' || str[i] == 'j' || str[i] == 'z')
	{
		spec->mod[0] = str[i++];
		if (str[i] == 'h' || str[i] == 'l')
			spec->mod[1] = str[i++];
	}
	return (i);
}
