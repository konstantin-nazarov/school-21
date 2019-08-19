/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 18:53:39 by dhorker           #+#    #+#             */
/*   Updated: 2019/07/28 19:12:11 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <stdio.h>
#include "libft.h"

int	main()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		printf("Error %s", SDL_GetError());

	SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (win == 0)
		printf("Error %s", SDL_GetError());
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr)
		printf("Error %s", SDL_GetError());
	

	return (0);
}
