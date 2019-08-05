/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16:59:16 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/08 18:36:04 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int av, char **ac)
{
	int	*check;
	int i;

	if (!(check = check_valid(av, ac)))
	{
		ft_putstr_fd("error\n", 2);
		return (0);
	}
	if (!(check_sort(check)))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	free(check);
	return (0);
}
