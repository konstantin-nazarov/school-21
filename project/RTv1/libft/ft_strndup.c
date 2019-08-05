/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 00:35:04 by krakharo          #+#    #+#             */
/*   Updated: 2018/11/21 00:38:17 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*res;
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	res = (char*)malloc(sizeof(char) * (n + 1));
	if (!res)
		return (0);
	i = 0;
	while (str[i] != '\0' && i < n)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
