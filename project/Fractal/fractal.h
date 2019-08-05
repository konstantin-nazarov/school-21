/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:22:22 by dhorker           #+#    #+#             */
/*   Updated: 2019/07/01 18:27:00 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H

# define FRACTAL_H

# include "minilibx_macos/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <OpenCL/cl.h>
#include <stdio.h>

# define F_H 1000
# define F_W 1500
# define M_H 250
# define M_W 375

typedef struct			s_system
{
	void				*mlx;
	void				*win;
	void				*img;
	unsigned int		*m_img;
	unsigned int		*re_img;
	unsigned int		*mini_img;
	int					b_img;
	int					l_img;
	int					lmini_img;
	int					e_img;
}						t_system;

typedef union			u_color
{
	unsigned int		rgba;
	struct
	{
		unsigned int	b:8;
		unsigned int	g:8;
		unsigned int	r:8;
		unsigned int	a:8;
	}					u;
}						t_color;

typedef struct			s_fractal
{
	int					block_h;
	int					block_w;
	float				sx;
	float				sy;
	float				dx;
	float				dy;
	float				z;
	int					it;
	float				size;
	unsigned char		psych;
	int					win_w;
	t_color				color;
}						t_fractal;

typedef struct			s_struct
{
	t_system			*sys;
	t_fractal			*fractal;
	t_fractal			*mini;
	void				(*f[5])(t_fractal*, int width, int height);
	void				(*out[5])(t_system*, t_fractal*);
	int					(*pixel[5])(t_fractal*, float, float, char);
	int					id;
	char				pause;
	char				psych;
	char				shade;
	char				opacity;
}						t_struct;

typedef struct			s_cl
{
	cl_uint				err;		// код ошибки
	cl_int				err_int;
	cl_platform_id		plat_id;	// идентификаторы платформы
	cl_uint				plat_count;	// количество платформ
	cl_device_id		dev_id;	// идентификаторы устройств
	cl_uint				dev_count;	// количество устройств
	cl_context			cont;
	cl_command_queue	queue;
	cl_program			prog;
	cl_kernel			kern;
	cl_mem				frac;
	cl_mem				x;
	cl_mem				y;
	cl_mem				c;
	cl_mem				win;
}						t_cl;


int						process_ms(int key, int x, int y, t_struct *ms);
int						process_brd(int key, t_struct *inp);
int						color(t_fractal *fractal, int i);
int						ft_close(t_struct *strct);
void					create_mlx(t_system *mlx);
void					ft_bzero(void *b, size_t length);
void					ft_putstr(char *str);
int						ft_strcmp(char *str1, char *str2);
int						move_ms(int x, int y, t_struct *ms);
void					create_mandelbrot(t_fractal *fractal, int width,
						int height);
void					out_mandelbrot(t_system *mlx, t_fractal *frac, t_cl cl);
// int						pixel_mandelbrot(t_fractal *fractal, float x, float y,
// 						char win);
void					create_julia(t_fractal *fractal, int width, int height);
void					out_julia(t_system *mlx, t_fractal *frac);
int						pixel_julia(t_fractal *fractal, float x, float y,
						char win);
void					create_carpet(t_fractal *fractal, int width,
						int height);
void					out_carpet(t_system *mlx, t_fractal *frac);
int						pixel_carpet(t_fractal *fractal, int x, int y, int i);
void					create_newton(t_fractal *fractal, int width,
						int height);
void					out_newton(t_system *mlx, t_fractal *frac);
int						pixel_newton(t_fractal *fractal, float x, float y,
						char win);
void					create_ship(t_fractal *fractal, int width, int height);
void					out_ship(t_system *mlx, t_fractal *frac);
int						pixel_ship(t_fractal *fractal, float x, float y,
						char win);
void					mini_window(t_struct strct);
void					clear_window(t_system *mlx);
void					refractal_brd(int key, t_struct *inp);
void					support_pos(t_struct *p, float x, float y, float t);
void					support_neg(t_struct *p, float x, float y);
void					print_information(void);
void					create_output_list(void (*f[5])(t_system*, t_fractal*));
void					create_fractal_list(void (*f[5])(t_fractal*, int, int));
void					create_pixel_list(int (*f[5])(t_fractal*, float,
						float, char));
void					create_struct(t_system *mlx, t_struct *strct, int id);
int	opencl_start(t_cl *cl);

#endif
