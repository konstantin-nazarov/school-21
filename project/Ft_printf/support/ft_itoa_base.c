/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:54:19 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/01 20:18:30 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base_letter(unsigned int val, int base, char letter)
{
	char			*str;
	int				n;
	unsigned int	num;
	char			a;

	if (val == 0)
		return (utoa_support());
	num = val;
	n = 0;
	while (num != 0)
	{
		num /= base;
		n++;
	}
	if ((str = (char *)malloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	str[n] = '\0';
	a = (letter == 'a') ? 'a' : 'A';
	while ((n) != 0)
	{
		n--;
		str[n] = (val % base < 10) ? val % base + '0' : val % base + a - 10;
		val /= base;
	}
	return (str);
}
