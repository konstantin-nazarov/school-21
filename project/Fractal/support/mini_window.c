/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:14:25 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/06 18:28:34 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	support(t_struct *strct, int i)
{
	int	x;
	int	y;

	y = -1;
	if (i == 2)
	{
		while (++y < 243)
		{
			x = -1;
			while (++x < 243)
				if (y < 243)
					strct->sys->mini_img[(y + 3) * M_W + (x + 66)] =
						pixel_carpet(strct->mini, x, y, -1);
		}
	}
	else
		while (++y < M_H)
		{
			x = -1;
			while (++x < M_W)
				strct->sys->mini_img[y * 375 + x] =
					strct->pixel[i](strct->mini, x, y, 'M');
		}
}

void		mini_window(t_struct strct)
{
	int	i;
	int	ind;

	i = -1;
	ind = -M_W - 1;
	while (++i < 5)
		if (i != strct.id)
		{
			strct.f[i](strct.mini, M_W, M_H);
			strct.mini->it = 30;
			if (i == 4)
			{
				strct.mini->size = 0.08;
				strct.mini->dx = -1.73;
				strct.mini->dy = -0.01;
			}
			strct.mini->color.rgba = 0xAAFF00 + i * 100000;
			ft_bzero(strct.sys->mini_img, sizeof(int) * M_W * M_H);
			support(&strct, i);
			mlx_put_image_to_window(strct.sys->mlx, strct.sys->win,
				strct.sys->m_img, ind += M_W + 1, 0);
		}
}
