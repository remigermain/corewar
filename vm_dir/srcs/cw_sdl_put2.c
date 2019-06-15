/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl_put2.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/11 08:35:57 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 09:01:50 by rcepre      ###    #+. /#+    ###.fr     */
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
	ft_memdel((void **)&str);
}

void	put_background(t_visu *visu)
{
	SDL_Rect rect;

	if (visu->responsive_mode)
		return ;
	ft_bzero(&rect, sizeof(SDL_Rect));
	SDL_QueryTexture(visu->background, NULL, NULL, &rect.w, &rect.h);
	SDL_RenderCopy(visu->ren, visu->background, NULL, &rect);
}
