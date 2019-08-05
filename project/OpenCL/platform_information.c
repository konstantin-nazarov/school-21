/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   platform_information.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:15:15 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/26 20:21:11 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

/*
** Полная информация о платформах.
** 1: Массив платформ.
** 2: Количество платформ.
*/

cl_uint	platform_information(cl_platform_id *plat_id, cl_uint plat_count)
{
	cl_uint	err;
	size_t	i;

	i = -1;
	while (++i < plat_count)
	{
		printf("\nPlatform №%lu\n", i + 1);
		if ((err = platform_name(plat_id[i])))
			return (err);
		if ((err = platform_profile(plat_id[i])))
			return (err);
		if ((err = platform_version(plat_id[i])))
			return (err);
		if ((err = platform_extensions(plat_id[i])))
			return (err);
		if ((err = platform_vendor(plat_id[i])))
			return (err);
	}
	return (0);
}
