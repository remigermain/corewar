/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl_update_win_size_utils.c                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/11 08:25:24 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 09:08:25 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

void	update_bytes_pos(t_visu *visu)
{
	SDL_Rect	rect;
	int			i;
	int			j;
	int			x;

	rect.w = visu->arena.w / 64;
	rect.h = visu->arena.h / 64;
	rect.y = visu->arena.y;
	rect.x = visu->arena.x;
	j = -1;
	x = 0;
	while (++j < 64)
	{
		i = -1;
		rect.x = visu->arena.x;
		while (++i < 64)
		{
			visu->bytetab[x++].coord = rect;
			rect.x = (visu->arena.x + visu->arena.w / 64) +
					(i * visu->arena.w / 64);
		}
		rect.y = (visu->arena.y + (visu->arena.h / 64)) + j *
															visu->arena.h / 64;
	}
}

void	update_info_gl(t_visu *visu)
{
	int			w;
	int			h;
	int			i;

	w = visu->info.w / 5;
	h = visu->info.h / 2;
	i = -1;
	while (++i < 5)
	{
		visu->info_gl[i].x = visu->info.x + (i * visu->info.w / 5);
		visu->info_gl[i].y = visu->info.y;
		visu->info_gl[i].w = w;
		visu->info_gl[i].h = h;
	}
}

void	update_info_players(t_visu *visu, t_core *cw)
{
	int			w;
	int			h;
	int			i;

	w = visu->info.w / cw->nb_player;
	h = visu->info.h / 2;
	i = -1;
	while (++i < cw->nb_player)
	{
		visu->info_players[i].x = visu->info.x +
								(i * visu->info.w / cw->nb_player);
		visu->info_players[i].y = visu->info.y + h;
		visu->info_players[i].w = w;
		visu->info_players[i].h = h;
	}
}
