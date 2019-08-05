/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_supp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:19:53 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/08 18:45:11 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	digit_number(int result)
{
	if (result < 0)
		return (digit_number(-result) + 1);
	if (result != 0)
		return (digit_number(result / 10) + 1);
	else
		return (0);
}

int	*valid_supp(int av, char **ac, int *check, int count)
{
	int	i;

	i = 0;
	while (++i < av)
	{
		while (*(ac[i]))
		{
			check = new_elem(check, ft_atoi(ac[i]), ++count);
			ac[i] += (check[count] == 0 && *(ac[i]) == '0')
				? 1 : digit_number(check[count]);
			if (*(ac[i]) && *(ac[i]) != ' ')
			{
				free(check);
				return (0);
			}
			if (*(ac[i]))
				ac[i]++;
		}
	}
	check[0] = count + 1;
	return (check);
}
