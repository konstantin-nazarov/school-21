/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:24:42 by krakharo          #+#    #+#             */
/*   Updated: 2019/06/17 17:24:43 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H
# include <math.h>

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

t_vec				ft_vectorscale(t_vec *v, double n);
t_vec				ft_vectorsub(t_vec *v1, t_vec *v2);
t_vec				ft_vectorcross(t_vec *v1, t_vec *v2);
void				ft_vectornorm(t_vec *v);
double				ft_vectordot(t_vec *v1, t_vec *v2);

void				ft_print_vec(t_vec *vec);

#endif
