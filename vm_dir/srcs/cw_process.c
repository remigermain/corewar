/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_process.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/03 10:08:31 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 18:21:36 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

void				add_process(t_core *cw, t_process *fork, t_inst *inst,
		int pc)
{
	static int	number = 0;

	if (!number)
		number = cw->nb_player;
	ft_memcpy(&(cw->process[cw->total_process]), fork, sizeof(t_process));
	cw->process[cw->total_process].pc = i_pc(pc);
	cw->process[cw->total_process].number = ++number;
	cw->process[cw->total_process].cycle_instruction =\
						next_inst(cw, &(cw->process[cw->total_process]));
	if (fork->player < cw->nb_player)
		cw->player[fork->player].nb_process++;
	cw->fork++;
	cw->total_process++;
	fork->pc = i_pc(inst->size);
	cw->vm.pc[fork->pc] = fork->player + 1;
	if (cw->total_process >= cw->len_process)
	{
		if (!(cw->process = (t_process*)realloc(cw->process,\
						sizeof(t_process) * (cw->len_process * 2))))
			cw_error_run(cw, CW_MALLOC_R, "add_process");
		ft_bzero(cw->process + cw->total_process, sizeof(t_process) *\
				cw->len_process);
		cw->len_process *= 2;
	}
}

/*
**-----------------------------------------------------------------------
** if process didn't live remove it and join prev and next link in side chain
**-----------------------------------------------------------------------
*/

static void			remove_process2(t_core *cw, int i, int j)
{
	if (i != j)
	{
		cw->vm.pc[i_pc(cw->process[j].pc)] = 0;
		cw->vm.cycles[i_pc(cw->process[j].pc)] = 0;
		remove_process_verbose(cw, &(cw->process[j]));
		ft_memcpy(&cw->process[i], &cw->process[j], sizeof(t_process));
	}
	cw->process[i].live = 0;
	if (cw->process[i].player < cw->nb_player)
		cw->player[cw->process[i].player].nb_process++;
}

void				remove_process(t_core *cw)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while ((int)j < cw->nb_player)
		cw->player[j++].nb_process = 0;
	j = 0;
	while (j < cw->total_process)
	{
		while (j < cw->total_process && !cw->process[j].live)
			j++;
		if (j < cw->total_process && cw->process[j].live)
		{
			remove_process2(cw, i, j);
			i++;
			j++;
		}
	}
	cw->total_process = i;
}

/*
**-----------------------------------------------------------------------
** check every process and decremente cycle instruction
** if cycle instruction is equal to 0 execute instruction and pass to next one
**-----------------------------------------------------------------------
*/

void				covered_process(t_core *cw)
{
	int	i;

	i = cw->total_process - 1;
	while (i >= 0)
	{
		cw->vm.cycles[i_pc(cw->process[i].pc)] =\
										cw->process[i].cycle_instruction - 1;
		cw->vm.pc[i_pc(cw->process[i].pc)] = cw->process[i].player + 1;
		if (--cw->process[i].cycle_instruction <= 0)
		{
			cw->vm.pc[i_pc(cw->process[i].pc)] = 0;
			launch_instruction(cw, &(cw->process[i]));
			cw->process[i].cycle_instruction = next_inst(cw, &(cw->process[i]));
		}
		i--;
	}
	exit(0);
}
