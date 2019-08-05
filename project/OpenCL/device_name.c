/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:19:05 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/26 20:22:22 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

/*
** Название устройства.
** 1: Устройство.
*/

cl_uint	device_name(cl_device_id dev_id)
{
	cl_uint	err;
	char	*str;
	size_t	size;

	if ((err = clGetDeviceInfo(dev_id, CL_DEVICE_NAME, 0, 0, &size)))
		return (err);
	if (!(str = (char*)malloc(sizeof(char) * size)))
		return (1000);
	if ((err = clGetDeviceInfo(dev_id, CL_DEVICE_NAME, size, str, 0)))
	{
		free(str);
		return (err);
	}
	printf("	Name:			%s\n", str);
	return (0);
}
