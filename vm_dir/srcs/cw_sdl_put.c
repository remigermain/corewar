/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl_put.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/30 12:31:51 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/09 18:13:48 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

void	put_text(t_visu *visu, SDL_Rect rect, char *str, int color)
{
	SDL_Surface	*tmp;
	SDL_Color	rgb;
	SDL_Texture	*text;
	SDL_Rect	text_rect;

	text_rect.x = rect.x;
	text_rect.y = rect.y;
	color_translate(color, &rgb);
	tmp = TTF_RenderText_Blended(visu->font, str, rgb);
	text = SDL_CreateTextureFromSurface(visu->ren, tmp);
	SDL_FreeSurface(tmp);
	SDL_QueryTexture(text, NULL, NULL, &text_rect.w, &text_rect.h);
	if (rect.w < text_rect.w)
		text_rect.w = rect.w;
	SDL_RenderCopy(visu->ren, text, NULL, &text_rect);
	SDL_DestroyTexture(text);
	ft_memdel((void**)&str);
}

/*
**-----------------------------------------------------------------------
**	display a color rectangle
**-----------------------------------------------------------------------
*/

void	put_fill_rect(t_visu *visu, SDL_Rect *rect, int color)
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
** display a color rectangle depending on player
**-----------------------------------------------------------------------
*/

void	put_fill_rect2(t_visu *visu, t_core *cw, int pc)
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

void	put_dot(t_visu *visu, SDL_Rect *rect, int color)
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

void	put_frame_rect(t_visu *visu, SDL_Rect *rect, int color)
{
	SDL_Color rgb;

	color_translate(color, &rgb);
	SDL_SetRenderDrawColor(visu->ren, rgb.r, rgb.g, rgb.b, 0);
	SDL_RenderDrawRect(visu->ren, rect);
}
