/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik-prog <lyahasik-prog@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:36:52 by lyahasik-pr       #+#    #+#             */
/*   Updated: 2019/08/17 19:44:50 by lyahasik-pr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headlines.h"

unsigned int	*create_img(t_sdl *sdl)
{
	sdl->img = (t_sdl_img*)malloc(sizeof(t_sdl_img));
	sdl->img->rect.x = 0;
	sdl->img->rect.y = 0;
	sdl->img->rect.w = WINDOW_W;
	sdl->img->rect.h = WINDOW_H;
	sdl->img->data = SDL_CreateTexture(
		sdl->renderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		WINDOW_W,
		WINDOW_H);
}

unsigned int	*lock_img(t_sdl *sdl)
{
	unsigned int	*buf;
	int				pitch;

	buf = (unsigned int*)malloc(sizeof(unsigned int*) * WINDOW_H * WINDOW_W);
	pitch = 0;
	SDL_LockTexture(
		sdl->img->data,
		0,
		(void**)&buf,
		&pitch);
	return (buf);
}

void	filling_img(t_project *project)
{
	int				x;
	int				y;
	unsigned int	*buf;

	y = -1;
	create_img(project->sdl);
	buf = lock_img(project->sdl);
	while (++y < WINDOW_H)
	{
		x = -1;
		while (++x < WINDOW_W)
		{
			direction_camera(project, x, y);
			buf[y * WINDOW_W + x] = ft_vec3_color(ray_trace(*project));
		}
	}
	SDL_UnlockTexture(project->sdl->img->data);
}
