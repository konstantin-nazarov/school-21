/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik-prog <lyahasik-prog@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:32:58 by lyahasik-pr       #+#    #+#             */
/*   Updated: 2019/08/08 23:51:27 by lyahasik-pr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headlines.h"

void	destroy_program(t_project *project)
{
	// stbi_image_free(project->img_buf);
	SDL_DestroyTexture(project->sdl->img->data);
	SDL_DestroyRenderer(project->sdl->renderer);
	SDL_DestroyWindow(project->sdl->window);
	SDL_Quit();
}

void	render_show(t_project *project)
{
	SDL_RenderClear(project->sdl->renderer);
	SDL_RenderCopy(
		project->sdl->renderer,
		project->sdl->img->data,
		NULL,
		&project->sdl->img->rect);
	SDL_RenderPresent(project->sdl->renderer);
}

void	create_window(t_project *project)
{
	project->sdl = (t_sdl*)malloc(sizeof(t_sdl));
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		printf("Error %s", SDL_GetError());
	if ((project->sdl->window = SDL_CreateWindow(
			"RT",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			WINDOW_W,
			WINDOW_H,
			SDL_WINDOW_SHOWN)) == 0)
		printf("Error %s", SDL_GetError());
	if ((project->sdl->renderer = SDL_CreateRenderer(
			project->sdl->window,
			-1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE)) == 0)
		printf("Error %s", SDL_GetError());
}
