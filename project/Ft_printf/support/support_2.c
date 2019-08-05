/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:11:49 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/01 19:34:15 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		type_o_support(va_list *ap, t_spec spec)
{
	if (ft_strstr(spec.mod, "ll") || spec.mod[0] == 'j' || spec.mod[0] == 'z')
		return (llo_spec(ap, spec));
	else if (spec.mod[0] == 'l')
		return (lo_spec(ap, spec));
	else if (ft_strstr(spec.mod, "hh"))
		return (hho_spec(ap, spec));
	else if (spec.mod[0] == 'h')
		return (ho_spec(ap, spec));
	return (-1);
}

void	sign_point(t_spec spec, long long num, char c)
{
	if (spec.u.f.f4 == 1)
	{
		if (num == -1)
			ft_putstr("0");
		else if (num == -2 && c == 'a')
			ft_putstr("0x");
		else if (c == 'a' && num != 0)
			ft_putstr("0x");
		else if (c == 'A' && num != 0)
			ft_putstr("0X");
	}
}

void	sign(t_spec spec, long long num)
{
	if (num < 0)
		ft_putchar('-');
	else if (spec.u.f.f2 & 1)
		ft_putchar('+');
	else if (spec.u.f.f3 & 1)
		ft_putchar(' ');
}

void	init_func_array(int (*func[NUM])(va_list *, t_spec))
{
	func[0] = &di_spec;
	func[1] = &di_spec;
	func[2] = &s_spec;
	func[3] = &lu_spec;
	func[4] = &u_spec;
	func[5] = &o_spec;
	func[6] = &x_spec;
	func[7] = &x_big_spec;
	func[8] = &f_spec;
	func[9] = &p_spec;
	func[14] = &li_spec;
	func[15] = &lo_spec;
	func[18] = &f_spec;
}

void	init_spec_array(char spec[NUM])
{
	spec[0] = 'd';
	spec[1] = 'i';
	spec[2] = 's';
	spec[3] = 'U';
	spec[4] = 'u';
	spec[5] = 'o';
	spec[6] = 'x';
	spec[7] = 'X';
	spec[8] = 'f';
	spec[9] = 'p';
	spec[10] = 'c';
	spec[11] = '\n';
	spec[12] = '%';
	spec[13] = 'm';
	spec[14] = 'D';
	spec[15] = 'O';
	spec[16] = 'R';
	spec[17] = 'Z';
	spec[18] = 'F';
}
