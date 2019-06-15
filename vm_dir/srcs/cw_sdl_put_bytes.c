/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl_put_bytes.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 13:01:10 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 08:30:19 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

void	put_one_byte(t_visu *visu, t_core *cw, int i)
{
	if (cw->vm.arena[i])
		put_fill_rect_prog(visu, cw, i);
	else if (cw->vm.color[i])
	{
		if (cw->vm.color[i] == 1 || cw->vm.color[i] == 2)
			cw->vm.color[i] == 1 ? put_dot(visu, &visu->bytetab[i].coord,
			RGB_PLAY_1) : put_dot(visu, &visu->bytetab[i].coord, RGB_PLAY_2);
		else if (cw->vm.color[i] == 3)
			put_dot(visu, &visu->bytetab[i].coord, RGB_PLAY_3);
		else if (cw->vm.color[i] == 4)
			put_dot(visu, &visu->bytetab[i].coord, RGB_PLAY_4);
	}
	else
		put_fill_rect(visu, &visu->bytetab[i].coord, RGB_BCK);
	if (cw->vm.pc[i])
	{
		if (cw->vm.pc[i] == 1)
			put_frame_rect(visu, &visu->bytetab[i].coord, RGB_PLAY_1);
		else if (cw->vm.pc[i] == 2)
			put_frame_rect(visu, &visu->bytetab[i].coord, RGB_PLAY_2);
		else if (cw->vm.pc[i] == 3)
			put_frame_rect(visu, &visu->bytetab[i].coord, RGB_PLAY_3);
		else if (cw->vm.pc[i] == 4)
			put_frame_rect(visu, &visu->bytetab[i].coord, RGB_PLAY_4);
	}
}

void	put_bytes(t_visu *visu, t_core *cw)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
		put_one_byte(visu, cw, i);
}
