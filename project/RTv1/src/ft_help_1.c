/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:17:11 by krakharo          #+#    #+#             */
/*   Updated: 2019/06/17 16:17:13 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

void		ft_hud(t_mlx *mlx)
{
	char	*s1;
	char	*s2;

	if (mlx->hud == 1)
	{
		if (mlx->aa == 1)
		{
			s1 = NULL;
			mlx_ps(mlx, 0, 0, "anti-aliasing: off");
		}
		else
		{
			s1 = ft_strjoinl("anti-aliasing: x", ft_itoa(mlx->aa), 'R');
			mlx_ps(mlx, 0, 0, s1);
			free(s1);
		}
		s2 = ft_strjoinl("reflection: ", ft_itoa(mlx->maxref), 'R');
		mlx_ps(mlx, 0, 20, s2);
		free(s2);
		if (mlx->spec == 1)
			mlx_ps(mlx, 0, 40, "blink: on");
		else
			mlx_ps(mlx, 0, 40, "blink: off");
	}
}

void		ft_help(void)
{
	ft_putendl("WASD: move");
	ft_putendl("<^>v: rotate x/y");
	ft_putendl("9/6 (num): rotate z axis");
	ft_putendl("LEFT click: select object");
	ft_putendl("ENTER: unselect object");
	ft_putendl("+/- (num): move z axis");
	ft_putendl("+/-: change size");
	ft_putendl("G: Blink");
	ft_putendl("R/F: +/- reflections");
	ft_putendl("TAB: hide/show HUD");
	ft_putendl("ESC: exit");
}

int			ft_last_hook(int keycode, t_mlx *mlx)
{
	double	tmp_rot;
	t_obj	*tmp;

	tmp = mlx->tmp;
	if (keycode == KEY_NUM_9 && tmp->type != 4 && \
		(tmp_rot = tmp->rot.x) < 6000.0)
	{
		tmp->rot.x = tmp->rot.x * cosf(0.5) + tmp->rot.y * (-sinf(0.5));
		tmp->rot.y = tmp_rot * sinf(0.5) + tmp->rot.y * cosf(0.5);
	}
	if (keycode == KEY_NUM_6 && tmp->type != 4 && \
		(tmp_rot = tmp->rot.x) > -6000.0)
	{
		tmp->rot.x = tmp->rot.x * cosf(-0.5) + tmp->rot.y * (-sinf(-0.5));
		tmp->rot.y = tmp_rot * sinf(-0.5) + tmp->rot.y * cosf(-0.5);
	}
	return (0);
}

int			ft_objects_rot(int key, t_mlx *mlx)
{
	double	tmp_rot;
	t_obj	*tmp;

	tmp = mlx->tmp;
	if (key == KEY_LEFT && tmp->type != 4 && (tmp_rot = tmp->rot.x) < 6000.0)
	{
		tmp->rot.x = tmp->rot.x * cosf(0.5) + tmp->rot.z * sinf(0.5);
		tmp->rot.z = tmp_rot * (-sinf(0.5)) + tmp->rot.z * cosf(0.5);
	}
	if (key == KEY_RIGHT && tmp->type != 4 && (tmp_rot = tmp->rot.x) > -6000.0)
	{
		tmp->rot.x = tmp->rot.x * cosf(-0.5) + tmp->rot.z * sinf(-0.5);
		tmp->rot.z = tmp_rot * (-sinf(-0.5)) + tmp->rot.z * cosf(-0.5);
	}
	if (key == KEY_DOWN && tmp->type != 4 && (tmp_rot = tmp->rot.y) > -6000.0)
	{
		tmp->rot.y = tmp->rot.y * cosf(-0.5) + tmp->rot.z * (-sinf(-0.5));
		tmp->rot.z = tmp_rot * sinf(-0.5) + tmp->rot.z * cosf(-0.5);
	}
	if (key == KEY_UP && tmp->type != 4 && (tmp_rot = tmp->rot.y) < 6000.0)
	{
		tmp->rot.y = tmp->rot.y * cosf(0.5) + tmp->rot.z * (-sinf(0.5));
		tmp->rot.z = tmp_rot * sinf(0.5) + tmp->rot.z * cosf(0.5);
	}
	return (ft_last_hook(key, mlx));
}

double		*ft_endlight(t_obj *tmp, t_obj *light, double *tab, double d)
{
	tab[3] = ft_clamp(tab[3] * 4.0 * d, 0.0, 1.0);
	tab[0] += tab[3] * (tmp->col.red / 255) * (light->col.red / 255);
	tab[1] += tab[3] * (tmp->col.green / 255) * (light->col.green / 255);
	tab[2] += tab[3] * (tmp->col.blue / 255) * (light->col.blue / 255);
	return (tab);
}
