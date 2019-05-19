/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 21:07:47 by ccolemon          #+#    #+#             */
/*   Updated: 2019/03/09 17:32:38 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define P_W 1700
# define P_H 1000
# define MATRIX matrix[j][i]
# define M_A m[j][i].c.u.a

# define DEFAULT 0xFFD700
# define BLACK 0x000000
# define D_GRAY 0xA9A9A9
# define GRAY 0xB0B0B0
# define RED 0xFF0000
# define YELLOW 0xFFFF00
# define GREEN 0x00FF00
# define CYAN 0x00FFFF
# define BLUE 0x0000FF
# define PINK 0xFF00FF
# define WHITE 0xFFFFFF

# define KR 15
# define KY 16
# define KG 5
# define KC 8
# define KB 11
# define KP 35
# define KW 13

# define KD 2
# define KO 31
# define KS 1
# define KESC 53
# define KLEFT 123
# define KRIGHT 124

# define CHECK_ERROR(x) if (x == -1) return(-1);
# define MESSAGE_ERR {write(1,"ERROR: invalid file\n",20);close(fd);return(0);}
# define F_ERR(m, c, p0, p1, p2) {F_FREE(p0, p1, p2);ft_putstr(m);return(c);}
# define F_FREE(p0, p1, p2) {free(p0); free(p1); free(p2);}
# define USAGE {write(1, "usage: ./fdf [file]\n", 20); return (0);}
# define F_IF(x, func) if ((x)) func
# define F_WH(x, func) while ((x)) func
# define LEN_LINE (sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)))
# define ARGB(x, y) y.u.x = p1.u.x + (p2.u.x - p1.u.x) * i / l;
# define SP(n,c,s) mlx_string_put(win->mlx, win->win, 10, 10 + n, c, s)

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

/*
** работа с окном
** img -
** rem_i -
** x, y - ширина/высота окна
** bit -
** size_l -
** endian -
*/

typedef struct		s_system
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*rem_i;
	int				x;
	int				y;
	int				bit;
	int				size_l;
	int				endian;
}					t_system;

/*
** работа с цветами и оттенками
** A - непрозрачность
*/

typedef union		u_argb
{
	unsigned int	argb;
	struct
	{
		unsigned	b: 8;
		unsigned	g: 8;
		unsigned	r: 8;
		unsigned	a: 8;
	}				u;
}					t_argb;

/*
** параметры карты
** sX, sY - стартовые координаты
** cX, cY - координаты центра
** X,Y - ширина и высота карты
** gap - шаг между точками
** tX, tY, tZ - поворот по осям
** mtx - считанная строка из файла
** pX, pY, nX, nY- крайние Х, Y
*/

typedef struct		s_fdf
{
	int				sx;
	int				sy;
	int				cx;
	int				cy;
	int				x;
	int				y;
	int				gap;
	double			tx;
	double			ty;
	double			tz;
	int				px;
	int				nx;
	int				py;
	int				ny;
	char			*mtx;
}					t_fdf;

/*
** параметры точки
** x,y,z - координаты
** oz - z для расчета поворота
** c, tmp_c - цвет
*/

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				oz;
	t_argb			c;
	t_argb			tmp_c;
}					t_point;

/*
** работа с мышкой и клавой
** key - код с мышки
** x,y - координаты мышки
** keycode - код с клавиатуры
*/

typedef struct		s_inp
{
	int				key;
	int				x;
	int				y;
	int				keycode;
	int				check;
	t_fdf			*map;
	t_system		*win;
	t_point			**point;
}					t_inp;

/*
** прорисовка линии
** dX, dY - модуль разницы меду координатами
** ratio - коэффициент поворота
** shift - сдвиг относительно идеальной линии
** space - шаг оттенка
*/

typedef struct		s_line
{
	int				dx;
	int				dy;
	int				x;
	int				y;
	int				l;
	int				i;
	float			ratio;
	float			sh;
	t_argb			space;
}					t_line;

/*
** main.c
*/

int					ft_close(void *param);
void				create_map(t_system win, t_fdf *map);
int					fdf(t_system *win, t_fdf *map, t_inp *inp);
int					calc(int fd, t_fdf *map, int check);
int					main(int fd, char **av);

/*
** parcer.c
*/

unsigned int		ft_ab(char *str);
void				del_matrix(t_point **matrix, int h);
t_point				**create_matrix(int h, int w);
t_point				**fill(t_fdf *map, int j);
int					valid(t_fdf map, int check, int i);

/*
** input.c
*/

int					mouse_press(int key, int x, int y, t_inp *mouse);
int					mouse_unpress(int key, int x, int y, t_inp *mouse);
int					key_press(int code, t_inp *key);

/*
** rotate.c
*/

void				rot_z(t_fdf *m, t_point *p);
void				rot_y(t_fdf *map, t_point *p);
void				rot_x(t_fdf *map, t_point *p);
void				rotate(t_system *win, t_fdf *map, t_point **p, int i);
void				rerotate(t_inp *mouse, int x, int y);

/*
** grid_n_color.c
*/

unsigned			nc(t_argb p1, t_argb p2, int l, int i);
t_point				**change_color(t_system win, t_point **mtx, \
								t_fdf *map, int keycode);
void				output_grid(t_system *win, t_fdf map, t_point **point);
void				create_grid(t_system *win, t_fdf *map, \
								t_point **point, int keycode);

/*
** line.c
*/

void				rememory_img(t_system *win, int x, int y, unsigned int nc);
void				easyline(t_system *w, t_point p1, t_point p2, t_line s);
void				descent(t_system *w, t_line s, t_point p1, t_point p2);
void				rise(t_system *w, t_line s, t_point p1, t_point p2);
void				line(t_system *win, t_point p1, t_point p2);

/*
** line_dop.c
*/

int					op(int color, unsigned char op);
unsigned char		fac(float x);

/*
** remove.c
*/

void				re_y(t_inp *mouse, int x);
void				recoor(t_inp *mouse, int *x, int *y);
void				zoompos(t_inp *ms);
void				zoomneg(t_inp *mouse);
int					move_map(int x, int y, t_inp *mouse);

#endif
