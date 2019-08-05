/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device_vendor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:16:09 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/26 20:21:41 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

/*
** Поставщик устройства.
** 1: Устройство.
*/

cl_uint	device_vendor(cl_device_id dev_id)
{
	cl_uint	err;
	char	*str;
	size_t	size;

	if ((err = clGetDeviceInfo(dev_id, CL_DEVICE_VENDOR, 0, 0, &size)))
		return (err);
	if (!(str = (char*)malloc(sizeof(char) * size)))
		return (1000);
	if ((err = clGetDeviceInfo(dev_id, CL_DEVICE_VENDOR, size, str, 0)))
	{
		free(str);
		return (err);
	}
	printf("	Vendor:			%s\n", str);
	return (0);
}
