/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik-prog <lyahasik-prog@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:38:30 by lyahasik-pr       #+#    #+#             */
/*   Updated: 2019/08/19 19:21:22 by lyahasik-pr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headlines.h"

void	mouse_down(t_project *project, SDL_Event event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		direction_camera(project, event.button.x, event.button.y);
		project->scene->obj = -1;
		intersection(project->scene, project->scene->camera[0]->pos, project->scene->camera[0]->dir);
		if (project->scene->obj != -1)
			project->scene->change = project->scene->object[project->scene->obj];
		else
			project->scene->change = NULL;
	}
}

// char	reposition_x(double *x, const Uint8 *keyboard)
// {
// 	if ((keyboard[SDL_SCANCODE_KP_7]))
// 	{
// 		*x += 10;
// 		return (1);
// 	}
// 	else if ((keyboard[SDL_SCANCODE_KP_4]))
// 	{
// 		*x -= 10;
// 		return (1);
// 	}
// 	return(0);
// }

// char	reposition_y(double *y, const Uint8 *keyboard)
// {
// 	if ((keyboard[SDL_SCANCODE_KP_8]))
// 	{
// 		*y += 10;
// 		return (1);
// 	}
// 	else if ((keyboard[SDL_SCANCODE_KP_5]))
// 	{
// 		*y -= 10;
// 		return (1);
// 	}
// 	return(0);
// }

// char	reposition_z(double *z, const Uint8 *keyboard)
// {
// 	if ((keyboard[SDL_SCANCODE_KP_9]))
// 	{
// 		*z += 10;
// 		return (1);
// 	}
// 	else if ((keyboard[SDL_SCANCODE_KP_6]))
// 	{
// 		*z -= 10;
// 		return (1);
// 	}
// 	return(0);
// }

// char	change_light(t_scene *scene, const Uint8 *keyboard)
// {
// 	if ((reposition_x(&scene->light[1]->pos.x, keyboard)))
// 		return (1);
// 	else if ((reposition_y(&scene->light[1]->pos.y, keyboard)))
// 		return (1);
// 	else if ((reposition_z(&scene->light[1]->pos.z, keyboard)))
// 		return (1);
// 	return (0);
// }

// char	change_object(t_scene *scene, const Uint8 *keyboard)
// {
// 	if ((reposition_x(&scene->change->pos.x, keyboard)))
// 		return (1);
// 	else if ((reposition_y(&scene->change->pos.y, keyboard)))
// 		return (1);
// 	else if ((reposition_z(&scene->change->pos.z, keyboard)))
// 		return (1);
// 	return (0);
// }

// void	keyboard_down(t_project *project, const Uint8 *keyboard)
// {
// 	if ((project->scene->change))
// 	{
// 		if ((change_object(project->scene, keyboard)))
// 		{
// 			filling_img(project);
// 			render_show(project);
// 		}
// 	}
// 	else
// 		if ((change_light(project->scene, keyboard)))
// 		{
// 			filling_img(project);
// 			render_show(project);
// 		}
// }

void	change_object(t_project *project, const Uint8 *keyboard)
{
	if ((keyboard[SDL_SCANCODE_KP_7]))
		project->scene->change->pos.x += 10;
	else if ((keyboard[SDL_SCANCODE_KP_4]))
		project->scene->change->pos.x -= 10;
	else if ((keyboard[SDL_SCANCODE_KP_8]))
		project->scene->change->pos.y += 10;
	else if ((keyboard[SDL_SCANCODE_KP_5]))
		project->scene->change->pos.y -= 10;
	else if ((keyboard[SDL_SCANCODE_KP_9]))
		project->scene->change->pos.z += 10;
	else if ((keyboard[SDL_SCANCODE_KP_6]))
		project->scene->change->pos.z -= 10;
	else if ((keyboard[SDL_SCANCODE_UP]))
		project->scene->change->rot.x -= 0.01;
	else if ((keyboard[SDL_SCANCODE_DOWN]))
		project->scene->change->rot.x += 0.01;
	else if ((keyboard[SDL_SCANCODE_LEFT]))
		project->scene->change->rot.y -= 0.01;
	else if ((keyboard[SDL_SCANCODE_RIGHT]))
		project->scene->change->rot.y += 0.01;
	else
		return ;
	if (project->scene->change->rot.x < -1)
		project->scene->change->rot.x = 1;
	else if (project->scene->change->rot.x > 1)
		project->scene->change->rot.x = -1;
	else if (project->scene->change->rot.y < -1)
		project->scene->change->rot.y = 1;
	else if (project->scene->change->rot.y > 1)
		project->scene->change->rot.y = -1;
	filling_img(project);
	render_show(project);
}

void	change_light(t_project *project, const Uint8 *keyboard)
{
	if ((keyboard[SDL_SCANCODE_KP_7]))
		project->scene->light[1]->pos.x += 10;
	else if ((keyboard[SDL_SCANCODE_KP_4]))
		project->scene->light[1]->pos.x -= 10;
	else if ((keyboard[SDL_SCANCODE_KP_8]))
		project->scene->light[1]->pos.y += 10;
	else if ((keyboard[SDL_SCANCODE_KP_5]))
		project->scene->light[1]->pos.y -= 10;
	else if ((keyboard[SDL_SCANCODE_KP_9]))
		project->scene->light[1]->pos.z += 10;
	else if ((keyboard[SDL_SCANCODE_KP_6]))
		project->scene->light[1]->pos.z -= 10;
	else
		return ;
	filling_img(project);
	render_show(project);
}

void	keyboard_down(t_project *project, const Uint8 *keyboard)
{
	if ((project->scene->change))
		change_object(project, keyboard);
	else
		change_light(project, keyboard);
}

char	check_event(t_project *project, SDL_Event event, const Uint8 *keyboard)
{
	if (event.type == SDL_QUIT || (keyboard[SDL_SCANCODE_ESCAPE]))
		return (0);
	if (event.type == SDL_MOUSEBUTTONDOWN)
		mouse_down(project, event);
	else if (event.type == SDL_KEYDOWN)
		keyboard_down(project, keyboard);
	return (1);
}

void	catching_events(t_project *project)
{
	SDL_Event	event;
	const Uint8	*keyboard;

	keyboard = SDL_GetKeyboardState(0);
	while (1)
	{
		SDL_PollEvent(&event);
		SDL_PumpEvents();
		if (!(check_event(project, event, keyboard)))
			break ;
	}
	destroy_program(project);
}
