/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 14:41:17 by dhorker           #+#    #+#             */
/*   Updated: 2019/07/28 18:00:58 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headlines.h"

t_object	**create_object()
{
	t_object	**object;

	object = (t_object**)malloc(sizeof(t_object*) * 4);

	object[3] = (t_object*)malloc(sizeof(t_object));
	object[3]->type = PLANE;
	object[3]->pos = create_vec3(-50, 0, 150);
	object[3]->norm = create_vec3(1, 0, 0);
	object[3]->color = create_vec3(0, 0x99, 0x11);

	object[2] = (t_object*)malloc(sizeof(t_object));
	object[2]->type = SPHERE;
	object[2]->pos = create_vec3(-50, 0, 150);
	object[2]->color = create_vec3(0xFF, 0x99, 0);
	object[2]->r = 35;

	object[1] = (t_object*)malloc(sizeof(t_object));
	object[1]->type = SPHERE;
	object[1]->pos = create_vec3(00, 0, 150);
	object[1]->color = create_vec3(0, 0x99, 0);
	object[1]->r = 15;

	object[0] = (t_object*)malloc(sizeof(t_object));
	object[0]->type = PLANE;
	object[0]->pos = create_vec3(0, -50, 150);
	object[0]->norm = create_vec3(0, 1, 0);
	object[0]->color = create_vec3(0, 0x99, 0x11);
	return (object);
}

t_light	**create_light()
{
	t_light	**light;

	light = (t_light**)malloc(sizeof(t_light*) * 2);
	light[0] = (t_light*)malloc(sizeof(t_light));
	light[0]->type = AMBIENT;
	light[0]->intensity = 0.2;

	light[1] = (t_light*)malloc(sizeof(t_light));
	light[1]->type = POINT;
	light[1]->pos = create_vec3(20, 0, 150);
	light[1]->intensity = 1;
	return (light);
}

t_camera	**create_camera()
{
	t_camera	**camera;

	camera = (t_camera**)malloc(sizeof(t_camera*));
	camera[0] = (t_camera*)malloc(sizeof(t_camera));
	camera[0]->pos = create_vec3(0, 0, 0);
	camera[0]->dir = create_vec3(0, 0, 0);
	camera[0]->z = (F_W * 0.5) / tanf((FOV * 0.5) * (M_PI / 180));
	return (camera);
}

void	direction_camera(t_scene *scene, double x, double y)
{
	t_vec3	pixel;
	double	z;

	x -= F_W * 0.5;
	y = -(y - F_H * 0.5);
	z = (F_W * 0.5) / tanf((FOV * 0.5) * (M_PI / 180));
	pixel = create_vec3(x, y, z);
	scene->camera[0]->dir = ft_vec3_sub(pixel, scene->camera[0]->pos);
	scene->camera[0]->dir = ft_vec3_normal(scene->camera[0]->dir);
}

void	create_scene(t_scene *scene)
{
	scene->mlx = mlx_init();
	scene->win = mlx_new_window(scene->mlx, F_W, F_H, "RT");
	scene->img = mlx_new_image(scene->mlx, F_W, F_H);
	scene->img_b = 24;
	scene->img_w = F_W;
	scene->img_e = 1;
	scene->texture = (unsigned char*)mlx_get_data_addr(scene->img, &(scene->img_b), &(scene->img_w), &(scene->img_e));
	scene->img_rw = (int*)scene->texture;
	scene->object = create_object();
	scene->change = (t_object*)malloc(sizeof(t_object));
	scene->change = NULL;
	scene->shadow = 0;
	scene->light = create_light();
	scene->camera = create_camera();
}

int		ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
