/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl_events.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 13:30:11 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 09:08:00 by rcepre      ###    #+. /#+    ###.fr     */
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
	if (visu->speed > 1)
		visu->sound = 0;
}

static void	handle_sound(t_visu *visu)
{
	if (visu->event.key.keysym.sym == SDLK_m)
	{
		if (visu->sound)
			visu->sound = 0;
		else
		{
			visu->speed = -1;
			visu->sound = 1;
		}
	}
}

/*
**-----------------------------------------------------------------------
** SDL function to quit/reduce window or manage speed
**-----------------------------------------------------------------------
*/

void		handle_responsive(t_core *cw, t_visu *visu)
{
	if (visu->event.key.keysym.sym == SDLK_r)
	{
		if (visu->responsive_mode)
		{
			visu->responsive_mode = 0;
			SDL_SetWindowFullscreen(visu->win, SDL_WINDOW_FULLSCREEN_DESKTOP);
		}
		else
		{
			visu->responsive_mode = 1;
			SDL_SetWindowFullscreen(visu->win, 0);
			SDL_SetWindowMinimumSize(visu->win, 800, 800);
		}
		update_win_size(visu, cw, RESIZE);
	}
}

void		handle_events(t_visu *visu, t_core *cw)
{
	SDL_PollEvent(&visu->event);
	if (visu->event.type == SDL_WINDOWEVENT &&
			visu->event.window.event == SDL_WINDOWEVENT_RESIZED)
		update_win_size(visu, cw, RESIZE);
	if (visu->event.type == SDL_QUIT)
		quit_sdl(visu, cw);
	if (visu->event.type == SDL_KEYDOWN)
	{
		handle_speed(visu);
		handle_sound(visu);
		if (visu->event.key.keysym.sym == SDLK_SPACE)
			visu->pause = visu->pause ? 0 : 1;
		if (visu->event.key.keysym.sym == SDLK_ESCAPE)
			quit_sdl(visu, cw);
		handle_responsive(cw, visu);
	}
}
