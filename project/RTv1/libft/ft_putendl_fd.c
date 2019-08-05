/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 01:44:20 by krakharo          #+#    #+#             */
/*   Updated: 2018/11/23 01:44:22 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t	i;
	char	c;

	c = '\n';
	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
		i++;
	write(fd, s, i);
	write(fd, &c, 1);
}
