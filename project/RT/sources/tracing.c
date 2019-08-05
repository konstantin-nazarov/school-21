/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 14:43:11 by dhorker           #+#    #+#             */
/*   Updated: 2019/07/28 15:46:54 by dhorker          ###   ########.fr       */
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

t_vec3	ray_trace(t_scene scene)
{
	t_vec3	tmp;
	t_vec3	normal;
	double	t;

	scene.obj = -1;
	t = intersection(&scene, scene.camera[0]->pos, scene.camera[0]->dir);
	if (t > LEAST && t < LARG)
	{
		tmp = ft_vec3_sum(scene.camera[0]->pos, ft_vec3_multi_scal(scene.camera[0]->dir, t));
		if (scene.object[scene.obj]->type == SPHERE)
			normal = ft_vec3_normal(ft_vec3_sub(tmp, scene.object[scene.obj]->pos));
		else if (scene.object[scene.obj]->type == PLANE)
			normal = scene.object[scene.obj]->norm;
		return (ft_vec3_multi_scal(scene.object[scene.obj]->color, create_lighting(scene, tmp, normal)));
	}
	return (create_vec3(0xFF, 0xFF, 0xFF));
}
