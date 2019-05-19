/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:22:22 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/12 16:06:14 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H

# define FRACTAL_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>

# define P_H 1000
# define P_W 1500

typedef struct			s_system
{
	void				*mlx;
	void				*win;
	void				*img;
	unsigned int		*re_img;
	int					b_img;
	int					l_img;
	int					e_img;
}						t_system;

typedef union			s_color
{
	int					rgba;
	struct
	{
		unsigned int	B:8;
		unsigned int	G:8;
		unsigned int	R:8;
		unsigned int	A:8;
	}					u;
}						u_color;

typedef struct			s_fractal
{
	int					block_h;
	int					block_w;
	float				cX;
	float				cY;
	float				size;
	int					it;
}						t_fractal;

typedef struct			s_key
{
	int					key;
	t_system			*sys;
	t_fractal			*fractal;
}						t_key;
#endif
