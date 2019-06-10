/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 18:22:38 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 14:25:03 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
**	init les fonts and open cw_fonts.ttf
**-----------------------------------------------------------------------
*/

static void	init_ttf(t_core *cw, t_visu *visu)
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

static void	put_icon_and_title(t_visu *visu)
{
	SDL_Surface *icon;

	SDL_SetWindowTitle(visu->win, "Corewar");
	icon = SDL_LoadBMP(DIR_S"cw_icon.bmp");
	SDL_SetWindowIcon(visu->win, icon);
	SDL_FreeSurface(icon);
}

/*
**-----------------------------------------------------------------------
** change samples song
**-----------------------------------------------------------------------
*/

static void	load_samples(t_core *cw)
{
	int i;

	i = 0;
	cw->samples[0] = Mix_LoadWAV(DIR_S"live1.wav");
	cw->samples[1] = Mix_LoadWAV(DIR_S"live2.wav");
	cw->samples[2] = Mix_LoadWAV(DIR_S"live3.wav");
	cw->samples[3] = Mix_LoadWAV(DIR_S"live4.wav");
	cw->samples[4] = Mix_LoadWAV(DIR_S"jump1.wav");
	cw->samples[5] = Mix_LoadWAV(DIR_S"jump2.wav");
	cw->samples[6] = Mix_LoadWAV(DIR_S"jump3.wav");
	cw->samples[7] = Mix_LoadWAV(DIR_S"jump4.wav");
	cw->samples[8] = Mix_LoadWAV(DIR_S"fork1.wav");
	cw->samples[9] = Mix_LoadWAV(DIR_S"fork2.wav");
	cw->samples[10] = Mix_LoadWAV(DIR_S"fork3.wav");
	cw->samples[11] = Mix_LoadWAV(DIR_S"fork4.wav");
	cw->samples[12] = Mix_LoadWAV(DIR_S"st1.wav");
	cw->samples[13] = Mix_LoadWAV(DIR_S"st2.wav");
	cw->samples[14] = Mix_LoadWAV(DIR_S"st3.wav");
	cw->samples[15] = Mix_LoadWAV(DIR_S"st4.wav");
	while (i < SAMPLE_NB)
		if (cw->samples[i++] == NULL)
			cw_warning(SDL_LOAD_SAM);
}

/*
**-----------------------------------------------------------------------
**	init SDL, audio, fonts and make a renderer
**-----------------------------------------------------------------------
*/

void		init_sdl(t_core *cw, t_visu *visu)
{
	SDL_DisplayMode	dm;
	int				freq;

	freq = (MIX_DEFAULT_FREQUENCY) * 2;
	if ((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)))
		cw_error_run(cw, SDL_INIT, NULL);
	if ((Mix_OpenAudio(freq, MIX_DEFAULT_FORMAT, STEREO, 128) == -1))
		cw_error_run(cw, SDL_OPEN_AUDIO, NULL);
	load_samples(cw);
	Mix_AllocateChannels(5);
	init_ttf(cw, visu);
	if (visu->win_h == -1)
	{
		SDL_GetCurrentDisplayMode(0, &dm);
		visu->win_h = dm.h * 0.8;
		visu->win_w = dm.h * 0.8;
	}
	responsive(visu, cw, 0);
	if (SDL_CreateWindowAndRenderer(visu->win_w, visu->win_h, SDL_WINDOW_SHOWN |
				SDL_WINDOW_RESIZABLE, &visu->win, &visu->ren))
		cw_error_run(cw, SDL_CREATE_WIN, NULL);
	SDL_SetWindowMinimumSize(visu->win, 600, 600);
	SDL_SetRenderDrawColor(visu->ren, 0x1e, 0x1e, 0x1e, 255);
	put_icon_and_title(visu);
	SDL_RenderClear(visu->ren);
}

/*
**-----------------------------------------------------------------------
**	quit sdl, call cw_error and free everything, then exit
**-----------------------------------------------------------------------
*/

void		quit_sdl(t_visu *visu, t_core *cw)
{
	int i;

	i = -1;
	while (++i < SAMPLE_NB)
		Mix_FreeChunk(cw->samples[i]);
	Mix_CloseAudio();
	SDL_DestroyRenderer(visu->ren);
	SDL_DestroyWindow(visu->win);
	TTF_CloseFont(visu->font);
	TTF_Quit();
	SDL_Quit();
	cw_error_run(cw, SDL_SDL_QUIT, NULL);
}
