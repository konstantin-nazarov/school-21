/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:30:08 by krakharo          #+#    #+#             */
/*   Updated: 2019/06/17 15:30:09 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_digitnb(double nb)
{
	long	size;

	if (nb >= 0.0 && nb <= 1.0)
		return (2);
	if (nb >= -1.0 && nb < 0)
		return (3);
	nb *= 10;
	size = 0;
	if (nb < 0)
	{
		size++;
		nb = -nb;
	}
	while (nb > 9)
	{
		nb /= 10;
		size++;
	}
	return (++size);
}

char		*ft_ftoa(double nb)
{
	double	n;
	char	*str;
	long	length;

	n = nb;
	nb *= 10;
	length = ft_digitnb(n);
	if (!(str = (char *)malloc(sizeof(char) * (length + 2))))
		return (NULL);
	str[length + 1] = '\0';
	if (nb < 0)
		nb = -nb;
	str[length] = ((int)nb % 10) + '0';
	nb /= 10;
	str[length - 1] = '.';
	length -= 2;
	while (length >= 0)
	{
		str[length--] = ((int)nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
