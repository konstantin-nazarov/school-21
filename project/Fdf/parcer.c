/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:40:56 by dhorker           #+#    #+#             */
/*   Updated: 2019/03/09 17:01:35 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ft_ab(char *str)
{
	int			n;
	unsigned	num;

	num = 0;
	n = -1;
	while (str[++n] != ' ' && str[n] != '\0')
		;
	while (--n >= 0)
	{
		if (ISDIGIT(*str))
			num += (*str - 48) * pow(16, n);
		else if (ISLALPHA(*str))
			num += (*str - 87) * pow(16, n);
		else if (ISHALPHA(*str))
			num += (*str - 55) * pow(16, n);
		else
			ERR;
		str++;
	}
	return (num);
}

void			del_matrix(t_point **matrix, int h)
{
	while (h--)
		free(matrix[h]);
	free(matrix);
}

t_point			**create_matrix(int h, int w)
{
	t_point		**matrix;

	CHECK_NULL((matrix = (t_point **)malloc(sizeof(t_point *) * h)));
	while (h--)
		if (!(matrix[h] = (t_point *)malloc(sizeof(t_point) * w)))
		{
			del_matrix(matrix, h);
			break ;
		}
	return ((matrix) ? matrix : NULL);
}

t_point			**fill(t_fdf *map, int j)
{
	t_point		**matrix;
	char		*colr;
	char		*tmp;
	int			i;

	CHECK_NULL((matrix = create_matrix(map->y, map->x)));
	while ((i = -1) && ++j < map->y)
		while (++i < map->x)
		{
			F_WH(*map->mtx == 32 && map->mtx, map->mtx++);
			if (map->mtx)
			{
				MATRIX.x = i;
				MATRIX.y = j;
				MATRIX.z = ft_atoi(map->mtx);
				colr = ft_strsub(map->mtx, 0, ft_countchars(map->mtx, 32, 0));
				tmp = ft_strstr(colr, "0x");
				MATRIX.c.argb = tmp ? ft_ab(tmp + 2) : DEFAULT;
				MATRIX.tmp_c.argb = MATRIX.c.argb;
				F_WH(*map->mtx != 32 && map->mtx, map->mtx++);
				free(colr);
			}
		}
	return (matrix);
}

int				valid(t_fdf map, int check, int i)
{
	CHECK_ERR((ISDIGIT(*map.mtx) || (*map.mtx == ' ') ||
				(*map.mtx == '-' && ISDIGIT(*(map.mtx + 1)))));
	while ((i = 3) && *map.mtx)
	{
		check += ((*map.mtx == ' ') ||
		(*map.mtx == '-' && ISDIGIT(*(map.mtx + 1))) ||
		(ISDIGIT(*map.mtx) && ISDIGIT(*(map.mtx + 1))) ||
		(ISDIGIT(*map.mtx) && *(map.mtx + 1) == ' ')) ? 0 : 1;
		if (check == 1 && ISDIGIT(*map.mtx) && ft_strnstr(map.mtx, ",0x", 4))
		{
			check = 0;
			while (map.mtx[++i] && map.mtx[i] != ' ' && !check)
				check += ISHEX(map.mtx[i]) ? 0 : 1;
			check += (i == 4 || i > 12) ? 1 : 0;
		}
		if (check)
			break ;
		map.mtx += (i == 3) ? 1 : i;
	}
	return (check ? -1 : 0);
}
