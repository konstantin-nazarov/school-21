/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_llf_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:48:25 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/13 13:50:21 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_big_num_llf(char **output, unsigned int n[MAX_DIGITS_LLF],
									unsigned int point, unsigned int length)
{
	unsigned int	i;
	int				point_appears;

	point_appears = 0;
	i = length;
	while (i > 0)
	{
		i--;
		ft_put_virtual_nbr(n[i], output);
		if (i == point && i != 0)
		{
			ft_put_virtual_char('.', output);
			point_appears = 1;
		}
	}
	return (point_appears);
}

int			start_processing_number_llf(char **output, unsigned int e,
									unsigned long int m, unsigned int pres)
{
	unsigned int	res[MAX_DIGITS_LLF];
	unsigned int	point;
	unsigned int	length;

	length = 0;
	if (e >= E_LIMIT_LLF)
	{
		mult_x_y_to_the_power_llf(m, 2, e - E_LIMIT_LLF, res);
		point = 0;
		length = count_digits_llf(res);
		set_presition_llf(res, pres, point, &length);
		length += pres;
	}
	else if (e < E_LIMIT_LLF)
	{
		mult_x_y_to_the_power_llf(m, 5, E_LIMIT_LLF - e, res);
		point = E_LIMIT_LLF - e;
		length = count_digits_llf(res);
		set_presition_llf(res, pres, point, &length);
	}
	point = pres;
	length += print_big_num_llf(output, res, point, length);
	return (length);
}

static void	support_is_it(char **output, unsigned long int m)
{
	if (m == M_MASK2_LLF)
	{
		ft_put_virtual_char('i', output);
		ft_put_virtual_char('n', output);
		ft_put_virtual_char('f', output);
	}
	else
	{
		ft_put_virtual_char('n', output);
		ft_put_virtual_char('a', output);
		ft_put_virtual_char('n', output);
	}
}

int			is_it_special_value_llf(char **output, unsigned int e,
									unsigned long int m, unsigned int pres)
{
	unsigned int	i;

	i = 0;
	if (e == E_MASK_LLF)
	{
		support_is_it(output, m);
		return (3);
	}
	else if (e == 0 && m == 0)
	{
		ft_put_virtual_char('0', output);
		if (pres != 0)
		{
			ft_put_virtual_char('.', output);
			while (i < pres)
			{
				ft_put_virtual_char('0', output);
				i++;
			}
			return (pres + 2);
		}
		return (1);
	}
	return (0);
}
