/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:21:14 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/12 20:11:08 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		ft_close(t_key *key)
{
	free(key->fractal);
	exit(0);
	return (0);
}

int		color_pix(t_fractal *malde, float x, float y, int i)
{
	float	x0;
	float	y0;
	float	anc;
	int		c;

	if (x / malde->block_w == 0.0)
	c = 0xFFFFFF / malde->it;
	x0 = (x / malde->block_w - malde->cX) * malde->size;
	y0 = (1 - y / malde->block_h) * malde->size;
	x = 0;
	y = 0;
	while (++i <= malde->it && x * x + y * y <= 4)
	{
		anc = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = anc;
	}
	if (x0 * x0 + y0 * y0 <= 4)
		return (0xFFFFFF - c * i);
	return (0x000000);
}

void	out_fractal(t_system *mlx, t_fractal *frac)
{
	int			x;
	int			y;

	mlx_clear_window(mlx->mlx, mlx->win);
	ft_bzero(mlx->re_img, sizeof(int) * P_W * P_H);
	y = -1;
	while (++y < P_H)
	{
		x = -1;
		while (++x < P_W)
			mlx->re_img[y * P_W + x] = color_pix(frac, x, y, 0);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

int	process_key(int key, t_key *inp)
{
	if (key == 53)
		ft_close(inp);
	if (key == 126)
	{
		inp->fractal->it++;
		out_fractal(inp->sys, inp->fractal);
	}
	if (key == 125)
	{
		if (inp->fractal->it > 2)
		{
			(inp->fractal->it)--;
			out_fractal(inp->sys, inp->fractal);
		}
	}
	return (0);
}

void	zoomneg(t_key *ms, float x, float y)
{
	if (ms->fractal->size <= 4)
	{
		ms->fractal->size *= 0.9;
		ms->fractal->cX = (x / ms->fractal->block_w - 2);
		ms->fractal->cY = (1 - y / ms->fractal->block_h) * ms->fractal->size;
		out_fractal(ms->sys, ms->fractal);
	}
}

void	zoompos(t_key *ms, float x, float y)
{
	ms->fractal->size *= 1.1;
	ms->fractal->cX = (x / ms->fractal->block_w - 2);
	ms->fractal->cY = (1 - y / ms->fractal->block_h);
	out_fractal(ms->sys, ms->fractal);
}

int	process_ms(int key, int x, int y, t_key *ms)
{
	if (key == 1)
		zoomneg(ms, x, y);
	if (key == 2)
		zoompos(ms, x, y);
	return (0);
}

void	create_malde(t_fractal *malde)
{
	malde->block_w = P_W / 3;
	malde->block_h = P_H / 2;
	malde->size = 0.8;
	malde->cX = 2;
	malde->cY = 1;
	malde->it = 50;
}

void	fractal(t_key *key)
{
	t_fractal	*frac;

	frac = (t_fractal*)malloc(sizeof(t_fractal));
	create_malde(frac);
	key->fractal = frac;
	out_fractal(key->sys, frac);
}

void	create_mlx(t_system *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, P_W, P_H, "Fractal");
	mlx->img = mlx_new_image(mlx->mlx, P_W, P_H);
	mlx->b_img = 32;
	mlx->l_img = P_W;
	mlx->e_img = 1;
	mlx->re_img = (unsigned int*)mlx_get_data_addr(mlx->img, &mlx->b_img, &mlx->l_img, &mlx->e_img);
}

int		main()
{
	t_system	mlx;
	t_key		key;

	create_mlx(&mlx);
	key.sys = &mlx;
	fractal(&key);
	mlx_hook(mlx.win, 2, 0, process_key, &key);
	mlx_hook(mlx.win, 4, 0, process_ms, &key);
	mlx_hook(mlx.win, 17, 0, ft_close, &key);
	mlx_loop(mlx.mlx);
	return (0);
}
