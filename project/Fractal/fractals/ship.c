/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:54:57 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/07 15:23:51 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		pixel_ship(t_fractal *fractal, float x, float y, char win)
{
	double	c[2];
	double	z[2];
	double	t[2];
	int		i;

	i = -1;
	c[0] = ((x - (((win == 'F') ? F_W : M_W) / 2)) * 0.005 - 0.2) *
		fractal->size + fractal->dx;
	c[1] = ((y - (((win == 'F') ? F_H : M_H) / 2)) * 0.005 - 0.3) *
		fractal->size + fractal->dy;
	z[0] = 0;
	z[1] = 0;
	while (pow(z[0], 2) + pow(z[1], 2) < 30 && ++i < fractal->it)
	{
		t[0] = z[0];
		t[1] = z[1];
		z[0] = pow(t[0], 2) - pow(t[1], 2) + c[0];
		z[1] = 2 * fabs(t[0] * t[1]) + c[1];
	}
	if (i < fractal->it)
		return (color(fractal, i));
	return (0x000000);
}

void	out_ship(t_system *mlx, t_fractal *fractal)
{
	int	x;
	int	y;

	clear_window(mlx);
	y = -1;
	while (++y < F_H)
	{
		x = -1;
		while (++x < F_W)
			mlx->re_img[y * F_W + x] = pixel_ship(fractal, x, y, 'F');
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, M_H + 1);
}

void	create_ship(t_fractal *fractal, int width, int height)
{
	fractal->block_w = width / 3;
	fractal->block_h = height / 2;
	fractal->size = 0.02;
	fractal->sx = 1.5;
	fractal->sy = 1;
	fractal->dx = -1.75;
	fractal->dy = -0.03;
	fractal->it = 30;
	fractal->psych = 0;
	fractal->color.rgba = 0x00FFFF;
}
