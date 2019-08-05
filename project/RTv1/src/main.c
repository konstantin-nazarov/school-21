/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:32:04 by krakharo          #+#    #+#             */
/*   Updated: 2019/06/20 17:34:38 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

int				main(int argc, char **argv)
{
	t_mlx	mlx;

	if ((argc != 2) || (ft_init(&mlx, argv[1]) == -1))
	{
		ft_putendl("usage: ./RTv1 input_file");
		return (0);
	}
	ft_help();
	if (ft_draw(&mlx) == -1)
		return (0);
	mlx_loop(mlx.mlx);
	return (0);
}
