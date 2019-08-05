/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:36:43 by krakharo          #+#    #+#             */
/*   Updated: 2018/11/22 19:36:44 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*res;

	if (!s)
		return (0);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		s++;
	while (s[i] != '\0')
		i++;
	i--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i >= 0)
		i--;
	res = (char*)malloc(sizeof(char) * (i + 2));
	if (!res)
		return (0);
	res[i + 1] = '\0';
	while (i >= 0)
	{
		res[i] = s[i];
		i--;
	}
	return (char*)(res);
}
