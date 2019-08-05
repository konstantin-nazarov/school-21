/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:23:21 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/08 18:35:33 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(int *check)
{
	int				i;
	unsigned char	rhesus;

	i = 0;
	if (check[0] > 2)
		rhesus = (check[1] < check[2]) ? 1 : 0;
	while (++i < check[0] - 1)
	{
		if (rhesus == 1 && check[i] > check[i + 1])
			return (0);
		if (rhesus == 0 && check[i] < check[i + 1])
			return (0);
	}
	return (1);
}
