/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device_max_compute_units.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:18:17 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/26 20:22:08 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

/*
** Максимальное количество рабочих групп.
** 1: Устройство.
*/

cl_uint	device_max_compute_units(cl_device_id dev_id)
{
	cl_uint	err;
	cl_uint	info_num;

	if ((err = clGetDeviceInfo(dev_id, CL_DEVICE_MAX_COMPUTE_UNITS,
													4, &info_num, 0)))
		return (err);
	printf("	Max work group:		%lu\n", (size_t)info_num);
	return (0);
}
