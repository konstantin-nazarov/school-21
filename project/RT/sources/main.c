/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik-prog <lyahasik-prog@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 14:39:33 by dhorker           #+#    #+#             */
/*   Updated: 2019/08/17 18:36:50 by lyahasik-pr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define STB_IMAGE_IMPLEMENTATION
#include "headlines.h"

int	main()
{
	t_project		project;
	void			*img;

	project.scene = (t_scene*)malloc(sizeof(t_scene));
	create_scene(project.scene);
	create_window(&project);
	project.sdl->img = (t_sdl_img*)malloc(sizeof(t_sdl_img));
	project.img_buf = create_texture("texture/test_3.jpg", project.sdl->img);
	// project.img_buf = create_texture("texture/red.jpg", project.sdl->img);
	filling_img(&project);
	// import_img("texture/test_2.jpg", &project);
	render_show(&project);
	catching_events(&project);
	return (0);
}
