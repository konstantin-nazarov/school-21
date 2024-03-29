/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 20:45:40 by dhorker           #+#    #+#             */
/*   Updated: 2018/11/25 21:04:38 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int	i;

	i = -1;
	while (++i <= 46340)
	{
		if (nb == i * i)
			return (i);
	}
	return (0);
}
