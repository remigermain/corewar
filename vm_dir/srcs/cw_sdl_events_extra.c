/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl_events.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 13:30:11 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 18:03:25 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
** SDL function for music in walkman , button exit et light
**-----------------------------------------------------------------------
*/

static int	change_light(t_visu *visu)
{
	SDL_Surface	*surf;

	SDL_DestroyTexture(visu->background);
	if (visu->light && !(surf = SDL_LoadBMP(IMG_COMMODORE_SCREEN_2_1)))
		cw_warning(SDL_LOAD_BMP);
	else if (!visu->light &&
		!(surf = SDL_LoadBMP(IMG_COMMODORE_SCREEN_2)))
		cw_warning(SDL_LOAD_BMP);
	if (!(visu->background =\
		SDL_CreateTextureFromSurface(visu->ren, surf)))
		cw_warning(SDL_CREATE_TEXT);
	SDL_FreeSurface(surf);
	visu->light = (visu->light ? 0 : 1);
	return (1);
}

static int	change_music(void)
{
	static char	is_music = 1;
	Mix_Music	*music;

	music = NULL;
	if (is_music)
	{
		Mix_VolumeMusic(MIX_MAX_VOLUME / 12);
		if (!(music = Mix_LoadMUS(DIR_S"pink.wav")))
			cw_warning(SDL_LOAD_SAM);
		if (Mix_PlayMusic(music, 0) == -1)
			cw_warning(SDL_PLAY_CHAN);
	}
	else
	{
		Mix_HaltMusic();
		Mix_FreeMusic(music);
	}
	is_music = (is_music ? 0 : 1);
	return (1);
}

void		get_mouse(t_visu *visu, t_core *cw)
{
	static int	is_press = 0;
	int			x;
	int			y;

	if (visu->event.type == SDL_MOUSEBUTTONDOWN && is_press == 1)
		return ;
	else if (visu->event.type == SDL_MOUSEBUTTONUP)
		is_press = 0;
	else if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT) &&
		!visu->responsive_mode && visu->event.key.repeat == 0)
	{
		is_press = 0;
		if (!visu->mod_back && x >= GR_POWER_1 && x <= GR_POWER_2 &&
				y >= GR_POWER_3 && y <= GR_POWER_4)
			quit_sdl(visu, cw);
		else if (visu->mod_back && x >= CO_POWER_1 && x <= CO_POWER_2 &&
				y >= CO_POWER_3 && y <= CO_POWER_4)
			quit_sdl(visu, cw);
		else if (visu->mod_back && x >= CO_MU_1 && x <= CO_MU_2 &&
				y >= CO_MU_3 && y <= CO_MU_4)
			is_press = change_music();
		else if (visu->mod_back && x >= CO_LIGHT_1 && x <= CO_LIGHT_2 &&
				y >= CO_LIGHT_3 && y <= CO_LIGHT_4)
			is_press = change_light(visu);
	}
}
