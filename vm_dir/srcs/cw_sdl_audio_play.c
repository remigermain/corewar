/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl_audio_play.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/10 18:52:13 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 14:33:10 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

void	play_fork(t_core *cw)
{
	static int head = 0;

	play_sample(cw, head + 8, FORK_CHAN);
	head = head == 3 ? 0 : head + 1;
}

void	play_st(t_core *cw)
{
	static int head = 0;

	play_sample(cw, head + 12, ST_CHAN);
	head = head == 3 ? 0 : head + 1;
}

void	play_ld(t_core *cw)
{
	static int head = 0;

	play_sample(cw, head + 12, LD_CHAN);
	head = head == 3 ? 0 : head + 1;
}

void	play_live(t_core *cw, int head)
{
	if (head > 0 && head < 256)
		play_sample(cw, 0, LIVE_CHAN);
	if (head > 255 && head < 512)
		play_sample(cw, 1, LIVE_CHAN);
	if (head > 511 && head < 768)
		play_sample(cw, 2, LIVE_CHAN);
	if (head > 767 && head < 1024)
		play_sample(cw, 3, LIVE_CHAN);
}

void	play_jump(t_core *cw, int head)
{
	if (head > 0 && head < 256)
		play_sample(cw, 4, JUMP_CHAN);
	if (head > 255 && head < 512)
		play_sample(cw, 5, JUMP_CHAN);
	if (head > 511 && head < 768)
		play_sample(cw, 6, JUMP_CHAN);
	if (head > 767 && head < 1024)
		play_sample(cw, 7, JUMP_CHAN);
}
