/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:12:20 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/06 18:28:47 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int			move_ms(int x, int y, t_struct *ms)
{
	float	tx;
	float	ty;
	int		temp;

	mini_window(*ms);
	if (y >= 250 && ms->id == 1 && ms->pause == 0)
	{
		tx = x / ms->fractal->block_w - 1.5;
		ty = 1 - (y - 250) / ms->fractal->block_h;
		if ((ms->fractal->z - (tx + ty) / 100) > -1
			&& (ms->fractal->z - (tx + ty) / 100) < 1)
			ms->fractal->z -= (tx + ty) / 100;
		ms->out[ms->id](ms->sys, ms->fractal);
	}
	if (y < M_H && (temp = x / M_W) >= 0)
	{
		y = -1;
		while (++y < M_H)
		{
			x = temp * M_W + temp;
			while (x < (temp + 1) * M_W + temp)
				mlx_pixel_put(ms->sys->mlx, ms->sys->win, x++, y, 0x96FFFFFF);
		}
	}
	return (0);
}

static void	refractal_ms(t_struct *ms, int x)
{
	ms->psych = 0;
	ms->shade = 0;
	ms->id = x / M_W + ((x / M_W >= ms->id) ? 1 : 0);
	ms->f[ms->id](ms->fractal, F_W, F_H);
	ms->out[ms->id](ms->sys, ms->fractal);
	mini_window(*ms);
}

static void	zoomneg(t_struct *ms, float x, float y)
{
	if (ms->id != 2)
	{
		support_neg(ms, x, y);
		ms->fractal->size *= 0.9;
		if (ms->psych == 1)
			ms->fractal->psych += (ms->fractal->psych == 255) ? 2 : 1;
		if (ms->shade == 1)
			ms->fractal->color.rgba += 100;
		ms->out[ms->id](ms->sys, ms->fractal);
	}
}

static void	zoompos(t_struct *ms, float x, float y)
{
	float temp;

	temp = 0;
	if (ms->id != 2 && ms->fractal->size <= 64 && y > 249)
	{
		support_pos(ms, x, y, temp);
		ms->fractal->size *= 1.1;
		if (ms->psych == 1)
			ms->fractal->psych -= (ms->fractal->psych == 1) ? 2 : 1;
		if (ms->shade == 1)
			ms->fractal->color.rgba -= 100;
		ms->out[ms->id](ms->sys, ms->fractal);
	}
}

int			process_ms(int key, int x, int y, t_struct *ms)
{
	if (y < M_H && key == 1)
		refractal_ms(ms, x);
	if (key == 4)
		zoomneg(ms, x, y);
	if (key == 5)
		zoompos(ms, x, y);
	return (0);
}
