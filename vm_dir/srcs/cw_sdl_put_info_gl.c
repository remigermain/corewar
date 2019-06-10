/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl_put_info_gl.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 13:34:01 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/07 13:41:46 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

void	put_info_cycles(t_visu *visu, int value, int cycle)
{
	SDL_Color	color;
	SDL_Rect	rect;

	rect.x = visu->info.x;
	rect.y = visu->info.y + visu->info.h;
	rect.w = value * (visu->info.w) / CYCLE_TO_DIE;
	rect.h = 2;
	color_translate(RGB_INFO, &color);
	SDL_SetRenderDrawColor(visu->ren, color.r, color.g, color.b, 0);
	SDL_RenderFillRect(visu->ren, &rect);
	color_translate(RGB_PLAY_4, &color);
	rect.w = cycle * (visu->info.w) / CYCLE_TO_DIE;
	SDL_SetRenderDrawColor(visu->ren, color.r, color.g, color.b, 0);
	SDL_RenderFillRect(visu->ren, &rect);
}

void	dbg_put_frames(t_visu *visu)
{
	put_frame_rect(visu, &visu->arena, RGB_PLAY_3 - 666);
	put_frame_rect(visu, &visu->info, RGB_PLAY_3 - 666);
	put_frame_rect(visu, &visu->info_gl[0], RGB_PLAY_3 - 666);
	put_frame_rect(visu, &visu->info_gl[1], RGB_PLAY_3 - 666);
	put_frame_rect(visu, &visu->info_gl[2], RGB_PLAY_3 - 666);
	put_frame_rect(visu, &visu->info_gl[3], RGB_PLAY_3 - 666);
	put_frame_rect(visu, &visu->info_gl[4], RGB_PLAY_3 - 666);
}

void	put_info_gl(t_visu *visu, t_core *cw, int cycle)
{
	unsigned char	*str;

	ft_sprintf(&str, "[cycle%d]", cw->vm.cycle_total);
	put_text(visu, visu->info_gl[CYCLES], (char*)str, RGB_INFO_TXT);
	ft_sprintf(&str, "[%dprocess]", cw->total_process);
	put_text(visu, visu->info_gl[PROCESS], (char*)str, RGB_INFO_TXT);
	ft_sprintf(&str, "[speed%d]", visu->speed);
	put_text(visu, visu->info_gl[SPEED], (char*)str, RGB_INFO_TXT);
	if (!visu->pause)
		ft_sprintf(&str, "[%dms]", visu->t2);
	else
		ft_sprintf(&str, "[paused]");
	put_text(visu, visu->info_gl[MS], (char*)str,\
		visu->pause ? RGB_PLAY_3 : RGB_INFO_TXT);
	ft_sprintf(&str, "[%dplayers]", cw->nb_player);
	put_text(visu, visu->info_gl[PLAYERS], (char*)str, RGB_INFO_TXT);
	put_info_cycles(visu, cw->vm.cycle_to_die, cycle);
}

void	put_info_gl_end(t_visu *visu, t_core *cw)
{
	unsigned char	*str;

	ft_sprintf(&str, "[cycle%d]", cw->vm.cycle_total);
	put_text(visu, visu->info_gl[0], (char*)str, RGB_INFO_TXT);
	ft_sprintf(&str, "[END]");
	put_text(visu, visu->info_gl[4], (char*)str, RGB_INFO_TXT);
}
