/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_processing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:50:55 by fhagrave          #+#    #+#             */
/*   Updated: 2019/05/13 14:01:15 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_virtual_nbr(int n, char **output)
{
	if (n == -2147483648)
	{
		ft_put_virtual_char('-', output);
		ft_put_virtual_char('2', output);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_put_virtual_char('-', output);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_put_virtual_nbr(n / 10, output);
		ft_put_virtual_nbr(n % 10, output);
	}
	else
		ft_put_virtual_char(n + '0', output);
}

void	ft_put_virtual_char(char c, char **output)
{
	**output = c;
	(*output)++;
}
