/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:13:32 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/13 13:59:58 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putstring(char *str, int size)
{
	while (*str && size-- > 0)
		write(1, str++, 1);
}

void	ft_putnbr_ulong(unsigned long int n)
{
	if (n >= 10)
		ft_putnbr_ulong(n / 10);
	ft_putchar(n % 10 + '0');
}

void	putnumber_u(unsigned long long n)
{
	if (n >= 10)
	{
		putnumber(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
		ft_putchar(n + '0');
}

void	putnumber(long long n)
{
	if (n < -9223372036854775807)
	{
		ft_putchar('9');
		n = 223372036854775808;
	}
	if (n < 0)
		n *= -1;
	if (n >= 10)
	{
		putnumber(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
		ft_putchar(n + '0');
}

void	ft_putstr_fast(char const *s)
{
	write(1, s, ft_strlen(s));
}
