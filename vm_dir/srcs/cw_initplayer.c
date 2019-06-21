/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_initplayer.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/03 10:08:31 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 16:31:58 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
**		Load players with equal start distance
**-----------------------------------------------------------------------
*/

static void	init_start(t_core *cw)
{
	int	i;

	i = -1;
	while (++i < cw->nb_player)
		cw->player[i].start = (MEM_SIZE / cw->nb_player) * i;
}

/*
**-----------------------------------------------------------------------
**	PC and R1 register depend to player number
**-----------------------------------------------------------------------
*/

static void	put_process(t_core *cw, int i)
{
	int	j;
	int number;

	j = 4;
	cw->process[i].pc = cw->player[i].start;
	cw->process[i].number = i + 1;
	cw->player[i].nb_process = 1;
	cw->process[i].player = i;
	cw->process[i].live_cycle = 0;
	cw->player[i].number = -(cw->player[i].number);
	number = cw->player[i].number;
	while (--j >= 0)
		cw->process[i].reg[0][3 - j] = ((unsigned char*)(&number))[j];
	cw->process[i].cycle_instruction = next_inst(cw, &(cw->process[i])) + 1;
	cw->last_live = i;
	cw->total_process++;
	if (++i < cw->nb_player)
		put_process(cw, i);
}

/*
**-----------------------------------------------------------------------
**	Write players depending on their PC
**-----------------------------------------------------------------------
*/

void		cw_initplayer(t_core *cw)
{
	int		i;

	i = -1;
	init_start(cw);
	while (++i < cw->nb_player)
	{
		ft_memcpy(cw->vm.arena + cw->player[i].start, cw->player[i].inst,
				cw->player[i].data.prog_size);
		ft_memset(cw->vm.color + cw->player[i].start, i + 1,
				cw->player[i].data.prog_size);
		cw->vm.pc[cw->player[i].start] = i + 1;
	}
	cw->len_process = cw->nb_player * 10000;
	if (!(cw->process = (t_process*)ft_memalloc(sizeof(t_process) *
					cw->len_process)))
		cw_error_run(cw, CW_MALLOC, "init_process");
	put_process(cw, 0);
}
