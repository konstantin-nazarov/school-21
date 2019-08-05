/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:32:25 by krakharo          #+#    #+#             */
/*   Updated: 2019/06/19 20:52:12 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

t_obj			*ft_add_object(t_mlx *mlx, t_obj *link)
{
	t_obj	*head;

	head = mlx->obj;
	if (mlx->obj == NULL)
		return (link);
	while (mlx->obj->next != NULL)
		mlx->obj = mlx->obj->next;
	mlx->obj->next = link;
	return (head);
}

t_obj			*ft_add_light_link(t_mlx *mlx, t_obj *link)
{
	t_obj	*head;

	head = mlx->light;
	if (mlx->light == NULL)
		return (link);
	while (mlx->light->next != NULL)
		mlx->light = mlx->light->next;
	mlx->light->next = link;
	return (head);
}

int				ft_checkscene(t_mlx *mlx, int i)
{
	if (ft_strcmp(mlx->scene[0], "scene") != 0)
		return (-1);
	if (ft_strcmp(mlx->scene[1], "{") != 0 || \
			ft_strcmp(mlx->scene[4], "}") != 0)
		return (-1);
	if (ft_strncmp(mlx->scene[2], "	cam_pos(", 9) != 0)
		return (-1);
	mlx->cam_pos.x = (double)ft_atoin(mlx->scene[2], &i);
	mlx->cam_pos.y = (double)ft_atoin(mlx->scene[2], &i);
	mlx->cam_pos.z = (double)ft_atoin(mlx->scene[2], &i);
	if (mlx->scene[2][i] != ')')
		return (-1);
	if (ft_strncmp(mlx->scene[3], "	cam_dir(", 9) != 0)
		return (-1);
	i = 9;
	mlx->cam_dir.x = (double)ft_atoin(mlx->scene[3], &i);
	mlx->cam_dir.y = (double)ft_atoin(mlx->scene[3], &i);
	mlx->cam_dir.z = (double)ft_atoin(mlx->scene[3], &i);
	if (mlx->scene[3][i] != ')')
		return (-1);
	if (ft_strlen(mlx->scene[5]) != 0)
		return (-1);
	return (0);
}

int				ft_parse_objects(t_mlx *mlx, int k)
{
	int	res;

	while (k < mlx->nbl - 1)
	{
		if (ft_strcmp(mlx->scene[k], "	object(light)") == 0)
			res = ft_add_light(mlx, &k, 6);
		else if (ft_strcmp(mlx->scene[k], "	object(cone)") == 0)
			res = ft_add_cyl_cone(mlx, &k, CONE, 6);
		else if (ft_strcmp(mlx->scene[k], "	object(cylinder)") == 0)
			res = ft_add_cyl_cone(mlx, &k, CYLN, 6);
		else if (ft_strcmp(mlx->scene[k], "	object(plane)") == 0)
			res = ft_add_plane(mlx, &k, 6);
		else if (ft_strcmp(mlx->scene[k], "	object(sphere)") == 0)
			res = ft_add_sphere(mlx, &k, 7);
		else
			return (ft_free_lists(mlx->light, mlx->obj));
		if (res == -1)
			return (ft_free_lists(mlx->light, mlx->obj));
	}
	return (0);
}

int				ft_pars(t_mlx *mlx)
{
	t_obj	*object;

	if (ft_checkscene(mlx, 9) == -1)
		return (-1);
	if (ft_strcmp(mlx->scene[6], "content") != 0 || \
			ft_strcmp(mlx->scene[7], "{") != 0 || \
			ft_strcmp(mlx->scene[mlx->nbl - 1], "}") != 0)
		return (-1);
	if (ft_parse_objects(mlx, 8) == -1)
		return (-1);
	if (ft_check_objects(mlx, (object = NULL)) == -1)
	{
		ft_putendl("ERROR: invalid object");
		return (-1);
	}
	return (0);
}
