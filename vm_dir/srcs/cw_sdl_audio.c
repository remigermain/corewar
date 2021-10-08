/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl_audio.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/11 08:59:19 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 10:28:38 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
** load samples
**-----------------------------------------------------------------------
*/

void	load_samples(t_core *cw)
{
	int	i;

	i = 0;
	cw->samples[0] = Mix_LoadWAV(DIR_S "live1.wav");
	cw->samples[1] = Mix_LoadWAV(DIR_S "live2.wav");
	cw->samples[2] = Mix_LoadWAV(DIR_S "live3.wav");
	cw->samples[3] = Mix_LoadWAV(DIR_S "live4.wav");
	cw->samples[4] = Mix_LoadWAV(DIR_S "jump1.wav");
	cw->samples[5] = Mix_LoadWAV(DIR_S "jump2.wav");
	cw->samples[6] = Mix_LoadWAV(DIR_S "jump3.wav");
	cw->samples[7] = Mix_LoadWAV(DIR_S "jump4.wav");
	cw->samples[8] = Mix_LoadWAV(DIR_S "fork1.wav");
	cw->samples[9] = Mix_LoadWAV(DIR_S "fork2.wav");
	cw->samples[10] = Mix_LoadWAV(DIR_S "fork3.wav");
	cw->samples[11] = Mix_LoadWAV(DIR_S "fork4.wav");
	cw->samples[12] = Mix_LoadWAV(DIR_S "st1.wav");
	cw->samples[13] = Mix_LoadWAV(DIR_S "st2.wav");
	cw->samples[14] = Mix_LoadWAV(DIR_S "st3.wav");
	cw->samples[15] = Mix_LoadWAV(DIR_S "st4.wav");
	while (i < SAMPLE_NB)
		if (cw->samples[i++] == NULL)
			cw_warning(SDL_LOAD_SAM);
	Mix_AllocateChannels(5);
}

void	play_sample(t_core *cw, int indice, int channel)
{
	if (cw->visu->sound)
	{
		if (Mix_PlayChannel(channel, cw->samples[indice], 0) < 0)
			cw_warning(SDL_PLAY_CHAN);
	}
}
