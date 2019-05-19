/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:03:14 by dhorker           #+#    #+#             */
/*   Updated: 2018/11/27 21:23:50 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dup;

	i = -1;
	len = ft_strlen(src);
	dup = (char*)malloc(sizeof(*dup) * (len + 1));
	while (++i < len)
		dup[i] = src[i];
	dup[i] = '\0';
	return (dup);
}
