/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device_max_work_group_size.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:16:29 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/26 20:22:00 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

/*
** Максимальное количество kernel в рабочей группе.
** 1: Устройство.
*/

cl_uint	device_max_work_group_size(cl_device_id dev_id)
{
	cl_uint	err;
	size_t	info_num;

	if ((err = clGetDeviceInfo(dev_id, CL_DEVICE_MAX_WORK_GROUP_SIZE,
													8, &info_num, 0)))
		return (err);
	printf("	Max work group size:	%lu\n", info_num);
	return (0);
}
