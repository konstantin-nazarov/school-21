/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:55:26 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/13 13:57:47 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*insert_chars_into_float(const char *output,
			const char *insert_pointer, char insert_char, unsigned int ammount)
{
	char			*new_otput;
	unsigned int	i;
	char			*insert_pointer_copy;

	insert_pointer_copy = (char *)insert_pointer;
	new_otput = ft_strnew(ammount + ft_strlen(output));
	ft_strncpy(new_otput, output, insert_pointer - output);
	i = insert_pointer_copy - output;
	while (i < insert_pointer_copy - output + ammount)
		new_otput[i++] = insert_char;
	new_otput += insert_pointer_copy - output + ammount;
	ft_strcpy(new_otput, insert_pointer);
	new_otput -= insert_pointer_copy - output + ammount;
	return (new_otput);
}

void			init_f_spec(t_insert *insert, t_spec spec,
													unsigned int *precision)
{
	insert->symb = ' ';
	insert->sign = "";
	if (spec.u.f.dot_for_prec == 0)
		*precision = 6;
	else
		*precision = spec.prec;
}

void			check_for_inf_or_nan(char *virtual_output, t_spec *spec)
{
	if (ft_strcmp(virtual_output, "inf") == 0)
		spec->u.f.inf_flag = 1;
	if (ft_strcmp(virtual_output, "nan") == 0)
		spec->u.f.nan_flag = 1;
}

unsigned int	check_for_plus_or_space(t_spec spec,
		unsigned int below_zero_flag, t_insert *insert, char **virtual_output)
{
	char		*catch_old_pointer;

	if (spec.u.f.nan_flag == 0)
	{
		if (below_zero_flag)
			insert->sign = "-";
		else
		{
			if (PLUS_TOKEN)
				insert->sign = "+";
			else
			{
				if (SPACE_TOKEN)
					insert->sign = " ";
			}
		}
		catch_old_pointer = *virtual_output;
		*virtual_output = ft_strjoin(insert->sign, *virtual_output);
		free(catch_old_pointer);
		return (ft_strlen(insert->sign));
	}
	return (0);
}

void			check_for_minus_or_zero(t_insert *insert,
					char **virtual_output, t_spec spec, unsigned int length)
{
	char	*catch_old_pointer;

	insert->pointer = *virtual_output;
	if (MINUS_TOKEN)
		while (*(insert->pointer))
			(insert->pointer)++;
	else
	{
		if (ZERO_TOKEN && spec.u.f.inf_flag == 0 && spec.u.f.nan_flag == 0)
		{
			insert->symb = '0';
			insert->pointer += ft_strlen(insert->sign);
		}
	}
	if ((unsigned int)spec.width > length)
	{
		catch_old_pointer = *virtual_output;
		*virtual_output = insert_chars_into_float(*virtual_output,
		insert->pointer, insert->symb, (unsigned int)(spec.width) - length);
		free(catch_old_pointer);
	}
}
