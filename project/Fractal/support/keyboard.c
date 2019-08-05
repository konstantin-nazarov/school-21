/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:14:07 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/06 19:27:57 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/*
** Автоматическая смена цвета
*/

static void	autocolor(int key, t_struct *inp)
{
	if (inp->id != 2 && key == 76)
	{
		if (inp->psych == 0)
		{
			inp->psych = 1;
			inp->shade = 0;
			inp->fractal->color.rgba = 0x00FFFF;
		}
		else
			inp->psych = 0;
	}
	if (inp->id != 2 && key == 65)
	{
		if (inp->shade == 0)
		{
			inp->shade = 1;
			inp->psych = 0;
			inp->fractal->psych = 0;
			inp->fractal->color.rgba = 0x00FFFF;
		}
		else
			inp->shade = 0;
	}
}

/*
** Количество итераций
*/

static void	reiteration(int key, t_struct *inp)
{
	if (key == 69)
	{
		if (inp->id == 2 && inp->fractal->it < 6)
			inp->fractal->it++;
		else if (inp->id != 2)
			inp->fractal->it += 10;
	}
	else if (key == 78)
	{
		if (inp->fractal->it > 2 || (inp->fractal->it > 0 && inp->id == 2))
			inp->fractal->it -=
				(inp->fractal->it >= 12 && inp->id != 2) ? 10 : 1;
	}
	inp->out[inp->id](inp->sys, inp->fractal);
}

/*
** Перемещение изображения
*/

static void	reshift(int key, t_struct *inp)
{
	if (inp->id != 2 && inp->id != 3 && key == 91)
		inp->fractal->dy += 0.1;
	else if (inp->id != 2 && inp->id != 3 && key == 84)
		inp->fractal->dy -= 0.1;
	else if (inp->id != 2 && inp->id != 3 && key == 86)
		inp->fractal->dx += 0.1;
	else if (inp->id != 2 && inp->id != 3 && key == 88)
		inp->fractal->dx -= 0.1;
	inp->out[inp->id](inp->sys, inp->fractal);
}

/*
** Смена цвета
*/

static void	recolor(int key, t_struct *inp)
{
	if (inp->fractal->psych != 0)
		inp->fractal->color.rgba = 0x00FFFF;
	if (key == 87)
	{
		inp->fractal->psych = 0;
		inp->fractal->color.rgba = 0x00FFFF;
	}
	else if (inp->id != 2 && key == 89)
		inp->fractal->psych += (inp->fractal->psych == 255) ? 2 : 1;
	else if (inp->id != 2 && key == 92)
		inp->fractal->psych -= (inp->fractal->psych == 1) ? 2 : 1;
	else if (key == 83)
	{
		inp->fractal->psych = 0;
		inp->fractal->color.rgba -= 1000;
	}
	else if (key == 85)
	{
		inp->fractal->psych = 0;
		inp->fractal->color.rgba += 1000;
	}
	inp->out[inp->id](inp->sys, inp->fractal);
}

int			process_brd(int key, t_struct *inp)
{
	if (inp->id == 1 && key == 49)
		inp->pause = (inp->pause == 0) ? 1 : 0;
	else if (key == 53)
		ft_close(inp);
	else if (key == 76 || key == 65)
		autocolor(key, inp);
	else if (key == 18 || key == 19 || key == 20 || key == 21 || key == 23)
		refractal_brd(key, inp);
	else if (key == 87 || key == 89 || key == 92 || key == 83 || key == 85)
		recolor(key, inp);
	else if (key == 69 || key == 78)
		reiteration(key, inp);
	else if (key == 91 || key == 84 || key == 86 || key == 88)
		reshift(key, inp);
	return (0);
}
