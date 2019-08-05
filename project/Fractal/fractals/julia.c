/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 17:28:28 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/07 15:23:41 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		pixel_julia(t_fractal *fractal, float x, float y, char win)
{
	float	cx;
	float	cy;
	float	temp;
	int		i;

	win = 0;
	i = -1;
	cx = (x / fractal->block_w - fractal->sx) * fractal->size - fractal->dx;
	cy = (fractal->sy - y / fractal->block_h) * fractal->size + fractal->dy;
	while ((temp = cx * cx + cy * cy) <= 4 && ++i < fractal->it)
	{
		temp = cx * cx - cy * cy;
		cy = 2 * cx * cy + fractal->z;
		cx = temp + fractal->z;
	}
	if (temp > 4)
		return (color(fractal, (i < 1) ? 1 : i));
	return (0x99FF99);
}

void	out_julia(t_system *mlx, t_fractal *fractal)
{
	int	x;
	int	y;

	clear_window(mlx);
	y = -1;
	while (++y < F_H)
	{
		x = -1;
		while (++x < F_W)
			mlx->re_img[y * F_W + x] = pixel_julia(fractal, x, y, 'F');
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, M_H + 1);
}

void	create_julia(t_fractal *fractal, int width, int height)
{
	fractal->block_w = width / 3;
	fractal->block_h = height / 2;
	fractal->size = 1.5;
	fractal->sx = 1.5;
	fractal->sy = 1;
	fractal->dx = 0;
	fractal->dy = 0;
	fractal->z = -0.52;
	fractal->it = 50;
	fractal->psych = 0;
	fractal->color.rgba = 0x00FFFF;
}
