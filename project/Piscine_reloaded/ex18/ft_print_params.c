/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:36:00 by dhorker           #+#    #+#             */
/*   Updated: 2018/11/27 21:06:49 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putchar(char c);

int	main(int ac, char **av)
{
	int i;
	int j;

	i = 0;
	if (ac > 1)
	{
		while (++i <= ac - 1)
		{
			j = -1;
			while (av[i][++j])
				ft_putchar(av[i][j]);
			ft_putchar('\n');
		}
	}
}