/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:53:31 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/21 14:42:11 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *str;

	str = s1;
	while (*(str))
		str++;
	while (*(s2))
		*(str++) = *(s2++);
	*(str) = '\0';
	return (s1);
}
