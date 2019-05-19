/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:22:49 by dhorker           #+#    #+#             */
/*   Updated: 2018/11/27 21:34:39 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int *mass;

	if (min > max || min == max)
		return (0);
	i = -1;
	mass = (int*)malloc(sizeof(*mass) * (max - min));
	while (++i < max - min)
		mass[i] = min + i;
	return (mass);
}
