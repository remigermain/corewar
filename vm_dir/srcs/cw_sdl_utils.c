/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/30 12:31:51 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 17:14:35 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

void	color_translate(int base, SDL_Color *color)
{
	color->r = base >> 16;
	color->g = base >> 8;
	color->b = base & 0x0000FF;
}

void	clear_screen(t_visu *visu)
{
	SDL_SetRenderDrawColor(visu->ren, 20, 20, 20, 0);
	if ((SDL_RenderClear(visu->ren)) < 0)
		cw_warning(SDL_RENDER_CLEAR);
}

void	play_audio(t_core *cw, int indice, int channel)
{
	if (test_bit(&(cw->utils.flags), CW_VISU) &&
		test_bit(&(cw->utils.flags), CW_VISU_M))
	{
		if (Mix_PlayChannel(channel, cw->samples[indice], 0) == -1)
			cw_warning(SDL_PLAY_CHAN);
	}
}

void	convert_little(t_core *cw, t_visu *visu, SDL_Rect *little, int pc)
{
	int max;
	int value;

	little->x = visu->bytetab[pc].coord.x + 2;
	little->w = visu->bytetab[pc].coord.w - 4;
	little->y = visu->bytetab[pc].coord.y + 2;
	little->h = visu->bytetab[pc].coord.h - 4;
	if (cw->vm.cycles[pc] && cw->vm.arena[pc] >= CW_LIVE &&
													cw->vm.arena[pc] <= CW_AFF)
	{
		max = cw->tab[cw->vm.arena[pc] - 1].cycles;
		value = cw->vm.cycles[pc];
		if (value > max)
			max = 1000;
		little->w = (max - value) * little->w / max;
	}
}

void	handle_time(t_visu *visu)
{
	int delay;

	visu->t2 = SDL_GetTicks() - visu->t1;
	delay = 1000 / 60 - visu->t2;
	SDL_Delay(delay > 0 ? delay : 0);
	visu->t2 = SDL_GetTicks() - visu->t1;
}
