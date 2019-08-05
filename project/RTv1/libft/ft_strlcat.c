/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:07:25 by krakharo          #+#    #+#             */
/*   Updated: 2018/11/21 18:36:19 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		siz;
	size_t		l_dst;
	size_t		i;

	siz = n;
	s = src;
	d = dst;
	i = 0;
	while (siz-- != 0 && *d != 0)
		d++;
	l_dst = d - dst;
	siz = n - l_dst;
	while (s[i] != '\0')
		i++;
	if (siz == 0)
		return (l_dst + i);
	s--;
	while (*++s != '\0')
		if (siz != 1 && siz--)
			*d++ = *s;
	*d = '\0';
	return (l_dst + (s - src));
}
