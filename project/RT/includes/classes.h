/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik-prog <lyahasik-prog@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 13:02:49 by dhorker           #+#    #+#             */
/*   Updated: 2019/08/17 19:54:19 by lyahasik-pr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_H

# define CLASSES_H

typedef union		u_rgb
{
	unsigned int	tmp;
	struct
	{
		unsigned	b: 8;
		unsigned	g: 8;
		unsigned	r: 8;
	}				rgb;
}					t_rgb;


typedef struct		s_sdl_img
{
	SDL_Texture		*data;
	int				width;
	int				height;
	int				palette;
	SDL_Rect		rect;
}					t_sdl_img;

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Surface		*surface;
	t_sdl_img		*img;
}					t_sdl;

typedef struct		s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vec3;

typedef struct		s_camera
{
	t_vec3			pos;
	t_vec3			dir;
	t_vec3			norm;
	double			z;
}					t_camera;

typedef struct		s_object
{
	char			type;
	double			r;
	t_vec3			pos;
	t_vec3			rot;
	t_vec3			dir;
	t_vec3			norm;
	t_vec3			color;
}					t_object;

typedef struct		s_light
{
	char			type;
	t_vec3			pos;
	t_vec3			dir;
	double			intensity;
}					t_light;

typedef struct		s_scene
{
	// void			*mlx;
	// void			*win;
	// void			*img;
	// int				*img_rw;
	// int				img_b;
	// int				img_w;
	// int				img_e;
	int				obj;
	char			shadow;
	t_camera		**camera;
	t_object		**object;
	t_object		*change;
	t_light			**light;
}					t_scene;

typedef struct		s_project
{
	t_scene			*scene;
	t_sdl			*sdl;
	unsigned char	*img_buf;
}					t_project;


#endif
