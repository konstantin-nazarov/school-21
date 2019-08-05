/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:18:45 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/26 20:22:15 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

/*
** Тип устройства.
** 1: Устройство.
*/

cl_uint	device_type(cl_device_id dev_id)
{
	cl_uint			err;
	cl_device_type	*str;
	size_t			size;

	if ((err = clGetDeviceInfo(dev_id, CL_DEVICE_TYPE, 0, 0, &size)))
		return (err);
	if (!(str = (cl_device_type*)malloc(sizeof(cl_device_type) * size)))
		return (1000);
	if ((err = clGetDeviceInfo(dev_id, CL_DEVICE_TYPE, size, str, 0)))
	{
		free(str);
		return (err);
	}
	if (*str == CL_DEVICE_TYPE_CPU)
		printf("	Type:			CPU\n");
	else if (*str == CL_DEVICE_TYPE_GPU)
		printf("	Type:			GPU\n");
	else if (*str == CL_DEVICE_TYPE_ACCELERATOR)
		printf("	Type:			ACCELERATOR\n");
	else if (*str == CL_DEVICE_TYPE_DEFAULT)
		printf("	Type:			DEFAULT\n");
	return (0);
}
