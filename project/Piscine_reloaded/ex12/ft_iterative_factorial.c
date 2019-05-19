/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 19:32:01 by dhorker           #+#    #+#             */
/*   Updated: 2018/11/28 19:50:50 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int	f;

	if (nb == 0 || nb == 1)
		return (1);
	else if (nb >= 13 || nb < 0)
		return (0);
	f = 0;
	while (nb >= 2)
	{
		if (f == 0)
			f = nb--;
		else
			f *= nb--;
	}
	return (f);
}
