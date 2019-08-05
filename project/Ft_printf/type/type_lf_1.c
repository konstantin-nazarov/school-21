/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_lf_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:36:41 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/13 13:40:38 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			fill_array_with_x_lf(unsigned long int x,
											unsigned int res[MAX_DIGITS_LF])
{
	unsigned int		i;
	unsigned long long	base;
	unsigned long int	t;

	i = MAX_DIGITS_LF;
	base = BASE_LF;
	t = x;
	while (i != 0)
	{
		i--;
		if (i <= MAX_DIGIT_NUMBER_LF)
		{
			res[i] = t / base;
			t = t % base;
			base /= 10;
		}
		else
			res[i] = 0;
	}
}

static void		support_mult(unsigned int y, unsigned int power,
										unsigned int *res, unsigned int base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < power)
	{
		j = 0;
		while (j < MAX_DIGITS_LF)
		{
			res[j] *= y;
			j++;
		}
		j = 0;
		while (j < MAX_DIGITS_LF - 1)
		{
			if (res[j] >= base)
			{
				res[j + 1] += res[j] / base;
				res[j] %= base;
			}
			j++;
		}
		i++;
	}
}

void			mult_x_y_to_the_power_lf(unsigned long int x, unsigned int y,
						unsigned int power, unsigned int res[MAX_DIGITS_LF])
{
	unsigned int base;

	fill_array_with_x_lf(x, res);
	base = 10;
	if (power != 0)
	{
		support_mult(y, power, res, base);
	}
}

unsigned int	count_digits_lf(unsigned int res[MAX_DIGITS_LF])
{
	unsigned int i;

	i = MAX_DIGITS_LF;
	while (i > 0)
	{
		i--;
		if (res[i] == 0)
			continue ;
		else
			break ;
	}
	return (i + digit_number_ui(res[i]));
}

void			add_zeroes_to_tail_lf(unsigned int res[MAX_DIGITS_LF],
										unsigned int num, unsigned int length)
{
	unsigned int	i;

	i = 0;
	while (i <= length)
	{
		res[length + num - i] = res[length - i];
		i++;
	}
	i = num - 1;
	while (i != 0)
	{
		res[i] = 0;
		i--;
	}
	res[0] = 0;
}
