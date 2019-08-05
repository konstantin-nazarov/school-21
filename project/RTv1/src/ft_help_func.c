/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:30:30 by krakharo          #+#    #+#             */
/*   Updated: 2019/06/17 15:30:31 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

void		ft_strjoinl_free(char *s1, char *s2, int type)
{
	if (type == 'L')
		free(s1);
	else if (type == 'R')
		free(s2);
	else if (type == 'B')
	{
		free(s1);
		free(s2);
	}
}

char		*ft_strjoinl(char *s1, char *s2, char type)
{
	char	*n;
	int		i[2];

	i[0] = 0;
	while (s1[i[0]])
		i[0]++;
	i[1] = 0;
	while (s2[i[1]])
		i[1]++;
	n = (char *)malloc(sizeof(char) * (i[0] + i[1] + 1));
	i[0] = 0;
	while (s1[i[0]])
	{
		n[i[0]] = s1[i[0]];
		i[0]++;
	}
	i[1] = 0;
	while (s2[i[1]])
	{
		n[i[0] + i[1]] = s2[i[1]];
		i[1]++;
	}
	ft_strjoinl_free(s1, s2, type);
	n[i[0] + i[1]] = '\0';
	return (n);
}

int			ft_atoin(char *str, int *k)
{
	int		s;
	int		r;

	r = 0;
	s = 1;
	while (str[*k] >= 0 && str[*k] <= 32)
		(*k)++;
	if (str[*k] == '-')
		s = -1;
	if (str[*k] == '+' || str[*k] == '-')
		(*k)++;
	while (str[*k] && str[*k] >= '0' && str[*k] <= '9')
	{
		r = r * 10 + str[*k] - '0';
		(*k)++;
	}
	return (s * r);
}

int			ft_res_gnl(char **line, char *buf_save)
{
	char	*eol;

	eol = ft_strchr(buf_save, '\n');
	if (NULL != eol)
	{
		*eol = '\0';
		*line = ft_strdup(buf_save);
		ft_memmove(buf_save, &eol[1], ft_strlen(&eol[1]) + 1);
		return (1);
	}
	if (0 < ft_strlen(buf_save))
	{
		*line = ft_strdup(buf_save);
		*buf_save = '\0';
		return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char	*buf_save = NULL;
	char		buffer[BUFF_SIZE + 1];
	char		*line_tmp;
	int			ret;

	if (NULL == line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (NULL == buf_save)
		buf_save = (char *)malloc(sizeof(char));
	while (!ft_strchr(buf_save, '\n'))
	{
		ret = read(fd, buffer, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (0 == ret)
			break ;
		buffer[ret] = '\0';
		line_tmp = ft_strjoinl(buf_save, buffer, 'L');
		buf_save = line_tmp;
	}
	return (ft_res_gnl(line, buf_save));
}
