/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl_put.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/30 12:31:51 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 08:37:31 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
**	display a color rectangle
**-----------------------------------------------------------------------
*/

void		put_fill_rect(t_visu *visu, SDL_Rect *rect, int color)
{
	SDL_Rect	little;
	SDL_Color	rgb;

	color_translate(color, &rgb);
	SDL_SetRenderDrawColor(visu->ren, rgb.r, rgb.g, rgb.b, 0);
	little.x = rect->x + 2;
	little.w = rect->w - 4;
	little.y = rect->y + 2;
	little.h = rect->h - 4;
	SDL_RenderFillRect(visu->ren, &little);
}

/*
**-----------------------------------------------------------------------
** display a color rectangle with progression bar
**-----------------------------------------------------------------------
*/

static void	convert_little(t_core *cw, t_visu *visu, SDL_Rect *little, int pc)
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

void		put_fill_rect_prog(t_visu *visu, t_core *cw, int pc)
{
	SDL_Rect	little;
	SDL_Color	rgb;
	int			color;

	color = cw->vm.color[pc] == 1 ? RGB_PLAY_1 : 0;
	color = cw->vm.color[pc] == 2 ? RGB_PLAY_2 : color;
	color = cw->vm.color[pc] == 3 ? RGB_PLAY_3 : color;
	color = cw->vm.color[pc] == 4 ? RGB_PLAY_4 : color;
	if (cw->vm.color[pc] >= 30 && (cw->vm.color[pc] -= 30))
		color = RGB_FORK;
	if (cw->vm.color[pc] >= 20 && (cw->vm.color[pc] -= 20))
		color = RGB_JUMP;
	if (cw->vm.color[pc] >= 10 && (cw->vm.color[pc] -= 10))
		color = RGB_LIVE;
	color_translate(color, &rgb);
	convert_little(cw, visu, &little, pc);
	SDL_SetRenderDrawColor(visu->ren, rgb.r, rgb.g, rgb.b, 0);
	SDL_RenderFillRect(visu->ren, &little);
}

void		put_dot(t_visu *visu, SDL_Rect *rect, int color)
{
	SDL_Rect	little;
	SDL_Color	rgb;

	put_fill_rect(visu, rect, RGB_BCK);
	color_translate(color, &rgb);
	SDL_SetRenderDrawColor(visu->ren, rgb.r, rgb.g, rgb.b, 0);
	little.w = visu->win_w > 800 ? 4 : 2;
	little.x = rect->x + (rect->w / 2) - little.w / 2;
	little.h = visu->win_h > 800 ? 4 : 2;
	little.y = rect->y + (rect->h / 2) - little.w / 2;
	SDL_RenderFillRect(visu->ren, &little);
}

void		put_frame_rect(t_visu *visu, SDL_Rect *rect, int color)
{
	SDL_Color rgb;

	color_translate(color, &rgb);
	SDL_SetRenderDrawColor(visu->ren, rgb.r, rgb.g, rgb.b, 0);
	SDL_RenderDrawRect(visu->ren, rect);
}
