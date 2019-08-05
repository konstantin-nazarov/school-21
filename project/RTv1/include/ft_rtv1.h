/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtv1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:24:52 by krakharo          #+#    #+#             */
/*   Updated: 2019/06/20 17:52:53 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RTV1_H
# define FT_RTV1_H

# include <errno.h>
# include <pthread.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

# include "libft.h"
# include "ft_help_func.h"
# include "ft_vector.h"
# include "ft_keys.h"
# include "ft_color.h"

# define FOV 2.0

# define WIN_W 800
# define WIN_H 800

# define CONE 1
# define CYLN 2
# define PLANE 3
# define SPHERE 4

# define I mlx->i
# define J mlx->j
# define K mlx->k

# define POSX mlx->cam_pos.x
# define POSY mlx->cam_pos.y
# define POSZ mlx->cam_pos.z

# define COND1 mlx->spec == 1 && tmp2->type != 3
# define COND2 mlx->spec == 1 && tmp->type != 3

# define THREAD 8

typedef struct		s_color
{
	double			red;
	double			green;
	double			blue;
}					t_color;

typedef struct		s_obj
{
	int				type;
	double			size;
	t_vec			rot;
	t_vec			pos;
	t_color			col;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_mlx
{
	int				nbl;
	int				hud;
	int				selection;
	int				maxref;
	int				pref;
	int				aa;
	char			*d;
	char			*pos;
	char			*rot;
	char			**scene;
	void			*mlx;
	void			*win;
	void			*img;
	t_vec			i;
	t_vec			j;
	t_vec			k;
	t_vec			cam_pos;
	t_vec			cam_dir;
	t_vec			ray_dir;
	t_vec			norm;
	t_vec			ref;
	t_vec			dist;
	t_vec			refpos;
	t_obj			*obj;
	t_obj			*tmp;
	t_obj			*light;
	double			spec;
	double			t0;
	double			t1;
	double			t;
	double			a;
	double			b;
	double			c;
	int				bpp;
	int				size_line;
	int				endian;
}					t_mlx;

typedef struct		s_tab_th
{
	t_mlx			*mlx;
	int				i;
}					t_tab_th;

typedef struct		s_th
{
	int				maxref;
	int				pref;
	int				cpt;
	int				ty;
	int				tx;
	int				aa;
	char			*d;
	t_vec			i;
	t_vec			j;
	t_vec			k;
	t_vec			cam_pos;
	t_vec			cam_dir;
	t_vec			ray_dir;
	t_vec			norm;
	t_vec			ref;
	t_vec			dist;
	t_vec			refpos;
	t_obj			*obj;
	t_obj			*light;
	double			spec;
	double			t0;
	double			t1;
	double			t;
	double			a;
	double			b;
	double			c;
	int				bpp;
	int				size_line;
}					t_th;

/*
**	Add object, ft_object.c
*/
int					ft_add_light(t_mlx *mlx, int *k, int i);
int					ft_add_plane(t_mlx *mlx, int *k, int i);
int					ft_add_sphere(t_mlx *mlx, int *k, int i);
int					ft_add_cyl_cone(t_mlx *mlx, int *k, int t, int i);
int					ft_col_n_pos(t_mlx *mlx, t_obj *link, int k);

int					ft_draw(t_mlx *mlx);
int					ft_pars(t_mlx *mlx);
int					close_hook(t_mlx *mlx);
int					ft_linelen(char *buf, int k);
int					key_hook(int keycode, t_mlx *mlx);
int					ft_pref_key(int keycode, t_mlx *mlx);
int					ft_free_lists(t_obj *lgt, t_obj *obj);
int					ft_parameters(int keycode, t_mlx *mlx, t_obj *tmp);
int					ft_objects_rot(int keycode, t_mlx *mlx);
int					ft_free_arg(t_mlx *mlx, char *buf, int stat);
int					ft_check_objects(t_mlx *mlx, t_obj *objects);
int					ft_mouse(int button, int x, int y, t_mlx *mlx);

void				ft_hud(t_mlx *mlx);
void				ft_help(void);
void				ft_string_put(t_mlx *mlx);
void				ft_init_mlx_var(t_mlx *mlx);
void				ft_copy(t_mlx *mlx, t_th *th);
void				ft_put_pixel(t_th *mlx, int x, int y, int color);

double				ft_inter_cone(t_th *mlx, t_obj *node, t_vec ray,
									t_vec pos);
double				ft_inter_cylinder(t_th *mlx, t_obj *node, t_vec ray,
									t_vec pos);
double				ft_inter_plane(t_th *mlx, t_obj *node, t_vec ray,
									t_vec pos);
double				ft_inter_sphere(t_th *mlx, t_obj *node, t_vec ray,
									t_vec pos);

t_vec				ft_norm(t_th *mlx, t_obj *tmp, t_vec pos);
t_obj				*copy_obj(t_obj *obj);
t_obj				*ft_add_light_link(t_mlx *mlx, t_obj *link);
t_obj				*ft_add_object(t_mlx *mlx, t_obj *link);
t_obj				*ft_intersection(t_th *mlx, t_obj *node, t_vec ray,
									t_vec pos);

double				*ft_average(double *r, double *tab);
double				*ft_endlight(t_obj *tmp, t_obj *light, double *tab,
									double d);
double				*ft_lambert(t_th *mlx, t_obj *tmp, t_obj *light,
									double *tab);
double				ft_spec(t_th *mlx, t_vec dist, double d,
									double lambert);

int					ft_init(t_mlx *mlx, char *s);
char				*sort_stage_one(char *buf);

void				mlx_ps(t_mlx *mlx, int x, int y, char *str);

#endif
