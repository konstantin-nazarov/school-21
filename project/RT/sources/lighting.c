/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 14:43:46 by dhorker           #+#    #+#             */
/*   Updated: 2019/07/28 15:12:13 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headlines.h"

double	create_lighting(t_scene scene, t_vec3 inter, t_vec3 normal)
{
	t_vec3	tmp;
	t_vec3	dir;
	double	t;
	double	dot;
	double	intes;
	int		i;

	intes = 0;
	i = -1;
	while (++i < 2)
	{
		if (scene.light[i]->type == AMBIENT)
			intes += scene.light[i]->intensity;
		else
		{
			if (scene.light[i]->type == POINT)
			{
				scene.shadow = 1;
				tmp = ft_vec3_sub(scene.light[i]->pos, inter);
				if ((t = intersection(&scene, inter, tmp)) > LEAST && t < 1)
					continue ;
			}
			else
				tmp = scene.light[i]->dir;
			tmp = ft_vec3_normal(tmp);
			dot = ft_vec3_dot(normal, tmp);
			if (dot > 0)
				intes += scene.light[i]->intensity * dot;
		}
	}
	if (intes > 1)
		intes = 1;
	return (intes);
}
