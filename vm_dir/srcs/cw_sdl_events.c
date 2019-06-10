/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl_events.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 13:30:11 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/09 18:38:23 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
** SDL function to increase or decrease speed (+ | -)
**-----------------------------------------------------------------------
*/

static void	handle_speed(t_visu *visu)
{
	if (visu->event.key.keysym.sym == SDLK_KP_MINUS)
	{
		visu->speed -= 1;
		if (visu->speed == 0)
			visu->speed = -1;
	}
	if (visu->event.key.keysym.sym == SDLK_KP_PLUS)
	{
		visu->speed += 1;
		if (visu->speed == 0)
			visu->speed = 1;
	}
}

/*
**-----------------------------------------------------------------------
** SDL function to quit/reduce window or manage speed
**-----------------------------------------------------------------------
*/

void		handle_events(t_visu *visu, t_core *cw)
{
	SDL_PollEvent(&visu->event);
	if (visu->event.type == SDL_WINDOWEVENT &&
			visu->event.window.event == SDL_WINDOWEVENT_RESIZED)
		responsive(visu, cw, RESIZE);
	if (visu->event.type == SDL_QUIT)
		quit_sdl(visu, cw);
	if (visu->event.type == SDL_KEYDOWN)
	{
		handle_speed(visu);
		if (visu->event.key.keysym.sym == SDLK_SPACE)
			visu->pause = visu->pause ? 0 : 1;
	}
}
