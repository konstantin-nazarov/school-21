/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device_profile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:15:49 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/26 20:21:33 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

/*
** Имя профиля OpenCL, поддерживаемое реализацией.
** 1: Устройство.
*/

cl_uint	device_profile(cl_device_id dev_id)
{
	cl_uint	err;
	char	*str;
	size_t	size;

	if ((err = clGetDeviceInfo(dev_id, CL_DEVICE_PROFILE, 0, 0, &size)))
		return (err);
	if (!(str = (char*)malloc(sizeof(char) * size)))
		return (1000);
	if ((err = clGetDeviceInfo(dev_id, CL_DEVICE_PROFILE, size, str, 0)))
	{
		free(str);
		return (err);
	}
	printf("	Profile:		%s\n", str);
	return (0);
}
