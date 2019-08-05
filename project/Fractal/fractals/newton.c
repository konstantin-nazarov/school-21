/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:39:39 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/07 15:23:44 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		pixel_newton(t_fractal *fractal, float x, float y, char win)
{
	double	z[2];
	double	d[2];
	double	t[2];
	double	p;
	int		i;

	i = -1;
	z[0] = (x - (((win == 'F') ? F_W : M_W) / 2)) * 0.005 * fractal->size;
	z[1] = (y - (((win == 'F') ? F_H : M_H) / 2)) * 0.005 * fractal->size;
	d[0] = z[0];
	d[1] = z[1];
	while ((pow(z[0], 2) + pow(z[1], 2)) < 1000000
		&& (pow(d[0], 2) + pow(d[1], 2)) > 0.000001 && ++i < fractal->it)
	{
		t[0] = z[0];
		t[1] = z[1];
		p = pow(pow(t[0], 2) + pow(t[1], 2), 2);
		z[0] = 2 / 3 * t[0] + (pow(t[0], 2) - pow(t[1], 2)) / (3 * p);
		z[1] = 2 / 3 * t[1] * (1 - t[0] / p);
		d[0] = fabs(t[0] - z[0]);
		d[1] = fabs(t[1] - z[1]);
	}
	return (color(fractal, i));
}

void	out_newton(t_system *mlx, t_fractal *fractal)
{
	int	x;
	int	y;

	clear_window(mlx);
	y = -1;
	while (++y < F_H)
	{
		x = -1;
		while (++x < F_W)
			mlx->re_img[y * F_W + x] = pixel_newton(fractal, x, y, 'F');
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, M_H + 1);
}

void	create_newton(t_fractal *fractal, int width, int height)
{
	fractal->block_w = width / 3;
	fractal->block_h = height / 2;
	fractal->size = 1;
	fractal->sx = 1.5;
	fractal->sy = 1;
	fractal->dx = 0;
	fractal->dy = 0;
	fractal->it = 50;
	fractal->psych = 0;
	fractal->color.rgba = 0x00FFFF;
}
