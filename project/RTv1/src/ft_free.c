/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:29:48 by krakharo          #+#    #+#             */
/*   Updated: 2019/06/17 15:29:50 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

t_obj	*copy_obj(t_obj *obj)
{
	t_obj	*new;

	if (!(new = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	if (obj && new)
	{
		new->type = obj->type;
		new->size = obj->size;
		new->rot = (t_vec){obj->rot.x, obj->rot.y, obj->rot.z};
		new->pos = (t_vec){obj->pos.x, obj->pos.y, obj->pos.z};
		new->col.red = obj->col.red;
		new->col.green = obj->col.green;
		new->col.blue = obj->col.blue;
		new->next = NULL;
		if (new && obj->next)
			new->next = copy_obj(obj->next);
		return (new);
	}
	return (NULL);
}

void	ft_copy(t_mlx *mlx, t_th *th)
{
	th->spec = mlx->spec;
	th->maxref = mlx->maxref;
	th->pref = mlx->pref;
	th->cpt = 0;
	th->cam_pos = (t_vec){mlx->cam_pos.x, mlx->cam_pos.y, mlx->cam_pos.z};
	th->cam_dir = (t_vec){mlx->cam_dir.x, mlx->cam_dir.y, mlx->cam_dir.z};
	th->ray_dir = (t_vec){mlx->ray_dir.x, mlx->ray_dir.y, mlx->ray_dir.z};
	th->light = copy_obj(mlx->light);
	th->obj = copy_obj(mlx->obj);
	th->bpp = mlx->bpp;
	th->size_line = mlx->size_line;
	th->d = mlx->d;
	th->aa = mlx->aa;
}

int		ft_free_lists(t_obj *lgt, t_obj *obj)
{
	t_obj	*fst;
	t_obj	*tmp;

	fst = obj;
	while (fst != NULL)
	{
		tmp = fst->next;
		free(fst);
		fst = tmp;
	}
	fst = lgt;
	while (fst != NULL)
	{
		tmp = fst->next;
		free(fst);
		fst = tmp;
	}
	return (-1);
}

int		ft_free_arg(t_mlx *mlx, char *buf, int stat)
{
	if (stat == 0)
		free(buf);
	else if (stat == 1)
	{
		ft_putendl("ERROR: Dynamic memory allocation failed");
		free(mlx->scene);
	}
	else if (stat == 2)
	{
		ft_putendl("ERROR: Scene descriptor incorrect or incomplete");
		free(mlx->scene);
	}
	else if (stat == 3)
	{
		ft_putendl("ERROR: Dynamic memory allocation failed");
		free(mlx->scene);
		ft_free_lists(mlx->light, mlx->obj);
	}
	return (-1);
}

double	*ft_average(double *r, double *tab)
{
	r[0] += ft_clamp(tab[0], 0.0, 1.0);
	r[1] += ft_clamp(tab[1], 0.0, 1.0);
	r[2] += ft_clamp(tab[2], 0.0, 1.0);
	return (r);
}
