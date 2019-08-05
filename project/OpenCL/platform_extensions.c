/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   platform_extensions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:13:57 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/26 20:20:50 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

/*
** Список расширений, поддерживаемых платформой.
** Определенные расширения поддерживаются всеми устройствами на этой платформе.
** 1: Платформа.
*/

cl_uint	platform_extensions(cl_platform_id plat_id)
{
	cl_uint	err;
	char	*str;
	size_t	size;

	if ((err = clGetPlatformInfo(plat_id, CL_PLATFORM_EXTENSIONS, 0, 0, &size)))
		return (err);
	if (!(str = (char*)malloc(sizeof(char) * size)))
		return (1000);
	if ((err = clGetPlatformInfo(plat_id, CL_PLATFORM_EXTENSIONS,
													size, str, 0)))
	{
		free(str);
		return (err);
	}
	printf("	Extensions:	%s\n", str);
	return (0);
}
