/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_n_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:41:18 by dhorker           #+#    #+#             */
/*   Updated: 2019/03/09 16:04:53 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned		nc(t_argb p1, t_argb p2, int l, int i)
{
	t_argb		new;

	new.argb = 0;
	F_IF(l <= 0, l = abs(l) + 1);
	if (i == -1 && (i = 200))
	{
		F_IF(p1.argb == RED, p1.argb = 0x0A0000);
		F_IF(p1.argb == YELLOW, p1.argb = 0x0A0A00);
		F_IF(p1.argb == GREEN, p1.argb = 0x000A00);
		F_IF(p1.argb == CYAN, p1.argb = 0x000A0A);
		F_IF(p1.argb == BLUE, p1.argb = 0x00000A);
		F_IF(p1.argb == PINK, p1.argb = 0x0A000A);
		F_IF(p1.argb == WHITE, p1.argb = BLACK);
	}
	ARGB(a, new);
	ARGB(r, new);
	ARGB(g, new);
	ARGB(b, new);
	return (new.argb);
}

t_point			**change_color(t_system win, t_point **m, t_fdf *map, int k)
{
	int			i;
	int			j;

	j = -1;
	while ((i = -1) && ++j < map->y)
		while (++i < map->x)
			if (k != KLEFT && k != KRIGHT && k != KO && k != KS)
			{
				F_IF(k == KR, m[j][i].c.argb = RED);
				F_IF(k == KY, m[j][i].c.argb = YELLOW);
				F_IF(k == KG, m[j][i].c.argb = GREEN);
				F_IF(k == KC, m[j][i].c.argb = CYAN);
				F_IF(k == KB, m[j][i].c.argb = BLUE);
				F_IF(k == KP, m[j][i].c.argb = PINK);
				F_IF(k == KW, m[j][i].c.argb = WHITE);
				m[j][i].c.argb = nc(m[j][i].c, m[j][i].c, m[j][i].z, -1);
			}
			else
			{
				F_IF(k == KLEFT, F_IF(M_A >= 15, M_A -= 15));
				F_IF(k == KRIGHT, F_IF(M_A <= 240, M_A += 15));
				F_IF(k == KO, m[j][i].c.argb = m[j][i].tmp_c.argb);
				F_IF(k == KS, create_map(win, map));
			}
	return (m);
}

void			output_grid(t_system *win, t_fdf map, t_point **point)
{
	int			i;
	int			j;

	mlx_clear_window(win->mlx, win->win);
	ft_bzero((int*)win->rem_i, sizeof(int) * win->x * win->y);
	i = -1;
	while (++i < map.y)
	{
		j = -1;
		while (++j < map.x)
		{
			if (j < map.x - 1)
				line(win, point[i][j], point[i][j + 1]);
			if (i < map.y - 1)
				line(win, point[i][j], point[i + 1][j]);
		}
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
}

void			create_grid(t_system *win, t_fdf *map, t_point **point, int key)
{
	int	i;
	int	j;

	F_IF(key, point = change_color(*win, point, map, key));
	map->cx = map->sx + (map->gap * (map->x - 1)) / 2;
	map->cy = map->sy + (map->gap * (map->y - 1)) / 2;
	map->px = map->cx;
	map->nx = map->cx;
	map->py = map->cy;
	map->ny = map->cy;
	point[0][0].x = map->sx;
	point[0][0].y = map->sy;
	i = -1;
	while (++i < map->y - 1 && (j = -1))
		while (++j < map->x - 1)
		{
			point[i][j + 1].x = point[i][j].x + map->gap;
			point[i][j + 1].y = point[i][j].y;
			point[i + 1][j].x = point[i][j].x;
			point[i + 1][j].y = point[i][j].y + map->gap;
		}
	point[i][j].x = point[i][j - 1].x + map->gap;
	point[i][j].y = point[i][j - 1].y;
	rotate(win, map, point, -1);
}
