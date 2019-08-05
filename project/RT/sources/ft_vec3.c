/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:10:51 by dhorker           #+#    #+#             */
/*   Updated: 2019/07/13 17:52:32 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headlines.h"

double	ft_vec3_len(t_vec3 vec)
{
	vec.x = pow(vec.x, 2);
	vec.y = pow(vec.y, 2);
	vec.z = pow(vec.z, 2);
	return (sqrt(vec.x + vec.y + vec.z));
}

/*
** Скалярное умножение векторов
*/

double	ft_vec3_dot(t_vec3 vec1, t_vec3 vec2)
{
	vec1.x *= vec2.x;
	vec1.y *= vec2.y;
	vec1.z *= vec2.z;
	return (vec1.x + vec1.y + vec1.z);
}

/*
** Деление вектора на скаляр
*/

t_vec3	ft_vec3_div_scal(t_vec3 vec, double scal)
{
	t_vec3 res;

	res.x = vec.x / scal;
	res.y = vec.y / scal;
	res.z = vec.z / scal;
	return (res);
}

/*
** Умножение вектора на скаляр
*/

t_vec3	ft_vec3_multi_scal(t_vec3 vec, double scal)
{
	t_vec3 res;

	res.x = vec.x * scal;
	res.y = vec.y * scal;
	res.z = vec.z * scal;
	return (res);
}

/*
** Вычитание векторов
*/

t_vec3	ft_vec3_sub(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3 res;

	res.x = vec1.x - vec2.x;
	res.y = vec1.y - vec2.y;
	res.z = vec1.z - vec2.z;
	return (res);
}

/*
** Сложение векторов
*/

t_vec3	ft_vec3_sum(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3 res;

	res.x = vec1.x + vec2.x;
	res.y = vec1.y + vec2.y;
	res.z = vec1.z + vec2.z;
	return (res);
}

/*
** Расстояние между векторами
*/

double	ft_vec3_dist(t_vec3 v1, t_vec3 v2)
{
	t_vec3 tmp;

	tmp = ft_vec3_sub(v1, v2);
	return (ft_vec3_len(tmp));
}

/*
** Нормализация вектора
*/

t_vec3	ft_vec3_normal(t_vec3 vec)
{
	double	len;

	len = ft_vec3_len(vec);
	return (ft_vec3_div_scal(vec, len));
}

/*
** Угол между векторами
*/

double	ft_vec3_angle(t_vec3 v1, t_vec3 v2)
{
	v1 = ft_vec3_normal(v1);
	v2 = ft_vec3_normal(v2);
	return (acos(ft_vec3_dot(v1, v2)));
}

unsigned int	ft_vec3_color(t_vec3 vec)
{
	unsigned int	color;

	color = 0;
	color = (((int)vec.x << 16) | ((int)vec.y << 8) | (int)vec.z);
	return (color);
}

t_vec3	create_vec3(double x, double y, double z)
{
	t_vec3 res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}
