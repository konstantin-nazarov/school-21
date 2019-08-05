/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:13:59 by krakharo          #+#    #+#             */
/*   Updated: 2018/11/22 18:14:01 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		res[j] = (*f)(j, s[j]);
	res[j] = '\0';
	return (res);
}
