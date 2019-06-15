/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/30 12:31:51 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 09:08:15 by rcepre      ###    #+. /#+    ###.fr     */
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

void	handle_time(t_visu *visu)
{
	int delay;

	visu->t2 = SDL_GetTicks() - visu->t1;
	delay = 1000 / 60 - visu->t2;
	SDL_Delay(delay > 0 ? delay : 0);
	visu->t2 = SDL_GetTicks() - visu->t1;
}
