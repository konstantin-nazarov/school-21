/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 14:47:09 by dhorker           #+#    #+#             */
/*   Updated: 2019/07/28 15:30:36 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headlines.h"

static void	change_light(t_scene *scene, int code)
{
	if (code == 89)
		scene->light[1]->pos.x += 10;
	if (code == 86)
		scene->light[1]->pos.x -= 10;
	if (code == 91)
		scene->light[1]->pos.y += 10;
	if (code == 87)
		scene->light[1]->pos.y -= 10;
	if (code == 92)
		scene->light[1]->pos.z += 10;
	if (code == 88)
		scene->light[1]->pos.z -= 10;
}

static void	change_object(t_scene *scene, int code)
{
	if (code == 89)
		scene->change->pos.x += 10;
	if (code == 86)
		scene->change->pos.x -= 10;
	if (code == 91)
		scene->change->pos.y += 10;
	if (code == 87)
		scene->change->pos.y -= 10;
	if (code == 92)
		scene->change->pos.z += 10;
	if (code == 88)
		scene->change->pos.z -= 10;
}

int			key_press(int code, t_scene *scene)
{
	if (code == 53)
		ft_close(0);
	if ((scene->change))
		change_object(scene, code);
	else
		change_light(scene, code);
	if (code == 123)
		scene->camera[0]->pos.x -= 10;
	if (code == 124)
		scene->camera[0]->pos.x += 10;
	create_img(scene);
	mlx_put_image_to_window(scene->mlx, scene->win, scene->img, 0, 0);
	return (0);
}
