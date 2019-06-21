/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl_put_info_gl.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 13:34:01 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 10:16:37 by rcepre      ###    #+. /#+    ###.fr     */
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

void	put_info_gl(t_visu *visu, t_core *cw, int cycle)
{
	unsigned char	*str;

	ft_sprintf(&str, "[cycle %d]", cw->vm.cycle_total);
	put_text(visu, visu->info_gl[CYCLES], (char*)str, RGB_INFO_TXT);
	ft_sprintf(&str, "[%d process]", cw->total_process);
	put_text(visu, visu->info_gl[PROCESS], (char*)str, RGB_INFO_TXT);
	ft_sprintf(&str, "[speed %d]", visu->speed);
	put_text(visu, visu->info_gl[SPEED], (char*)str, RGB_INFO_TXT);
	if (!visu->pause)
		ft_sprintf(&str, "[%d ms]", visu->t2);
	else
		ft_sprintf(&str, "[paused]");
	put_text(visu, visu->info_gl[MS], (char*)str,\
		visu->pause ? RGB_PLAY_3 : RGB_INFO_TXT);
	ft_sprintf(&str, "[ music ]", cw->nb_player);
	if (visu->sound)
		put_text(visu, visu->info_gl[PLAYERS], (char *)str, 0xAAFFAA);
	else
		put_text(visu, visu->info_gl[PLAYERS], (char*)str, 0x808080);
	put_info_cycles(visu, cw->vm.cycle_to_die, cycle);
}

void	put_info_gl_end(t_visu *visu, t_core *cw)
{
	unsigned char	*str;
	static	int		blink = 0;

	if (blink > 200)
		blink = 0;
	ft_sprintf(&str, "[cycle %d]", cw->vm.cycle_total);
	put_text(visu, visu->info_gl[0], (char*)str, RGB_INFO_TXT);
	ft_sprintf(&str, "[%s win !]", cw->player[cw->last_live].data.prog_name);
	if (blink++ > 100)
		put_text(visu, visu->info_gl[2], (char*)str, RGB_JUMP);
	else
		put_text(visu, visu->info_gl[2], (char*)str, RGB_FORK);
	ft_sprintf(&str, "[END]");
	put_text(visu, visu->info_gl[4], (char*)str, RGB_INFO_TXT);
}
