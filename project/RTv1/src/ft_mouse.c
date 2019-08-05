/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:32:11 by krakharo          #+#    #+#             */
/*   Updated: 2019/06/17 15:32:13 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

int				ft_parameters(int keycode, t_mlx *mlx, t_obj *tmp)
{
	if (keycode == 36 && (mlx->selection = 0) > -1)
		return (0);
	else if (keycode == 24 && tmp->type != 3)
		tmp->size = (tmp->size < 10000) ? tmp->size + 5 : tmp->size;
	else if (keycode == 27 && tmp->type != 3)
		tmp->size = (tmp->size > 6) ? tmp->size - 5 : tmp->size;
	else if (keycode == KEY_A)
		tmp->pos = (t_vec){tmp->pos.x + 10.0 * I.x,
			tmp->pos.y + 10.0 * I.y, tmp->pos.z + 10.0 * I.z};
	else if (keycode == KEY_D)
		tmp->pos = (t_vec){tmp->pos.x - 10.0 * I.x,
			tmp->pos.y - 10.0 * I.y, tmp->pos.z - 10.0 * I.z};
	else if (keycode == KEY_W)
		tmp->pos = (t_vec){tmp->pos.x + 10.0 * J.x,
			tmp->pos.y + 10.0 * J.y, tmp->pos.z + 10.0 * J.z};
	else if (keycode == KEY_S)
		tmp->pos = (t_vec){tmp->pos.x - 10.0 * J.x,
			tmp->pos.y - 10.0 * J.y, tmp->pos.z - 10.0 * J.z};
	else if (keycode == KEY_PLUS)
		tmp->pos = (t_vec){tmp->pos.x - 10.0 * K.x,
			tmp->pos.y - 10.0 * K.y, tmp->pos.z - 10.0 * K.z};
	else if (keycode == KEY_MINUS)
		tmp->pos = (t_vec){tmp->pos.x + 10.0 * K.x,
			tmp->pos.y + 10.0 * K.y, tmp->pos.z + 10.0 * K.z};
	return (ft_objects_rot(keycode, mlx));
}

void			ft_tmp_string(t_mlx *mlx)
{
	t_obj		*tmp;

	tmp = mlx->tmp;
	mlx->pos = ft_strjoinl("pos: ", (
	ft_strjoinl(ft_itoa(tmp->pos.x), (
	ft_strjoinl(" ", (
	ft_strjoinl(ft_itoa(tmp->pos.y), (
	ft_strjoinl(" ", ft_itoa(tmp->pos.z), 'R')), 'B')), 'R')), 'B')), 'R');
	if (tmp->type != 4)
	{
		mlx->rot = ft_strjoinl("rot: ", (
		ft_strjoinl(ft_ftoa(tmp->rot.x), (
		ft_strjoinl(" ", (
		ft_strjoinl(ft_ftoa(tmp->rot.y), (
		ft_strjoinl(" ", ft_ftoa(tmp->rot.z), 'R')), 'B')), 'R')), 'B')), 'R');
	}
}

t_obj			*ft_seek(double u, double v, t_vec vpos, t_mlx *mlx)
{
	t_obj	*tmp;
	t_th	*th;

	if (!(th = (t_th *)malloc(sizeof(t_th))))
		return (NULL);
	tmp = mlx->obj;
	K = ft_vectorsub(&mlx->cam_dir, &vpos);
	ft_vectornorm(&K);
	I = ft_vectorcross(&K, &(t_vec){0.0, 1.0, 0.0});
	ft_vectornorm(&I);
	J = ft_vectorcross(&I, &K);
	mlx->ray_dir = (t_vec){u * I.x + v * J.x + FOV * K.x, u * I.y + v * J.y
		+ FOV * K.y, u * I.z + v * J.z + FOV * K.z};
	ft_vectornorm(&mlx->ray_dir);
	tmp = ft_intersection(th, tmp, mlx->ray_dir, vpos);
	free(th);
	return (tmp);
}

void			ft_string_put(t_mlx *mlx)
{
	char	*s;

	s = (mlx->tmp->type != 3) ? \
		ft_strjoinl("size: ", ft_itoa(mlx->tmp->size), 'R') : 0;
	ft_tmp_string(mlx);
	if (mlx->tmp->type == 1 || mlx->tmp->type == 2)
	{
		if (mlx->tmp->type == 1)
			mlx_ps(mlx, 0, 720, "object: cone");
		if (mlx->tmp->type == 2)
			mlx_ps(mlx, 0, 720, "object: cylinder");
		mlx_ps(mlx, 0, 750, mlx->rot);
		mlx_ps(mlx, 0, 765, s);
	}
	else if (mlx->tmp->type == 3)
	{
		mlx_ps(mlx, 0, 720, "object: plane");
		mlx_ps(mlx, 0, 750, mlx->rot);
	}
	else if (mlx->tmp->type == 4)
	{
		mlx_ps(mlx, 0, 720, "object: sphere");
		mlx_ps(mlx, 0, 765, s);
	}
	(mlx->tmp->type != 3) ? free(s) : NULL;
}

int				ft_mouse(int button, int x, int y, t_mlx *mlx)
{
	double	u;
	double	v;

	u = (WIN_W - (double)x * 2.0) / WIN_H;
	v = (WIN_H - (double)y * 2.0) / WIN_W;
	if (button == 1 && (x >= 0 && x <= WIN_W) && (y >= 0 && y <= WIN_H))
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
		ft_hud(mlx);
		if ((mlx->tmp = ft_seek(u, v, (t_vec){mlx->cam_pos.x + u,
			mlx->cam_pos.y + v, mlx->cam_pos.z}, mlx)) == NULL)
		{
			mlx_ps(mlx, 0, 720, "no selection");
			mlx->selection = 0;
			return (0);
		}
		ft_string_put(mlx);
		mlx_ps(mlx, 0, 735, mlx->pos);
		free(mlx->pos);
		(mlx->tmp->type != 4) ? free(mlx->rot) : NULL;
		mlx->selection = 1;
	}
	return (0);
}
