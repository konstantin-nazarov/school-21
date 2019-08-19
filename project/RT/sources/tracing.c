/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik-prog <lyahasik-prog@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 14:43:11 by dhorker           #+#    #+#             */
/*   Updated: 2019/08/19 19:14:33 by lyahasik-pr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headlines.h"

double	intersection(t_scene *scene, t_vec3 inter, t_vec3 dir)
{
	double	res;
	double	t;
	int	i;

	i = -1;
	res = LARG;
	while (++i < 4)
	{
		if (i == scene->obj)
			continue ;
		if (scene->object[i]->type == SPHERE)
			t = check_sphere(scene->object[i], inter, dir);
		else if (scene->object[i]->type == PLANE)
			t = check_plane(scene->object[i], inter, dir, scene->shadow);
		if (t < LEAST || t > res)
			continue ;
		res = t;
		scene->obj = i;
	}
	return (res);
}

t_vec3	create_vec3_test(double x, double y, double z)
{
	t_vec3 res;

	// if (x == 147)
	// 	printf("test - %f - %f - %f\n", x, y, z);
	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

t_vec3	convert_color(unsigned char r, unsigned char g, unsigned char b)
{
	// t_rgb	tmp;

	// tmp.tmp = *rgb;
	// printf("%d\n", rgb);
	// printf("test - %d - %d - %d\n", r, g, b);
	// printf("test - %f - %f - %f\n", (double)tmp.u.r, (double)tmp.u.g, (double)tmp.u.b);
	return (create_vec3_test(r, g, b));
	// return (create_vec3_test(99, 74, 24));
}

t_vec3	texturing(t_project project, t_object obj, t_vec3 tmp)
{
	int	temp;
	double u,v,phi;
	unsigned char *buf;
	t_vec3	color;

	u = 0;
	v = 0;
	buf = project.img_buf;
	if (obj.type == SPHERE)
	{
		tmp = ft_vec3_sum(obj.rot, tmp);
		u = 0.5 + atan2f(tmp.z, tmp.x) / (2 * M_PI) - 1;
		v = 0.5 - asinf(tmp.y) / M_PI;
		temp = (int)floor(599 * v) * 1200 * 3 + (int)floor(1199 * u) * 3;
		color = convert_color(buf[temp],
			buf[temp + 1],
			buf[temp + 2]);
		return (color);
	}
	return (obj.color);
}

t_vec3	ray_trace(t_project project)
{
	t_vec3	tmp;
	t_vec3	normal;
	double	t;

	project.scene->obj = -1;
	t = intersection(project.scene, project.scene->camera[0]->pos, project.scene->camera[0]->dir);
	if (t > LEAST && t < LARG)
	{
		tmp = ft_vec3_sum(project.scene->camera[0]->pos, ft_vec3_multi_scal(project.scene->camera[0]->dir, t));
		if (project.scene->object[project.scene->obj]->type == SPHERE)
			normal = ft_vec3_normal(ft_vec3_sub(tmp, project.scene->object[project.scene->obj]->pos));
		else if (project.scene->object[project.scene->obj]->type == PLANE)
			normal = project.scene->object[project.scene->obj]->norm;
		return (ft_vec3_multi_scal(texturing(project, *project.scene->object[project.scene->obj], normal), create_lighting(*project.scene, tmp, normal)));
		// return (ft_vec3_multi_scal(project.scene->object[project.scene->obj]->color, create_lighting(*project.scene, tmp, normal)));
	}
	return (create_vec3(0xFF, 0xFF, 0xFF));
}
