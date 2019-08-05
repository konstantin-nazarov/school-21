/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   platform_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:12:37 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/26 20:20:00 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

/*
** Название платформы.
** 1: Платформа.
*/

cl_uint	platform_name(cl_platform_id plat_id)
{
	cl_uint	err;
	char	*str;
	size_t	size;

	if ((err = clGetPlatformInfo(plat_id, CL_PLATFORM_NAME, 0, 0, &size)))
		return (err);
	if (!(str = (char*)malloc(sizeof(char) * size)))
		return (1000);
	if ((err = clGetPlatformInfo(plat_id, CL_PLATFORM_NAME, size, str, 0)))
	{
		free(str);
		return (err);
	}
	printf("	Name:		%s\n", str);
	return (0);
}
