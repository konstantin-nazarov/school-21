/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:32:17 by krakharo          #+#    #+#             */
/*   Updated: 2019/06/19 20:39:39 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

int			ft_col_n_pos(t_mlx *mlx, t_obj *link, int k)
{
	int	i;

	i = 6;
	if (ft_strncmp(mlx->scene[k + 2], "		rgb(", 6) != 0 || \
			ft_strncmp(mlx->scene[k + 3], "		pos(", 6) != 0)
		return (-1);
	link->col.red = (double)ft_atoin(mlx->scene[k + 2], &i);
	link->col.green = (double)ft_atoin(mlx->scene[k + 2], &i);
	link->col.blue = (double)ft_atoin(mlx->scene[k + 2], &i);
	if (mlx->scene[k + 2][i] != ')')
		return (-1);
	i = 6;
	link->pos.x = (double)ft_atoin(mlx->scene[k + 3], &i);
	link->pos.y = (double)ft_atoin(mlx->scene[k + 3], &i);
	link->pos.z = (double)ft_atoin(mlx->scene[k + 3], &i);
	if (mlx->scene[k + 3][i] != ')')
		return (-1);
	return (0);
}

int			ft_add_light(t_mlx *mlx, int *k, int i)
{
	t_obj	*light;

	if (!(light = (t_obj *)malloc(sizeof(t_obj))))
		return (-1);
	if (ft_strcmp(mlx->scene[*k + 1], "	{") != 0 || \
			ft_strcmp(mlx->scene[*k + 4], "	}") != 0)
		return (-1);
	if (ft_strncmp(mlx->scene[*k + 2], "		rgb(", 6) != 0 || \
			ft_strncmp(mlx->scene[*k + 3], "		pos(", 6) != 0)
		return (-1);
	light->col.red = (double)ft_atoin(mlx->scene[*k + 2], &i);
	light->col.green = (double)ft_atoin(mlx->scene[*k + 2], &i);
	light->col.blue = (double)ft_atoin(mlx->scene[*k + 2], &i);
	if (mlx->scene[*k + 2][i] != ')')
		return (-1);
	i = 6;
	light->pos.x = (double)ft_atoin(mlx->scene[*k + 3], &i);
	light->pos.y = (double)ft_atoin(mlx->scene[*k + 3], &i);
	light->pos.z = (double)ft_atoin(mlx->scene[*k + 3], &i);
	if (mlx->scene[*k + 3][i] != ')')
		return (-1);
	light->next = NULL;
	mlx->light = ft_add_light_link(mlx, light);
	*k += 5;
	return (0);
}

int			ft_add_plane(t_mlx *mlx, int *k, int i)
{
	t_obj	*plane;

	if (!(plane = (t_obj *)malloc(sizeof(t_obj))))
		return (-1);
	plane->type = PLANE;
	if (ft_strcmp(mlx->scene[*k + 1], "	{") != 0 || \
			ft_strcmp(mlx->scene[*k + 5], "	}") != 0)
		return (-1);
	if (ft_col_n_pos(mlx, plane, *k) == -1 || \
			ft_strncmp(mlx->scene[*k + 4], "		rot(", 6) != 0)
		return (-1);
	plane->rot.x = (double)ft_atoin(mlx->scene[*k + 4], &i);
	plane->rot.y = (double)ft_atoin(mlx->scene[*k + 4], &i);
	plane->rot.z = (double)ft_atoin(mlx->scene[*k + 4], &i);
	if (mlx->scene[*k + 4][i] != ')')
		return (-1);
	plane->next = NULL;
	mlx->obj = ft_add_object(mlx, plane);
	*k += 6;
	return (0);
}

int			ft_add_cyl_cone(t_mlx *mlx, int *k, int t, int i)
{
	t_obj	*link;

	if (!(link = (t_obj *)malloc(sizeof(t_obj))))
		return (-1);
	if (ft_strcmp(mlx->scene[*k + 1], "	{") != 0 || \
			ft_strcmp(mlx->scene[*k + 6], "	}") != 0 || (link->type = t) != t)
		return (-1);
	if (ft_col_n_pos(mlx, link, *k) == -1 || \
			ft_strncmp(mlx->scene[*k + 4], "		rot(", 6) != 0)
		return (-1);
	link->rot.x = (double)ft_atoin(mlx->scene[*k + 4], &i);
	link->rot.y = (double)ft_atoin(mlx->scene[*k + 4], &i);
	link->rot.z = (double)ft_atoin(mlx->scene[*k + 4], &i);
	if (mlx->scene[*k + 4][i] != ')')
		return (-1);
	if (ft_strncmp(mlx->scene[*k + 5], "		size(", 7) != 0)
		return (-1);
	i = 7;
	link->size = ft_atoin(mlx->scene[*k + 5], &i);
	if (mlx->scene[*k + 5][i] != ')')
		return (-1);
	link->next = NULL;
	mlx->obj = ft_add_object(mlx, link);
	*k += 7;
	return (0);
}

int			ft_add_sphere(t_mlx *mlx, int *k, int i)
{
	t_obj	*sphere;

	if (!(sphere = (t_obj *)malloc(sizeof(t_obj))))
		return (-1);
	sphere->type = SPHERE;
	if (ft_strcmp(mlx->scene[*k + 1], "	{") != 0 || \
			ft_strcmp(mlx->scene[*k + 5], "	}") != 0)
		return (-1);
	if (ft_col_n_pos(mlx, sphere, *k) == -1)
		return (-1);
	if (ft_strncmp(mlx->scene[*k + 4], "		size(", 7) != 0)
		return (-1);
	sphere->size = ft_atoin(mlx->scene[*k + 4], &i);
	if (mlx->scene[*k + 4][i] != ')')
		return (-1);
	sphere->next = NULL;
	mlx->obj = ft_add_object(mlx, sphere);
	*k += 6;
	return (0);
}
