/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl_responsive.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 15:38:51 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/09 18:16:23 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
** put basic rectangle (the grey one) of the arena
**-----------------------------------------------------------------------
*/

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
	int	w;
	int	h;
	int	i;

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
	int	w;
	int	h;
	int	i;

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

void	responsive(t_visu *visu, t_core *cw, int todo)
{
	if (todo == RESIZE)
		SDL_GetWindowSize(visu->win, &visu->win_w, &visu->win_h);
	visu->arena.x = visu->win_w / 64;
	visu->arena.w = visu->win_w - (visu->arena.x * 2);
	visu->arena.y = visu->win_h / 16;
	visu->arena.h = visu->win_h - visu->arena.y - (visu->win_h / 64);
	visu->info.x = visu->arena.x;
	visu->info.w = visu->arena.w;
	visu->info.y = visu->win_h / 128;
	visu->info.h = visu->arena.y - (visu->info.y * 2);
	update_bytes_pos(visu);
	update_info_gl(visu);
	update_info_players(visu, cw);
}
