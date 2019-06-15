/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl_update_win_size.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/11 08:24:08 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 09:08:17 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

void	set_sizes_responsive(t_visu *visu)
{
	visu->arena.x = visu->win_w / 64;
	visu->arena.w = visu->win_w - (visu->arena.x * 2);
	visu->arena.y = visu->win_h / 16;
	visu->arena.h = visu->win_h - visu->arena.y - (visu->win_h / 64);
	visu->info.x = visu->arena.x;
	visu->info.w = visu->arena.w;
	visu->info.y = visu->win_h / 128;
	visu->info.h = visu->arena.y - (visu->info.y * 2);
}
/*
void	set_sizes_fix(t_visu *visu)
{
	visu->arena.x = 700;
	visu->arena.w = 1973 - 700;
	visu->arena.y = 95 + 70;
	visu->arena.h = 1100 - 165;
	visu->info.x = visu->arena.x;
	visu->info.w = visu->arena.w;
	visu->info.y = 95;
	visu->info.h = 60;
}
*/

void	set_sizes_fix(t_visu *visu)
{
	visu->arena.x = 525;
	visu->arena.w = 1973 - 700 - 280;
	visu->arena.y = 95 + 70 - 20;
	visu->arena.h = 1100 - 165 - 240;
	visu->info.x = visu->arena.x;
	visu->info.w = visu->arena.w;
	visu->info.y = 65;
	visu->info.h = 60;
}

void	update_win_size(t_visu *visu, t_core *cw, int todo)
{
	if (todo == RESIZE)
		SDL_GetWindowSize(visu->win, &visu->win_w, &visu->win_h);
	if (visu->responsive_mode)
		set_sizes_responsive(visu);
	else
		set_sizes_fix(visu);
	update_bytes_pos(visu);
	update_info_gl(visu);
	update_info_players(visu, cw);
}
