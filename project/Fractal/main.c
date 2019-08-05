/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:22:52 by dhorker           #+#    #+#             */
/*   Updated: 2019/07/01 19:09:58 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	create_output_list(void (*f[5])(t_system*, t_fractal*))
{
	f[0] = &out_julia;
	f[1] = &out_julia;
	f[2] = &out_carpet;
	f[3] = &out_newton;
	f[4] = &out_ship;
}

void	create_fractal_list(void (*f[5])(t_fractal*, int, int))
{
	f[0] = &create_mandelbrot;
	f[1] = &create_julia;
	f[2] = &create_carpet;
	f[3] = &create_newton;
	f[4] = &create_ship;
}

void	create_pixel_list(int (*f[5])(t_fractal*, float, float, char))
{
	f[0] = &pixel_julia;
	f[1] = &pixel_julia;
	f[3] = &pixel_newton;
	f[4] = &pixel_ship;
}

int		check_arg(int av, char **ac)
{
	if (av != 2)
		return (-1);
	if (!ft_strcmp("mandelbrot", ac[1]))
		return (0);
	else if (!ft_strcmp("julia", ac[1]))
		return (1);
	else if (!ft_strcmp("carpet", ac[1]))
		return (2);
	else if (!ft_strcmp("newton", ac[1]))
		return (3);
	else if (!ft_strcmp("ship", ac[1]))
		return (4);
	else if (!ft_strcmp("man", ac[1]))
		return (5);
	return (-1);
}

int		main(int av, char **ac)
{
	t_system	mlx;
	t_struct	strct;
	int			id;

	if (av != 2 || (id = check_arg(av, ac)) == -1)
	{
		ft_putstr("Неверный ввод. Ознакомьтесь с возможностями ");
		ft_putstr("программы - ./fractal man\n");
	}
	else
	{
		if (id == 5)
		{
			print_information();
			return (0);
		}
		create_struct(&mlx, &strct, id);
	}
	return (0);
}
