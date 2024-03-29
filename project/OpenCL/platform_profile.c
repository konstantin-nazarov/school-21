/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   platform_profile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:13:04 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/26 20:20:17 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

/*
** Имя профиля OpenCL, поддерживаемое реализацией.
** 1: Платформа.
*/

cl_uint	platform_profile(cl_platform_id plat_id)
{
	cl_uint	err;
	char	*str;
	size_t	size;

	if ((err = clGetPlatformInfo(plat_id, CL_PLATFORM_PROFILE, 0, 0, &size)))
		return (err);
	if (!(str = (char*)malloc(sizeof(char) * size)))
		return (1000);
	if ((err = clGetPlatformInfo(plat_id, CL_PLATFORM_PROFILE, size, str, 0)))
	{
		free(str);
		return (err);
	}
	printf("	Profile:	%s\n", str);
	return (0);
}
