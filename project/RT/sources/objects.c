/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 14:44:01 by dhorker           #+#    #+#             */
/*   Updated: 2019/07/28 15:12:14 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headlines.h"

double	check_sphere(t_object *object, t_vec3 pos, t_vec3 dir)
{
	t_vec3	tmp;
	double	k1;
	double	k2;
	double	k3;
	double	dis;
	double	t;
	double	res;

	res = LARG;
	tmp = ft_vec3_sub(pos, object->pos);
	k1 = ft_vec3_dot(dir, dir);
	k2 = 2 * ft_vec3_dot(tmp, dir);
	k3 = ft_vec3_dot(tmp, tmp) - (object->r * object->r);
	dis = k2 * k2 - 4 * k1 * k3;
	if (dis < 0)
		return (0);
	if ((t = (-k2 - sqrtf(dis)) / (2 * k1)) < LEAST || t > res)
		if ((t = (-k2 + sqrtf(dis)) / (2 * k1)) < LEAST || t > res)
			return (0);
	return (t);
}

double	check_plane(t_object *object, t_vec3 inter, t_vec3 dir, char shadow)
{
	t_vec3	tmp;
	double	dif;
	double	t;

	dif = ft_vec3_dot(object->norm, dir);
	if ((dif != 0 && shadow == 0) || (dif > 0 && shadow == 1))
	{
		tmp = ft_vec3_sub(object->pos, inter);
		t = ft_vec3_dot(tmp, object->norm) / dif;
			return (t);
	}
	return (0);
}
