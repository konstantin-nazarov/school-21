/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:31:52 by krakharo          #+#    #+#             */
/*   Updated: 2019/06/17 15:31:54 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

int			close_hook(t_mlx *mlx)
{
	ft_free_lists(mlx->light, mlx->obj);
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx->scene);
	exit(0);
	return (0);
}

int			ft_hook_add(int keycode, t_mlx *mlx)
{
	if (mlx->selection == 1)
	{
		if (keycode == KEY_ESC)
			close_hook(mlx);
		ft_parameters(keycode, mlx, mlx->tmp);
		ft_draw(mlx);
		ft_string_put(mlx);
		mlx_ps(mlx, 0, 735, mlx->pos);
		free(mlx->pos);
		(mlx->tmp->type != 4) ? free(mlx->rot) : NULL;
		return (-1);
	}
	if (keycode == KEY_MINUS)
	{
		mlx->cam_dir = (t_vec){mlx->cam_dir.x - 10.0 * K.x,
			mlx->cam_dir.y - 10.0 * K.y, mlx->cam_dir.z - 10.0 * K.z};
		mlx->cam_pos = (t_vec){mlx->cam_pos.x - 10.0 * K.x,
			mlx->cam_pos.y - 10.0 * K.y, mlx->cam_pos.z - 10.0 * K.z};
	}
	return (0);
}

int			ft_translation_add(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_S)
	{
		mlx->cam_dir = (t_vec){mlx->cam_dir.x - 10.0 * J.x,
			mlx->cam_dir.y - 10.0 * J.y, mlx->cam_dir.z - 10.0 * J.z};
		mlx->cam_pos = (t_vec){mlx->cam_pos.x - 10.0 * J.x,
			mlx->cam_pos.y - 10.0 * J.y, mlx->cam_pos.z - 10.0 * J.z};
	}
	else if (keycode == KEY_W)
	{
		mlx->cam_dir = (t_vec){mlx->cam_dir.x + 10.0 * J.x,
			mlx->cam_dir.y + 10.0 * J.y, mlx->cam_dir.z + 10.0 * J.z};
		mlx->cam_pos = (t_vec){mlx->cam_pos.x + 10.0 * J.x,
			mlx->cam_pos.y + 10.0 * J.y, mlx->cam_pos.z - 10.0 * J.z};
	}
	else if (keycode == KEY_PLUS)
	{
		mlx->cam_dir = (t_vec){mlx->cam_dir.x + 10.0 * K.x,
			mlx->cam_dir.y + 10.0 * K.y, mlx->cam_dir.z + 10.0 * K.z};
		mlx->cam_pos = (t_vec){mlx->cam_pos.x + 10.0 * K.x,
			mlx->cam_pos.y + 10.0 * K.y, mlx->cam_pos.z + 10.0 * K.z};
	}
	ft_pref_key(keycode, mlx);
	return (ft_draw(mlx));
}

int			ft_translation(int keycode, t_mlx *mlx)
{
	K = ft_vectorsub(&mlx->cam_dir, &mlx->cam_pos);
	ft_vectornorm(&K);
	I = ft_vectorcross(&K, &(t_vec){0.0, 1.0, 0.0});
	ft_vectornorm(&I);
	J = ft_vectorcross(&I, &K);
	(keycode == KEY_ESC) ? close_hook(mlx) : 0;
	if (keycode == KEY_A)
	{
		mlx->cam_dir = (t_vec){mlx->cam_dir.x + 10.0 * I.x,
			mlx->cam_dir.y + 10.0 * I.y, mlx->cam_dir.z + 10.0 * I.z};
		mlx->cam_pos = (t_vec){mlx->cam_pos.x + 10.0 * I.x,
			mlx->cam_pos.y + 10.0 * I.y, mlx->cam_pos.z + 10.0 * I.z};
	}
	else if (keycode == KEY_D)
	{
		mlx->cam_dir = (t_vec){mlx->cam_dir.x - 10.0 * I.x,
			mlx->cam_dir.y - 10.0 * I.y, mlx->cam_dir.z - 10.0 * I.z};
		mlx->cam_pos = (t_vec){mlx->cam_pos.x - 10.0 * I.x,
			mlx->cam_pos.y - 10.0 * I.y, mlx->cam_pos.z - 10.0 * I.z};
	}
	else if (keycode == KEY_G)
		mlx->spec = (mlx->spec == 0) ? 1 : 0;
	else if (keycode == KEY_TAB)
		mlx->hud = (mlx->hud == 0) ? 1 : 0;
	return (ft_translation_add(keycode, mlx));
}

int			key_hook(int keycode, t_mlx *mlx)
{
	double	tmp_pos;

	if (ft_hook_add(keycode, mlx) == -1)
		return (0);
	else if (keycode == KEY_LEFT && (tmp_pos = mlx->cam_pos.x) < 20000)
	{
		POSX = mlx->cam_pos.x * cosf(0.05) + mlx->cam_pos.z * sinf(0.05);
		POSZ = tmp_pos * (-sinf(0.05)) + mlx->cam_pos.z * cosf(0.05);
	}
	else if (keycode == KEY_RIGHT && (tmp_pos = mlx->cam_pos.x) > -20000)
	{
		POSX = mlx->cam_pos.x * cosf(-0.05) + mlx->cam_pos.z * sinf(-0.05);
		POSZ = tmp_pos * (-sinf(-0.05)) + mlx->cam_pos.z * cosf(-0.05);
	}
	else if (keycode == KEY_DOWN && (tmp_pos = mlx->cam_pos.y) > -20000)
	{
		POSY = mlx->cam_pos.y * cosf(-0.05) + mlx->cam_pos.z * (-sinf(-0.05));
		POSZ = fabs(tmp_pos * sinf(-0.05) + mlx->cam_pos.z * cosf(-0.05)) * -1;
	}
	else if (keycode == KEY_UP && (tmp_pos = mlx->cam_pos.y) < 20000)
	{
		POSY = mlx->cam_pos.y * cosf(0.05) + mlx->cam_pos.z * (-sinf(0.05));
		POSZ = fabs(tmp_pos * sinf(0.05) + mlx->cam_pos.z * cosf(0.05)) * -1;
	}
	return (ft_translation(keycode, mlx));
}
