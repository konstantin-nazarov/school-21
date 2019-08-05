/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 14:46:19 by dhorker           #+#    #+#             */
/*   Updated: 2019/07/28 15:36:11 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headlines.h"

int		mouse_press(int button, int x, int y, t_scene *scene)
{
	if (button == 1)
	{
		direction_camera(scene, x, y);
		scene->obj = -1;
		intersection(scene, scene->camera[0]->pos, scene->camera[0]->dir);
		if (scene->obj != -1)
			scene->change = scene->object[scene->obj];
		else
			scene->change = NULL;
	}
	return (0);
}
