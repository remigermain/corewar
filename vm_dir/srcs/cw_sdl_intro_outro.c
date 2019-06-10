/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl_intro_outro.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 17:25:01 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 17:14:21 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static void	sdl_intro_text(t_core *cw, t_visu *visu, int ret, int mod)
{
	while (ret)
	{
		handle_events(visu, cw);
		clear_screen(visu);
		if ((ret = display_intro(mod, visu)) == -1)
			play_audio(cw, rand() % 4 + 8, rand() % 4);
		SDL_RenderPresent(visu->ren);
		if (!ret && !mod && (++mod) && (ret = 1))
			SDL_Delay(1000);
		else
			SDL_Delay(75);
	}
}

static void	sdl_intro_diag(t_core *cw, t_visu *visu, int ret)
{
	while (ret)
	{
		handle_events(visu, cw);
		clear_screen(visu);
		ret = diagonal_animation(visu, cw, 1, 1);
		if (ret == -1)
			play_audio(cw, rand() % 4 + 12, rand() % 4);
		SDL_RenderPresent(visu->ren);
		SDL_Delay(50);
	}
	play_audio(cw, 1, LIVE_CHAN);
}

/*
**-----------------------------------------------------------------------
**	init SDL
**-----------------------------------------------------------------------
*/

void		sdl_intro(t_core *cw, t_visu *visu)
{
	int mod;

	mod = 0;
	if (test_bit(&(cw->utils.flags), CW_VISU))
	{
		init_sdl(cw, visu);
		update_bytes_pos(visu);
		if (!test_bit(&(cw->utils.flags), CW_VISU_AN))
			return ;
	}
	else
		return ;
	sdl_intro_text(cw, visu, 1, mod);
	sdl_intro_diag(cw, visu, 1);
}

void		sdl_outro(t_core *cw, t_visu *visu, int mod)
{
	int ret;

	ret = 1;
	if (!test_bit(&(cw->utils.flags), CW_VISU) \
								|| !test_bit(&(cw->utils.flags), CW_VISU_AN))
		return ;
	while (ret)
	{
		handle_events(visu, cw);
		clear_screen(visu);
		ret = !mod ? diagonal_animation(visu, cw, 0, 1) : display_outro(visu);
		if (ret == -1)
			play_audio(cw, rand() % 4 + 8, rand() % 4);
		SDL_RenderPresent(visu->ren);
		!mod ? SDL_Delay(50) : SDL_Delay(100);
	}
}
