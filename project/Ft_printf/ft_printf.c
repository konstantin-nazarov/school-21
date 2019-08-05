/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:45:46 by dhorker           #+#    #+#             */
/*   Updated: 2019/04/30 17:08:32 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	do_spec(char **s, va_list *ap, t_spec spec)
{
	int		(*func[NUM])(va_list*, t_spec);
	char	specif[NUM];
	int		i;
	int		length;

	init_func_array(func);
	init_spec_array(specif);
	i = 0;
	length = 0;
	while (i < NUM)
	{
		if (**s == specif[i])
		{
			if (**s == 'Z' || **s == 'R' || **s == 'm'
				|| **s == '%' || **s == 'c' || **s == '\n')
				length = c_spec(ap, spec, **s);
			else
				length = func[i](ap, spec);
			(*s)++;
			break ;
		}
		i++;
	}
	return (length);
}

int	ft_printf(const char *format, ...)
{
	char	basa[NUM];
	va_list	ap;
	t_spec	spec;
	int		length;
	char	*s;

	init_spec_array(basa);
	ft_bzero(&spec, sizeof(t_spec));
	length = 0;
	s = (char*)format;
	va_start(ap, format);
	while (*s)
	{
		while (*s && *s != '%')
		{
			ft_putchar(*s++);
			length++;
		}
		s += (*s) ? 1 : 0;
		s += create_spec(&spec, s);
		length += do_spec(&s, &ap, spec);
		ft_bzero(&spec, sizeof(t_spec));
	}
	va_end(ap);
	return (length);
}
