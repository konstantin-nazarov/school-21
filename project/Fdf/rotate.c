/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:40:53 by dhorker           #+#    #+#             */
/*   Updated: 2019/03/09 17:47:44 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			rot_z(t_fdf *m, t_point *p)
{
	int	x;
	int	y;

	x = p->x;
	y = p->y;
	p->x = m->cx + (x - m->cx) * cos(m->tz) - (y - m->cy) * sin(m->tz);
	p->y = m->cy + (x - m->cx) * sin(m->tz) + (y - m->cy) * cos(m->tz);
	if (m->px <= p->x)
		m->px = p->x;
	if (m->nx > p->x)
		m->nx = p->x;
	if (m->py <= p->y)
		m->py = p->y;
	if (m->ny > p->y)
		m->ny = p->y;
}

void			rot_y(t_fdf *map, t_point *p)
{
	int	x;
	int	z;

	x = p->x;
	z = p->oz;
	p->x = map->cx + (x - map->cx) * cos(map->ty) + z * sin(map->ty);
	p->oz = -((x - map->cx) * sin(map->ty)) + z * cos(map->ty);
	rot_z(map, p);
}

void			rot_x(t_fdf *map, t_point *p)
{
	int	y;
	int	z;

	y = p->y;
	z = p->z;
	z *= (map->gap != 0) ? map->gap : 1;
	p->y = map->cy + (y - map->cy) * cos(map->tx) + z * sin(map->tx);
	p->oz = -((y - map->cy) * sin(map->tx)) + z * cos(map->tx);
	rot_y(map, p);
}

void			rotate(t_system *win, t_fdf *map, t_point **p, int i)
{
	int	j;

	F_WH(++i < map->y && (j = -1), F_WH(++j < map->x, rot_x(map, &p[i][j])));
	output_grid(win, *map, p);
	SP(10, GRAY, "MOUSE");
	SP(50, GRAY, "      Left button - xz-rotate");
	SP(70, GRAY, "      Right button - y-rotate");
	SP(90, GRAY, "      Middle button - move");
	SP(110, GRAY, "      Scroll middle button - zoom");
	SP(160, GRAY, "KEYBOARD");
	SP(200, GRAY, "      Change basic color:");
	SP(220, RED, "      R - red");
	SP(240, YELLOW, "      y - yellow");
	SP(260, GREEN, "      G - green");
	SP(280, CYAN, "      C - cyan");
	SP(300, BLUE, "      B - blue");
	SP(320, PINK, "      P - pink");
	SP(340, WHITE, "      W - gray");
	SP(380, GRAY, "      Change transparency:");
	SP(400, GRAY, "      Left - max");
	SP(420, GRAY, "      Right - min");
	SP(460, GRAY, "      Back to default setting:");
	SP(480, GRAY, "      O - color");
	SP(500, GRAY, "      S - coordinates");
	SP(540, GRAY, "ESC - exit");
}

void			rerotate(t_inp *mouse, int x, int y)
{
	float		rad;

	rad = 3.1415926535 / 180;
	mouse->map->tx -= ((mouse->y > y) ? 2 : 0) * rad;
	mouse->map->tx += ((mouse->y < y) ? 2 : 0) * rad;
	mouse->y = y;
	mouse->map->tz -= ((mouse->x > x) ? 2 : 0) * rad;
	mouse->map->tz += ((mouse->x < x) ? 2 : 0) * rad;
	mouse->x = x;
	create_grid(mouse->win, mouse->map, mouse->point, 0);
}
