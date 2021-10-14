/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 18:22:38 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/17 18:59:35 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
**	init les fonts and open cw_fonts.ttf
**-----------------------------------------------------------------------
*/

static void		init_ttf(t_core *cw, t_visu *visu)
{
	if ((TTF_Init()) == -1)
		cw_error_run(cw, SDL_TTF_INIT, NULL);
	if (!(visu->font = TTF_OpenFont(DIR_S"cw_font.ttf", 13)))
		cw_error_run(cw, SDL_TTF_OPEN, NULL);
}

/*
**-----------------------------------------------------------------------
** put a title and an icon to the window
**-----------------------------------------------------------------------
*/

static void		put_icon_and_title(t_visu *visu)
{
	SDL_Surface *icon;

	SDL_SetWindowTitle(visu->win, "Corewar");
	if (!(icon = SDL_LoadBMP(DIR_S"cw_icon.bmp")))
		cw_warning(SDL_LOAD_BMP);
	SDL_SetWindowIcon(visu->win, icon);
	SDL_FreeSurface(icon);
}

/*
**-----------------------------------------------------------------------
**	init SDL, audio, fonts and make a renderer
**-----------------------------------------------------------------------
*/

void			init_sdl(t_core *cw, t_visu *visu)
{
	SDL_DisplayMode	dm;
	int				freq;

	freq = (MIX_DEFAULT_FREQUENCY) * 2;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		cw_error_run(cw, SDL_INIT, NULL);
	if ((Mix_OpenAudio(freq, MIX_DEFAULT_FORMAT, STEREO, 4096) < 0))
		cw_error_run(cw, SDL_OPEN_AUDIO, NULL);
	SDL_StartTextInput();
	init_ttf(cw, visu);
	if (visu->win_h == -1)
	{
		SDL_GetCurrentDisplayMode(0, &dm);
		visu->win_h = dm.h * 0.8;
		visu->win_w = dm.h * 0.8;
	}
	update_win_size(visu, cw, 0);
	if (SDL_CreateWindowAndRenderer(visu->win_w, visu->win_h, SDL_WINDOW_SHOWN |
						SDL_WINDOW_RESIZABLE | SDL_WINDOW_FULLSCREEN_DESKTOP,  \
														&visu->win, &visu->ren))
		cw_error_run(cw, SDL_CREATE_WIN, NULL);
	load_samples(cw);
	SDL_SetRenderDrawColor(visu->ren, 0x1e, 0x1e, 0x1e, 255);
	put_icon_and_title(visu);
	open_images(visu);
	SDL_RenderClear(visu->ren);
}

/*
**-----------------------------------------------------------------------
**	quit sdl, call cw_error and free everything, then exit
**-----------------------------------------------------------------------
*/

void			quit_sdl(t_visu *visu, t_core *cw)
{
	int i;

	i = -1;
	while (++i < SAMPLE_NB)
		Mix_FreeChunk(cw->samples[i]);
	Mix_CloseAudio();
	SDL_DestroyTexture(visu->background);
	SDL_DestroyRenderer(visu->ren);
	SDL_DestroyWindow(visu->win);
	TTF_CloseFont(visu->font);
	SDL_StopTextInput();
	TTF_Quit();
	SDL_Quit();
	cw_error_run(cw, SDL_SDL_QUIT, NULL);
}

void			open_images(t_visu *visu)
{
	SDL_Surface	*surf;

    visu->light = 1;
    visu->mod_back = 1;
	if (!(surf = SDL_LoadBMP(visu->screen.light)))
		cw_warning(SDL_LOAD_BMP);
	if (!(visu->background = SDL_CreateTextureFromSurface(visu->ren, surf)))
		cw_warning(SDL_CREATE_TEXT);
	SDL_FreeSurface(surf);
}
