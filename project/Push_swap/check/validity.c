/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:22:22 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/08 18:35:34 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*new_elem(int *old, int num, int size)
{
	int	*new;
	int	i;

	if (!(new = (int*)malloc(sizeof(int) * (size + 1))))
		return (0);
	i = 0;
	if (size > 1)
	{
		while (++i < size)
			new[i] = old[i];
		free(old);
	}
	new[(i == 0) ? 1 : i] = num;
	return (new);
}

static int	check_repeat(int *check)
{
	int	i;
	int	j;

	i = 0;
	while (++i < check[0])
	{
		j = 0;
		while (++j < i)
			if (check[i] == check[j])
				return (0);
	}
	return (1);
}

int	*check_valid(int av, char **ac)
{
	int	*check;

	if (av < 2)
		return (0);
	if (!(check = valid_supp(av, ac, check, 0)))
		return (0);
	if (!(check_repeat(check)))
	{
		free(check);
		return (0);
	}
	return (check);
}
