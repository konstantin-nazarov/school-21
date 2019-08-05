/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:37:25 by dhorker           #+#    #+#             */
/*   Updated: 2019/07/01 18:35:20 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/*
**	Закрытие
*/

int		ft_close(t_struct *key)
{
	free(key->fractal);
	free(key->mini);
	exit(0);
	return (0);
}

/*
** Смена фрактала
*/

void	refractal_brd(int key, t_struct *inp)
{
	inp->psych = 0;
	inp->shade = 0;
	if (key == 18)
		inp->id = 0;
	else if (key == 19)
		inp->id = 1;
	else if (key == 20)
		inp->id = 2;
	else if (key == 21)
		inp->id = 3;
	else if (key == 23)
		inp->id = 4;
	inp->f[inp->id](inp->fractal, F_W, F_H);
	inp->out[inp->id](inp->sys, inp->fractal);
	mini_window(*inp);
}

/*
** Очистка фрактала
*/

void	clear_window(t_system *mlx)
{
	int	i;
	int	j;

	i = 249;
	while (++i < (F_H + M_H))
	{
		j = -1;
		while (++j < F_W)
			mlx_pixel_put(mlx->mlx, mlx->win, j, i, 0x000000);
	}
}

/*
** Заполнение системной структуры
*/

void	create_mlx(t_system *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, F_W, F_H + M_H, "Fractal");
	mlx->img = mlx_new_image(mlx->mlx, F_W, F_H + M_H);
	mlx->m_img = mlx_new_image(mlx->mlx, 375, 250);
	mlx->b_img = 32;
	mlx->l_img = F_W;
	mlx->e_img = 1;
	mlx->re_img = (unsigned int*)mlx_get_data_addr(mlx->img,
		&mlx->b_img, &mlx->l_img, &mlx->e_img);
	mlx->lmini_img = F_W;
	mlx->mini_img = (unsigned int*)mlx_get_data_addr(mlx->m_img,
		&mlx->b_img, &mlx->lmini_img, &mlx->e_img);
}

/*
**	Заполнение всех необходимых структур
*/

void	create_struct(t_system *mlx, t_struct *strct, int id)
{
	t_cl cl;

	opencl_start(&cl);
	create_mlx(mlx);
	create_fractal_list(strct->f);
	create_output_list(strct->out);
	create_pixel_list(strct->pixel);
	strct->id = id;
	strct->pause = 0;
	strct->psych = 0;
	strct->sys = mlx;
	strct->opacity = 0;
	if (!(strct->fractal = (t_fractal*)malloc(sizeof(t_fractal))))
		ft_close(strct);
	if (!(strct->mini = (t_fractal*)malloc(sizeof(t_fractal))))
		ft_close(strct);
	strct->f[id](strct->fractal, F_W, F_H);
	strct->f[id](strct->mini, M_W, M_H);
	// strct->out[id](strct->sys, strct->fractal);
	out_mandelbrot(strct->sys, strct->fractal, cl);
	mini_window(*strct);
	mlx_hook(mlx->win, 2, 0, process_brd, strct);
	mlx_hook(mlx->win, 4, 0, process_ms, strct);
	mlx_hook(mlx->win, 6, 0, move_ms, strct);
	mlx_hook(mlx->win, 17, 0, ft_close, strct);
	mlx_loop(mlx->mlx);
}
