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

#include "Headers/SDL.h"
#include <stdio.h>

int	main()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		printf("Error %s", SDL_GetError());
	return (0);
}
