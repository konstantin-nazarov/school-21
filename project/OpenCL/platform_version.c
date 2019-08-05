/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   platform_version.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:13:31 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/26 20:20:37 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

/*
** Версия OpenCL.
** 1: Платформа.
*/

cl_uint	platform_version(cl_platform_id plat_id)
{
	cl_uint	err;
	char	*str;
	size_t	size;

	if ((err = clGetPlatformInfo(plat_id, CL_PLATFORM_VERSION, 0, 0, &size)))
		return (err);
	if (!(str = (char*)malloc(sizeof(char) * size)))
		return (1000);
	if ((err = clGetPlatformInfo(plat_id, CL_PLATFORM_VERSION, size, str, 0)))
	{
		free(str);
		return (err);
	}
	printf("	Version:	%s\n", str);
	return (0);
}
