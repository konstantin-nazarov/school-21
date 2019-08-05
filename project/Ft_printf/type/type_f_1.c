/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:52:03 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/13 13:54:57 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	f_spec(va_list *ap, t_spec spec)
{
	unsigned int	precision;
	unsigned int	below_zero_flag;
	unsigned int	length;
	char			*virtual_output;
	t_insert		insert;

	init_f_spec(&insert, spec, &precision);
	virtual_output = ft_strnew(MAX_DIGITS_LLF);
	if (spec.mod[0] == 'L')
		length = float_point_llf(ap, precision, &below_zero_flag,
		&virtual_output);
	else
		length = float_point_lf(ap, precision, &below_zero_flag,
		&virtual_output);
	check_for_inf_or_nan(virtual_output, &spec);
	length += check_for_plus_or_space(spec, below_zero_flag, &insert,
	&virtual_output);
	check_for_minus_or_zero(&insert, &virtual_output, spec, length);
	ft_putstr_fast(virtual_output);
	length = ft_strlen(virtual_output);
	free(virtual_output);
	return (length);
}

int	float_point_lf(va_list *ap, unsigned int prec, unsigned int *sign,
													char **virtual_output)
{
	t_double_long		f;
	unsigned int		e;
	unsigned long int	m;
	int					length;

	f.dl = va_arg(*ap, double);
	*sign = (f.ulin >> S_BITS_LF);
	e = (f.ulin >> E_BITS_LF) & E_MASK_LF;
	m = e ? (f.ulin & M_MASK1_LF) | M_MASK2_LF : (f.ulin & M_MASK1_LF) << 1;
	if ((length = is_it_special_value_lf(virtual_output, e, m, prec)) == 0)
		length = start_processing_number_lf(virtual_output, e, m, prec);
	*virtual_output = *virtual_output - length;
	return (length);
}

int	float_point_llf(va_list *ap, unsigned int prec, unsigned int *sign,
													char **virtual_output)
{
	t_longdouble_long	f;
	unsigned int		e;
	unsigned long int	m;
	int					length;

	f.dl = va_arg(*ap, long double);
	*sign = (f.ulin >> S_BITS_LLF) & 0x1;
	e = (f.ulin >> E_BITS_LLF) & E_MASK_LLF;
	m = f.ulin & M_MASK1_LLF;
	if ((length = is_it_special_value_llf(virtual_output, e, m, prec)) == 0)
		length = start_processing_number_llf(virtual_output, e, m, prec);
	*virtual_output = *virtual_output - length;
	return (length);
}
