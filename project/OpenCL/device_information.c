/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device_information.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:19:24 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/26 20:22:33 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

/*
** Перечень свойств устройств.
** 1: Массив устройств.
** 2: Количество устройств.
*/

cl_uint	device_information(cl_device_id *dev_id, cl_uint dev_count)
{
	cl_uint	err;
	size_t	i;

	i = -1;
	while (++i < dev_count)
	{
		printf("\nDevice №%lu\n", i + 1);
		if ((err = device_name(dev_id[i])))
			return (err);
		if ((err = device_vendor(dev_id[i])))
			return (err);
		if ((err = device_type(dev_id[i])))
			return (err);
		if ((err = device_profile(dev_id[i])))
			return (err);
		if ((err = device_max_compute_units(dev_id[i])))
			return (err);
		if ((err = device_max_work_group_size(dev_id[i])))
			return (err);
	}
	return (0);
}
