/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik-prog <lyahasik-prog@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:44:22 by lyahasik-pr       #+#    #+#             */
/*   Updated: 2019/08/16 20:03:11 by lyahasik-pr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headlines.h"

unsigned char	*create_texture(const char *str, t_sdl_img *img)
{
	unsigned char	*texture;

	stbi_set_flip_vertically_on_load(0);
	stbi_info(
		str,
		&(img->width),
		&(img->height),
		&(img->palette));
	printf("img: %d - %d - %d\n", img->width, img->height, img->palette);
	texture = stbi_load(
		str,
		&img->width,
		&img->height,
		&img->palette,
		img->palette);
	return (texture);
}

void	texture_from_buffer(t_project *project)
{
	if ((project->sdl->surface = SDL_CreateRGBSurfaceWithFormatFrom(
			(void*)project->img_buf,
			project->sdl->img->width,
			project->sdl->img->height,
			project->sdl->img->palette * 8,
			project->sdl->img->palette * project->sdl->img->width,
			SDL_PIXELFORMAT_RGB24)) == 0)
		printf("Error %s", SDL_GetError());
	project->sdl->img->data = SDL_CreateTextureFromSurface(
		project->sdl->renderer,
		project->sdl->surface);
	SDL_FreeSurface(project->sdl->surface);
}

void	import_img(const char *str, t_project *project)
{
	project->sdl->img = (t_sdl_img*)malloc(sizeof(t_sdl_img));
	project->img_buf = create_texture(str, project->sdl->img);
	texture_from_buffer(project);
	project->sdl->img->rect.x = 0;
	project->sdl->img->rect.y = 0;
	project->sdl->img->rect.w = project->sdl->img->width;
	project->sdl->img->rect.h = project->sdl->img->height;
}
