/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_lf_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:52:03 by fhagrave          #+#    #+#             */
/*   Updated: 2019/05/13 11:52:04 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_presition_lf(unsigned int res[MAX_DIGITS_LF], unsigned int pres,
		unsigned int point, unsigned int *length)
{
	if (point == 0 && pres != 0)
		add_zeroes_to_tail_lf(res, pres, *length + pres);
	if (point != 0)
	{
		if (pres > point)
		{
			add_zeroes_to_tail_lf(res, pres - point, *length);
			if (point >= *length)
				*length = pres + 1;
			else
				*length += pres - point;
		}
		else if (pres < point)
		{
			round_from_tail_lf(res, point - pres, *length);
			if (point >= *length)
				*length = pres + 1;
			else
				help_norme_lf(res, pres, point, length);
		}
		else if (pres == point && point >= *length)
			*length = pres + 1;
	}
}

void	help_norme_lf(unsigned int res[MAX_DIGITS_LF], unsigned int pres,
		unsigned int point, unsigned int *length)
{
	*length += pres - point;
	if (pres == 0 && res[*length - 1] == 0 && res[*length] == 1)
		(*length)++;
}
