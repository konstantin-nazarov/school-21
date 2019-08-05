/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:06:10 by dhorker           #+#    #+#             */
/*   Updated: 2019/07/01 19:09:57 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

// int		pixel_mandelbrot(t_fractal *fractal, float x, float y, char win)
// {
// 	float	cx;
// 	float	cy;
// 	float	temp;
// 	int		i;

// 	win = 0;
// 	i = -1;
// 	cx = (x / fractal->block_w - fractal->sx) * fractal->size - fractal->dx;
// 	cy = (fractal->sy - y / fractal->block_h) * fractal->size + fractal->dy;
// 	x = 0;
// 	y = 0;
// 	while ((temp = x * x + y * y) <= 4 && ++i < fractal->it)
// 	{
// 		temp = x * x - y * y + cx;
// 		y = 2 * x * y + cy;
// 		x = temp;
// 	}
// 	if (temp > 4)
// 		return (color(fractal, (i < 1) ? 1 : i));
// 	return (0x99FF99);
// }

void	out_mandelbrot(t_system *mlx, t_fractal *fractal, t_cl cl)
{
	// int	x;
	// int	y;
	char	win = 'F';

	clear_window(mlx);
	cl.frac = clCreateBuffer(cl.cont, CL_MEM_READ_ONLY, sizeof(fractal), 0, &(cl.err_int));
	// cl.x = clCreateBuffer(cl.cont, CL_MEM_READ_ONLY, 4, 0, &(cl.err_int));
	// cl.y = clCreateBuffer(cl.cont, CL_MEM_READ_ONLY, 4, 0, &(cl.err_int));
	cl.win = clCreateBuffer(cl.cont, CL_MEM_READ_ONLY, 1, 0, &(cl.err_int));
	cl.c = clCreateBuffer(cl.cont, CL_MEM_WRITE_ONLY, sizeof(mlx->re_img), 0, &(cl.err_int));

	cl.kern = clCreateKernel(cl.prog, "pixel_mandelbrot", &(cl.err_int));							// создает объект потока
if (cl.err_int == CL_INVALID_PROGRAM_EXECUTABLE)
		printf("err - %d\n", (int)cl.err_int);
	cl.err_int = clSetKernelArg(cl.kern, 0, sizeof(fractal), &fractal);							// передает аргументы в функцию потока
	if ((int)cl.err_int != 0)
		printf("err - %d\n", (int)cl.err_int);
	// cl.err_int = clSetKernelArg(cl.kern, 1, 4, &x);
	// cl.err_int = clSetKernelArg(cl.kern, 2, 4, &y);
	cl.err_int = clSetKernelArg(cl.kern, 1, 1, &win);
	if ((int)cl.err_int != 0)
		printf("err - %d\n", (int)cl.err_int);
	cl.err_int = clSetKernelArg(cl.kern, 2, sizeof(mlx->re_img), &(mlx->re_img));
	if ((int)cl.err_int != 0)
		printf("err - %d\n", (int)cl.err_int);


	cl.err_int = clEnqueueWriteBuffer(cl.queue, cl.win, CL_FALSE, 0, 1, &win, 0, 0, 0);
	if ((int)cl.err_int != 0)
		printf("2err\n");
	cl.err_int = clEnqueueWriteBuffer(cl.queue, cl.c, CL_FALSE, 0, sizeof(mlx->re_img), &(mlx->re_img), 0, 0, 0);
	if ((int)cl.err_int != 0)
		printf("2err\n");
	cl.err_int = clEnqueueWriteBuffer(cl.queue, cl.frac, CL_FALSE, 0, sizeof(fractal), &fractal, 0, 0, 0);
	if ((int)cl.err_int != 0)
		printf("2err\n");

	// cl.err_int = clEnqueueWriteBuffer(cl.queue, mem1, CL_FALSE, 0, len, buf, 0, 0, 0);	// запись данных в аргумент
	// cl.err_int = clEnqueueNDRangeKernel(cl.queue, cl.kern, 1, 0, &len, &len, 0, 0, 0);	// запуск потока
	// cl.err_int = clEnqueueReadBuffer(cl.queue, mem2, CL_FALSE, 0, len, buf2, 0, NULL, NULL);
	// y = -1;
	// while (++y < F_H)
	// {
	// 	x = -1;
	// 	{
	// 		while (++x < F_W)
	// 		{
	// 			mlx->re_img[y * F_W + x] = pixel_mandelbrot(fractal, x, y, 'F');
	// 		}
	// 	}
	// }
	size_t w_h = F_H * F_W;
	cl.err_int = clEnqueueNDRangeKernel(cl.queue, cl.kern, 1, 0, &w_h, 0, 0, 0, 0);
	cl.err_int = clEnqueueReadBuffer(cl.queue, cl.c, CL_FALSE, 0, sizeof(mlx->re_img), mlx->re_img, 0, NULL, NULL);
	cl.err_int = clFinish(cl.queue);	// завершение очереди, после выполнения всех действий

	if ((cl.err_int = clReleaseContext(cl.cont)) == CL_INVALID_CONTEXT)
		printf("Invalid context\n");
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, M_H + 1);
}

void	create_mandelbrot(t_fractal *fractal, int width, int height)
{
	fractal->block_w = width / 3;
	fractal->block_h = height / 2;
	fractal->size = 1;
	fractal->sx = 2;
	fractal->sy = 1;
	fractal->dx = 0;
	fractal->dy = 0;
	fractal->it = 30;
	fractal->psych = 0;
	fractal->color.rgba = 0x00FFFF;
	fractal->win_w = F_W;
}
