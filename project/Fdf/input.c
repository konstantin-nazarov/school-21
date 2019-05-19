/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:40:30 by dhorker           #+#    #+#             */
/*   Updated: 2019/03/08 18:05:09 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				mouse_press(int key, int x, int y, t_inp *mouse)
{
	mouse->x = x;
	mouse->y = y;
	if (key == 1)
	{
		mouse->key = 1;
		mouse->x = x;
		mouse->y = y;
	}
	if (key == 2)
	{
		mouse->key = 2;
		mouse->x = x;
		mouse->y = y;
	}
	if (key == 3 && mouse->map->px > x && mouse->map->nx < x
	&& mouse->map->py > y && mouse->map->ny < y)
		mouse->key = 3;
	if (key == 4 && mouse->key == 0)
		zoomneg(mouse);
	if (key == 5 && mouse->key == 0)
		zoompos(mouse);
	return (key);
}

int				mouse_unpress(int key, int x, int y, t_inp *mouse)
{
	mouse->x = x;
	mouse->y = y;
	if (key == 1 && mouse->key != 2 && mouse->key != 3)
	{
		mouse->key = 0;
		mouse->x = 0;
		mouse->y = 0;
	}
	if (key == 2 && mouse->key != 1 && mouse->key != 3)
	{
		mouse->key = 0;
		mouse->x = 0;
		mouse->y = 0;
	}
	if (key == 3 && mouse->key != 1 && mouse->key != 2)
	{
		mouse->key = 0;
		mouse->x = 0;
		mouse->y = 0;
	}
	return (key);
}

int				key_press(int code, t_inp *key)
{
	F_IF(code == KLEFT || code == KRIGHT || code == KR || code == KY ||\
		code == KG || code == KC || code == KB || code == KP || code == KW\
		|| code == KO || code == KS,\
		create_grid(key->win, key->map, key->point, code));
	F_IF(code == KESC, exit(0));
	return (0);
}
