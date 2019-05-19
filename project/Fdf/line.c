/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:40:58 by dhorker           #+#    #+#             */
/*   Updated: 2019/03/08 18:48:16 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			rememory_img(t_system *win, int x, int y, unsigned int nc)
{
	unsigned int	*img;

	img = (unsigned int*)win->rem_i;
	img[y * P_W + x] = nc;
}

void			easyline(t_system *w, t_point p1, t_point p2, t_line s)
{
	int l;

	l = LEN_LINE ? LEN_LINE + 2 : 1;
	if (p1.x == p2.x)
	{
		if (p1.y > p2.y)
			ft_swap(&p1.y, &p2.y);
		p1.y--;
		while (++p1.y <= p2.y)
			if (p1.y < P_H && p1.y > 0 && p1.x < P_W && p1.x > 400)
				rememory_img(w, p1.x, p1.y, nc(p1.c, p2.c, s.l, ++s.i));
	}
	else
	{
		if (p1.x > p2.x)
			ft_swap(&p1.x, &p2.x);
		p1.x--;
		while (++p1.x <= p2.x)
			if (p1.y < P_H && p1.y > 0 && p1.x < P_W && p1.x > 400)
				rememory_img(w, p1.x, p1.y, nc(p1.c, p2.c, s.l, ++s.i));
	}
}

void			descent(t_system *w, t_line s, t_point p1, t_point p2)
{
	t_point	swap;

	if (p2.x < p1.x)
	{
		swap = p1;
		p1 = p2;
		p2 = swap;
	}
	s.ratio = (float)(p2.y - p1.y) / (p2.x - p1.x);
	s.sh = p1.y + s.ratio;
	if ((s.x = p1.x) && p1.x < P_W && p1.x > 400 && p1.y < P_H && p1.y > 0)
		rememory_img(w, p1.x, p1.y, p1.c.argb);
	while (s.x++ < p2.x)
	{
		if (s.sh + 1 < P_H && s.sh + 1 > 0 && s.x < P_W && s.x > 400)
		{
			rememory_img(w, s.x, s.sh + 1,
				op(nc(p1.c, p2.c, s.l, ++s.i), 255 - fac(s.sh)));
			rememory_img(w, s.x, s.sh,
				op(nc(p1.c, p2.c, s.l, s.i), fac(s.sh)));
		}
		s.sh += s.ratio;
	}
	if (p2.x < P_W && p2.x > 400 && p2.y < P_H && p2.y > 0)
		rememory_img(w, p2.x, p2.y, p2.c.argb);
}

void			rise(t_system *w, t_line s, t_point p1, t_point p2)
{
	t_point	swap;

	if (p2.y < p1.y)
	{
		swap = p1;
		p1 = p2;
		p2 = swap;
	}
	s.ratio = (float)(p2.x - p1.x) / (p2.y - p1.y);
	s.sh = p1.x + s.ratio;
	if ((s.y = p1.y) && p1.x < P_W && p1.x > 400 && p1.y < P_H && p1.y > 0)
		rememory_img(w, p1.x, p1.y, p1.c.argb);
	while (s.y++ < p2.y)
	{
		if (s.sh + 1 < P_W && s.sh + 1 > 400 && s.y < P_H && s.y > 0)
		{
			rememory_img(w, s.sh + 1, s.y,
				op(nc(p1.c, p2.c, s.l, ++s.i), 255 - fac(s.sh)));
			rememory_img(w, s.sh, s.y,
				op(nc(p1.c, p2.c, s.l, s.i), fac(s.sh)));
		}
		s.sh += s.ratio;
	}
	if (p2.x < P_W && p2.x > 400 && p2.y < P_H && p2.y > 0)
		rememory_img(w, p2.x, p2.y, p2.c.argb);
}

void			line(t_system *win, t_point p1, t_point p2)
{
	t_line	set;

	set.l = LEN_LINE ? LEN_LINE + 2 : 1;
	set.dx = (p1.x < p2.x) ? p2.x - p1.x : p1.x - p2.x;
	set.dy = (p1.y < p2.y) ? p2.y - p1.y : p1.y - p2.y;
	set.i = -1;
	if (set.dx == 0 || set.dy == 0)
	{
		easyline(win, p1, p2, set);
		return ;
	}
	if (set.dy < set.dx)
		descent(win, set, p1, p2);
	else
		rise(win, set, p1, p2);
}
