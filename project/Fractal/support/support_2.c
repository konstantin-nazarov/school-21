/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 18:02:24 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/06 18:23:22 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/*
**	Цвет пикселя для джулии и мандельброта
*/

int		color(t_fractal *fractal, int i)
{
	if (fractal->psych == 0)
	{
		fractal->color.u.r = i * 50;
		return (fractal->color.rgba);
	}
	else
	{
		fractal->color.rgba = 0x000000 +
			(0xFFFFFF / fractal->it * i) * fractal->psych;
		return (fractal->color.rgba);
	}
}

/*
** Вспомогательная для увеличения
*/

void	support_pos(t_struct *p, float x, float y, float t)
{
	if (p->id != 4)
	{
		t = x / p->fractal->block_w - p->fractal->sx;
		p->fractal->dx -= t * p->fractal->size - t * (p->fractal->size * 1.1);
	}
	else
	{
		t = ((x - (F_W / 2)) * 0.005 - 0.2);
		p->fractal->dx += t * p->fractal->size - t * (p->fractal->size * 1.1);
	}
	t = (y - 250) / p->fractal->block_h - p->fractal->sy;
	if (p->id != 1)
	{
		if (p->id != 4)
			t = 1 - (y - 250) / p->fractal->block_h;
		else
			t = (((y - 250) - (F_H / 2)) * 0.005 - 0.3);
		p->fractal->dy += t * p->fractal->size - t * (p->fractal->size * 1.1);
	}
	else
	{
		t = (y - 250) / p->fractal->block_h - p->fractal->sy;
		p->fractal->dy -= t * p->fractal->size - t * (p->fractal->size * 1.1);
	}
}

/*
** Вспомогательная для уменьшения
*/

void	support_neg(t_struct *p, float x, float y)
{
	float	t;

	if (p->id != 4)
	{
		t = x / p->fractal->block_w - p->fractal->sx;
		p->fractal->dx += t * (p->fractal->size * 0.9) - t * p->fractal->size;
	}
	else
	{
		t = ((x - (F_W / 2)) * 0.005 - 0.2);
		p->fractal->dx -= t * (p->fractal->size * 0.9) - t * p->fractal->size;
	}
	if (p->id != 1)
	{
		if (p->id != 4)
			t = 1 - (y - 250) / p->fractal->block_h;
		else
			t = (((y - 250) - (F_H / 2)) * 0.005 - 0.3);
		p->fractal->dy -= t * (p->fractal->size * 0.9) - t * p->fractal->size;
	}
	else
	{
		t = (y - 250) / p->fractal->block_h - p->fractal->sy;
		p->fractal->dy += t * (p->fractal->size * 0.9) - t * p->fractal->size;
	}
}

/*
** Man
*/

void	print_information(void)
{
	ft_putstr("	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n");
	ft_putstr("	Валидным аргументом является название фрактала:\n\n");
	ft_putstr("		mandelbrot, julia, carpet, newton, ship\n\n");
	ft_putstr("	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n");
	ft_putstr("	Мышь\n\n");
	ft_putstr("		Колесико - масштабирование\n\n");
	ft_putstr("	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n");
	ft_putstr("	Малая клавиатура\n\n");
	ft_putstr("		'+','-' - количество итераций\n");
	ft_putstr("		2,4,8,6 - перемещение\n");
	ft_putstr("		7,9 - смена психоделики\n");
	ft_putstr("		1,3 - смена цвета\n");
	ft_putstr("		',' - режим смены цвета при масштабировании\n");
	ft_putstr("		'enter' - режим психоделики при масштабировании\n");
	ft_putstr("		5 - обнулить цвета\n\n");
	ft_putstr("	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n");
	ft_putstr("	Большая клавиатура\n\n");
	ft_putstr("		1,2,3,4,5 - переключение фракталов\n");
	ft_putstr("		'esc' - закрыть программу\n");
	ft_putstr("		'space' - остановить julia\n\n");
	ft_putstr("	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n");
	ft_putstr("	Так же, фракталы переключаются в верхней части окна\n\n");
	ft_putstr("	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n");
}
