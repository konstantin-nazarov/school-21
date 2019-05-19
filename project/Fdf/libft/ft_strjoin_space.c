/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:45:07 by ccolemon          #+#    #+#             */
/*   Updated: 2019/02/21 20:53:44 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_space(char const *s1, char const *s2)
{
	size_t		l;
	char		*str;
	char		*st;

	if (!s1 || !s2)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2) + 2;
	if (!(str = ft_strnew(l)))
		return (NULL);
	st = str;
	while (*s1)
		*str++ = *s1++;
	*str++ = ' ';
	while (*s2)
		*str++ = *s2++;
	*str++ = ' ';
	return (st);
}
