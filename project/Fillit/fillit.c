/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:24:22 by ccolemon          #+#    #+#             */
/*   Updated: 2019/03/03 19:25:57 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Подстановка/удаление фигуры
*/

static void			set_or_del(unsigned short *matrix, t_fill *tet, int i)
{
	matrix[tet[i].y] ^= (unsigned short)LINE(0) << tet[i].x;
	matrix[tet[i].y + 1] ^= (unsigned short)LINE(1) << tet[i].x;
	matrix[tet[i].y + 2] ^= (unsigned short)LINE(2) << tet[i].x;
	matrix[tet[i].y + 3] ^= (unsigned short)LINE(3) << tet[i].x;
}

/*
** Проверка возможности подстановки
*/

static int			check_lines(unsigned short *matrix, t_fill *tet, int i)
{
	if (matrix[tet[i].y] & ((unsigned short)LINE(0) << tet[i].x) ||
		matrix[tet[i].y + 1] & ((unsigned short)LINE(1) << tet[i].x) ||
		matrix[tet[i].y + 2] & ((unsigned short)LINE(2) << tet[i].x) ||
		matrix[tet[i].y + 3] & ((unsigned short)LINE(3) << tet[i].x))
		END;
	set_or_del(matrix, tet, i);
	SUCCESS;
}

/*
** Рекурсивная подстановка фигур
*/

static int			solve(unsigned short *matrix, t_fill *tet, int size, int i)
{
	int n;

	CHECK_SIZE((!tet[i].id), size);
	n = tet[i].n;
	tet[i].y = (n < 0) ? -1 : tet[n].y - 1;
	while (++tet[i].y <= size - tet[i].tet->height)
	{
		tet[i].x = (tet[i].y != tet[n].y) ? -1
										: tet[n].x - 2 + tet[i].tet->width;
		while (++tet[i].x <= size - tet[i].tet->width)
			if (check_lines(matrix, tet, i))
			{
				CHECK_SIZE((solve(matrix, tet, size, ++i)), size);
				set_or_del(matrix, tet, --i);
			}
	}
	END;
}

/*
** Создание битового поля для перебора, увеличение матрицы (если требуется)
*/

int					fillit(t_fill *tet, int size)
{
	unsigned short	matrix[16];

	ft_bzero(matrix, sizeof(unsigned short) * 16);
	size--;
	while (!(solve(matrix, tet, ++size, 0)))
		ft_bzero(matrix, sizeof(unsigned short) * 16);
	return (size);
}
