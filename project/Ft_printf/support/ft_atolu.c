/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:34:00 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/01 19:11:08 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			init_vars(unsigned long int *result, int *index)
{
	*result = 0;
	*index = 0;
}

static char			*remove_spaces(char *str)
{
	while (str[0] == ' ' || str[0] == '\t' || str[0] == '\n'
		|| str[0] == '\f' || str[0] == '\v' || str[0] == '\r')
		str++;
	return (str);
}

static char			*remove_signs_then_zeroes(char *str)
{
	if (str[0] == '+')
		str++;
	while (str[0] == '0')
		str++;
	return (str);
}

unsigned long int	ft_atolu(const char *str)
{
	int					index;
	unsigned long int	result;
	char				*st;

	st = (char *)str;
	init_vars(&result, &index);
	st = remove_spaces(st);
	if (st[0] == '\e')
		return (0);
	st = remove_signs_then_zeroes(st);
	while (st[index] >= '0' && st[index] <= '9' && ++index)
	{
		result *= 10;
		result += st[index - 1] - '0';
	}
	return (result);
}
