/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:41:01 by dhorker           #+#    #+#             */
/*   Updated: 2019/03/09 16:54:34 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			re_y(t_inp *mouse, int x)
{
	float		rad;

	rad = 3.1415926535 / 180;
	mouse->map->ty -= ((mouse->x > x) ? 2 : 0) * rad;
	mouse->map->ty += ((mouse->x < x) ? 2 : 0) * rad;
	mouse->x = x;
	create_grid(mouse->win, mouse->map, mouse->point, 0);
}

void			recoor(t_inp *mouse, int *x, int *y)
{
	mouse->map->sx -= mouse->x - *x;
	mouse->map->cx -= mouse->x - *x;
	mouse->map->nx -= mouse->x - *x;
	mouse->map->px -= mouse->x - *x;
	mouse->x = *x;
	mouse->map->sy -= mouse->y - *y;
	mouse->map->cy -= mouse->y - *y;
	mouse->map->ny -= mouse->y - *y;
	mouse->map->py -= mouse->y - *y;
	mouse->y = *y;
}

void			zoompos(t_inp *ms)
{
	ms->map->gap += 1;
	ms->map->sx = ms->map->cx - (ms->map->gap * (ms->map->x - 1) / 2);
	ms->map->sy = ms->map->cy - (ms->map->gap * (ms->map->y - 1) / 2);
	create_grid(ms->win, ms->map, ms->point, 0);
}

void			zoomneg(t_inp *ms)
{
	if (ms->map->gap > 1)
	{
		ms->map->gap -= 1;
		ms->map->sx += (ms->map->x - 1) / 2;
		ms->map->sy += (ms->map->y - 1) / 2;
		ms->map->nx += (ms->map->x - 1) / 2;
		ms->map->px -= (ms->map->x - 1) / 2;
		ms->map->ny += (ms->map->y - 1) / 2;
		ms->map->py -= (ms->map->y - 1) / 2;
		if (ms->map->nx >= P_W - 30)
			ms->map->sx = P_W - 30 + (ms->map->sx - ms->map->nx);
		if (ms->map->ny >= P_H - 30)
			ms->map->sy = P_H - 30 + (ms->map->sy - ms->map->ny);
		if (ms->map->px <= 430)
			ms->map->sx = 430 - (ms->map->px - ms->map->sx);
		if (ms->map->py <= 30)
			ms->map->sy = 30 - (ms->map->py - ms->map->sy);
	}
	create_grid(ms->win, ms->map, ms->point, 0);
}

int				move_map(int x, int y, t_inp *mouse)
{
	if (mouse->key == 1)
		rerotate(mouse, x, y);
	if (mouse->key == 2)
		re_y(mouse, x);
	if (mouse->key == 3)
	{
		recoor(mouse, &x, &y);
		if (mouse->map->nx >= P_W - 30)
			mouse->map->sx = P_W - 30 + (mouse->map->sx - mouse->map->nx);
		if (mouse->map->ny >= P_H - 30)
			mouse->map->sy = P_H - 30 + (mouse->map->sy - mouse->map->ny);
		if (mouse->map->px <= 430)
			mouse->map->sx = 430 - (mouse->map->px - mouse->map->sx);
		if (mouse->map->py <= 30)
			mouse->map->sy = 30 - (mouse->map->py - mouse->map->sy);
		create_grid(mouse->win, mouse->map, mouse->point, 0);
	}
	return (0);
}
