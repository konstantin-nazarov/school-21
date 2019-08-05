/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carpet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:31:21 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/07 15:24:37 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		pixel_carpet(t_fractal *fractal, int x, int y, int i)
{
	while ((x > 0 || y > 0) && ++i < fractal->it)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (0);
		x /= 3;
		y /= 3;
	}
	return (fractal->color.rgba);
}

void	out_carpet(t_system *mlx, t_fractal *fractal)
{
	int	x;
	int	y;

	clear_window(mlx);
	ft_bzero(mlx->re_img, sizeof(int) * (F_W * F_H));
	y = -1;
	while (++y < 729)
	{
		x = -1;
		while (++x < 729)
			if (y < 729)
				mlx->re_img[(y + 135) * F_W + (x + 385)] =
					pixel_carpet(fractal, x, y, -1);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, M_H + 1);
}

void	create_carpet(t_fractal *fractal, int width, int height)
{
	fractal->block_w = width / 3;
	fractal->block_h = height / 2;
	fractal->size = 1;
	fractal->sx = 1.5;
	fractal->sy = 1;
	fractal->dx = 0;
	fractal->dy = 0;
	fractal->z = 1.5;
	fractal->it = 4;
	fractal->psych = 0;
	fractal->color.rgba = 0x00FFFF;
}
