/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:18:00 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/01 19:56:56 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*utoa_support(void)
{
	char	*str;

	if ((str = (char *)malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char		*ft_sutoa_8(short unsigned int value)
{
	char				*str;
	int					n;
	short unsigned int	num;

	if (value == 0)
		return (utoa_support());
	num = value;
	n = 0;
	while (num)
	{
		num /= 8;
		n++;
	}
	if ((str = (char *)malloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	str[n] = '\0';
	while (n)
	{
		n--;
		str[n] = value % 8 + '0';
		value /= 8;
	}
	return (str);
}

char		*ft_lutoa_8(long long unsigned int value)
{
	char					*str;
	int						n;
	long long unsigned int	num;

	if (value == 0)
		return (utoa_support());
	num = value;
	n = 0;
	while (num)
	{
		num /= 8;
		n++;
	}
	if ((str = (char *)malloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	str[n] = '\0';
	num = value;
	while (n)
	{
		n--;
		str[n] = num % 8 + '0';
		num /= 8;
	}
	return (str);
}

char		*ft_sutoa_16(short unsigned int value, char letter)
{
	char				*str;
	int					n;
	char				a;
	short unsigned int	num;

	if (value == 0)
		return (utoa_support());
	num = value;
	n = 0;
	while (num)
	{
		num /= 16;
		n++;
	}
	if ((str = (char *)malloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	str[n] = '\0';
	a = (letter == 'a') ? 'a' : 'A';
	while (n)
	{
		n--;
		str[n] = (value % 16 < 10) ? value % 16 + '0' : value % 16 + a - 10;
		value /= 16;
	}
	return (str);
}

char		*ft_lutoa_16(long long unsigned int value, char letter)
{
	char					*str;
	int						n;
	char					a;
	long long unsigned int	num;

	if (value == 0)
		return (utoa_support());
	num = value;
	n = 0;
	while (num)
	{
		num /= 16;
		n++;
	}
	if ((str = (char *)malloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	str[n] = '\0';
	a = (letter == 'a') ? 'a' : 'A';
	while (n)
	{
		n--;
		str[n] = (value % 16 < 10) ? value % 16 + '0' : value % 16 + a - 10;
		value /= 16;
	}
	return (str);
}
