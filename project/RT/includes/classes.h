/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 13:02:49 by dhorker           #+#    #+#             */
/*   Updated: 2019/07/28 17:50:41 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_H

# define CLASSES_H

typedef struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef struct	s_camera
{
	t_vec3		pos;
	t_vec3		dir;
	t_vec3		norm;
	double		z;
}				t_camera;


typedef struct	s_object
{
	char		type;
	double		r;
	t_vec3		pos;
	t_vec3		dir;
	t_vec3		norm;
	t_vec3		color;
}				t_object;

typedef struct	s_light
{
	char		type;
	t_vec3		pos;
	t_vec3		dir;
	double		intensity;
}				t_light;

typedef struct	s_scene
{
	void		*mlx;
	void		*win;
	void		*img;
	unsigned char	*texture;
	int			*img_rw;
	int			img_b;
	int			img_w;
	int			img_e;
	int			obj;
	char		shadow;
	t_camera	**camera;
	t_object	**object;
	t_object	*change;
	t_light		**light;
}				t_scene;

#endif
