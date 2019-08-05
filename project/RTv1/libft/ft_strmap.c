/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:02:24 by krakharo          #+#    #+#             */
/*   Updated: 2018/11/22 18:02:26 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	res = (char*)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	j = -1;
	while (++j < i)
		res[j] = (*f)(s[j]);
	res[j] = '\0';
	return (res);
}
