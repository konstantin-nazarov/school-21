/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_dop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:41:25 by dhorker           #+#    #+#             */
/*   Updated: 2019/03/08 14:41:25 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				op(int color, unsigned char op)
{
	return (color |= (op << 24));
}

unsigned char	fac(float x)
{
	unsigned char	op;

	while (x >= 0)
		x--;
	x++;
	op = x * 255;
	return (op);
}
