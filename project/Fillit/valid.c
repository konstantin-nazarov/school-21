/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:13:49 by ccolemon          #+#    #+#             */
/*   Updated: 2019/03/13 20:12:35 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Зануление переменных
*/

static void				zeroxy(t_fill *tet, int i, int *val, unsigned short *t)
{
	while (++i < 4)
		val[i] = 0;
	t = 0;
	i = -1;
	while (++i < 27)
	{
		tet[i].x = 0;
		tet[i].y = 0;
		tet[i].n = -1;
		tet[i].id = 0;
	}
}

/*
** Поиск по базе, запоминание повторяющихся фигур
*/

static int				findtet(t_fill *tet, int k, t_base *base,
															unsigned short t)
{
	int					i;
	int					j;

	i = -1;
	while (++i < 19)
		if (base[i].temp.binshape == t)
		{
			tet[k].tet = &base[i];
			tet[k].id = 1;
			j = k;
			while (--j >= 0)
			{
				if (tet[k].tet->temp.binshape == tet[j].tet->temp.binshape)
				{
					tet[k].n = j;
					break ;
				}
			}
			SUCCESS;
		}
	END;
}

/*
** Подгон фигуры к верхнему углу посредством побитовых сдвигов
*/

static unsigned short	bitt(unsigned short t)
{
	if (t != 0)
	{
		while (!(t & (1 << 0)) && !(t & (1 << 4)) && !(t & (1 << 8))
												&& !(t & (1 << 12)))
			t = t >> 1;
		while (!(t & (1 << 0)) && !(t & (1 << 1)) && !(t & (1 << 2))
												&& !(t & (1 << 3)))
			t = t >> 4;
	}
	return (t);
}

/*
** Обработка символа, проверка символов после фигуры
*/

static int				valchar(char *str, int count, unsigned short *t, int e)
{
	if (*str == '#')
		*t |= (1 << count);
	else if (*str == '.')
		*t &= ~(1 << count);
	else if (*str == '\n' && count % 4 != 0)
		END;
	if (count == 15)
	{
		if (*(str + 2) != '\n' && *(str + 2) != '\0')
			return (0);
		else if (*(str + 2) == '\n')
			CHECK_END((*(str + 3) != '#' && *(str + 3) != '.'));
		if (!(*(str + 2)) && e)
			return (e);
	}
	SUCCESS;
}

/*
** val[0] - количество валидных фигур
** val[1] - порядковый номер символа в маске
** val[2] - номер тетримино в массиве валидности
** val[3] - количество \n в конце считывания тетримино
** Проверка на лишние символы, запись символа в соответствующий бит,
** подгон под шаблон, поиск по базе, проверка на символы после фигуры,
** подсчет символов фигуры, подсчет \n в каждой фигуре.
*/

int						valid(t_fill *tet, t_base *base, char *inp, int x)
{
	int					val[4];
	unsigned short		t;

	zeroxy(tet, -1, val, &t);
	while (*inp)
	{
		CHECK_END((*inp != '\n' && *inp != '.' && *inp != '#'));
		CHECK_NULL((valchar(inp, val[1], &t, val[0])));
		if (val[1] == 15)
		{
			CHECK_END(!(val[3] == 3) || !(t = bitt(t)));
			CHECK_NULL((findtet(tet, val[2]++, base, t)));
			CHECK_VAL(valchar(inp, val[1], &t, ++val[0]));
			val[3] = 0;
		}
		if (*inp++ != '\n')
		{
			inp += (val[1] == 15) ? 2 : 0;
			val[1] = (val[1] == 15) ? 0 : ++val[1];
		}
		else
			val[3]++;
	}
	return ((val[1]) ? 0 : val[0]);
}
