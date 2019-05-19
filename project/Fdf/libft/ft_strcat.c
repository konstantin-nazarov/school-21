/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:39:16 by ccolemon          #+#    #+#             */
/*   Updated: 2018/12/22 18:28:25 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destination, const char *append)
{
	char	*dest;

	dest = &destination[ft_strlen(destination)];
	while ((*dest++ = *append++))
		;
	return (destination);
}
