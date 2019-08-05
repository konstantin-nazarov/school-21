/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 20:49:16 by krakharo          #+#    #+#             */
/*   Updated: 2019/06/18 20:49:17 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

void		ft_pe(char *err)
{
	ft_putendl(err);
}

char		*ft_check_buf(char *scn)
{
	if (ft_strstr(scn, "scene\n{") == NULL)
		return (NULL);
	if (ft_strstr(scn, "content\n{") == NULL)
		return (NULL);
	return (scn);
}

double		ft_clamp(double value, double min, double max)
{
	if (value < min)
		value = min;
	if (value > max)
		value = max;
	return (value);
}

void		mlx_ps(t_mlx *mlx, int x, int y, char *str)
{
	mlx_string_put(mlx->mlx, mlx->win, x, y, WHITE, str);
}
