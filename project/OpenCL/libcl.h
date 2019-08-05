/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:04:59 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/28 17:59:47 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCL_H

# define LIBCL_H

# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <OpenCL/cl.h>

cl_uint	platform_name(cl_platform_id plat_id);
cl_uint	platform_profile(cl_platform_id plat_id);
cl_uint	platform_version(cl_platform_id plat_id);
cl_uint	platform_extensions(cl_platform_id plat_id);
cl_uint	platform_vendor(cl_platform_id plat_id);
cl_uint	platform_information(cl_platform_id *plat_id, cl_uint plat_count);
cl_uint	device_profile(cl_device_id dev_id);
cl_uint	device_vendor(cl_device_id dev_id);
cl_uint	device_max_work_group_size(cl_device_id dev_id);
cl_uint	device_max_compute_units(cl_device_id dev_id);
cl_uint	device_type(cl_device_id dev_id);
cl_uint	device_name(cl_device_id dev_id);
cl_uint	device_information(cl_device_id *dev_id, cl_uint dev_count);

#endif
