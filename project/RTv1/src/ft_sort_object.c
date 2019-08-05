/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:51:10 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/20 17:52:14 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

static char		*re_object(char *str1, char **str2)
{
	while (*str2[0] != '}')
		*str1++ = *str2[0]++;
	*str1++ = *str2[0];
	*str1++ = '\n';
	*str1++ = '	';
	return (str1);
}

static void		sort_stage_two(char *buf, char **tmp)
{
	while (buf)
	{
		if ((ft_memcmp(buf, "object(plane)", 13)))
			*tmp = re_object(*tmp, &buf);
		buf++;
		buf = ft_strstr(buf, "object");
	}
	*--tmp[0] = '}';
}

char			*sort_stage_one(char *buf)
{
	char	*tmp;
	char	*edit;
	char	*begin_buf;
	char	*begin_tmp;

	begin_tmp = ft_strdup(buf);
	tmp = ft_strstr(begin_tmp, "object");
	begin_buf = buf;
	buf = ft_strstr(buf, "object");
	edit = NULL;
	while (*buf)
	{
		if ((edit = ft_strstr(buf, "object(plane)")))
		{
			tmp = re_object(tmp, &edit);
			buf = edit;
		}
		edit = NULL;
		buf++;
	}
	sort_stage_two(ft_strstr(begin_buf, "object"), &tmp);
	free(begin_buf);
	return (begin_tmp);
}
