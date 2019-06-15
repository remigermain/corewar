/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_instructions1.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/23 12:51:28 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/13 03:51:02 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
** live :
**
** Reports the player designated by the first parameter as being
** alive. The instruction writes on the standard output a message of the type
** "The player $player_name ( $player_id), was reported as alive".
** It is up to you to'pimp' the message as you wish,
** as long as the idea passes and it contains the variables
** above named. A player only lives as long as at least one process
** performs a live performance with his id, and this at least once
** all CYCLE_TO_DIE. If the passed parameter does not match the id
** of any player, the behavior is indefinite. It's up to you to decide
** if it is an error and the process crashes, or if daring,
** the instruction does nothing and we move on to the next step, with eventual
** in addition a short message on the standard output,
** inconsistent message or warning message, your only limit
** is that of your creativity.
**-----------------------------------------------------------------------
*/

t_bool	live(t_core *cw, t_inst *inst, t_process *p)
{
	int i;

	play_live(cw, cw->vm.cycle_total % 1024);
	cw->vm.color[i_pc(p->pc)] = 10 + p->player + 1;
	cw->vm.pc[i_pc(p->pc)] = 10 + p->player + 1;
	i = find_player(cw, inst->value[0]);
	cw->total_live++;
	if (test_bit(&(cw->utils.flags), CW_DIFF))
		ft_printf("P %4d | live %d\n", p->number, inst->value[0]);
	if (i >= 0 && i < cw->nb_player)
	{
		cw->last_live = i;
		cw->player[i].nb_live++;
		if (test_bit(&(cw->utils.flags), CW_V4))
			ft_printf("\tPlayer said he's " GREEN "alive\n" RESET);
		else if (test_bit(&(cw->utils.flags), CW_DIFF))
			ft_printf("Player 1 (%s) is said to be alive\n",
				cw->player[p->player].data.prog_name);
	}
	p->live = 1;
	p->live_cycle = cw->vm.cycle_total;
	return (TRUE);
}

/*
**-----------------------------------------------------------------------
** fork :
**
** Generate a new process at the address passed in parameter
** by copying the calling process. The new process therefore keeps
** the status of all registers and the carry,
** only the PC differs (except in the case of a %0 fork).
**
** lfork :
**
** Same as Fork but without addressing restrictions.
**-----------------------------------------------------------------------
*/

t_bool	ffork(t_core *cw, t_inst *inst, t_process *p)
{
	play_fork(cw);
	cw->vm.color[i_pc(p->pc)] = 30 + p->player + 1;
	cw->vm.pc[i_pc(p->pc)] = 30 + p->player + 1;
	add_process(cw, p, inst);
	if (test_bit(&(cw->utils.flags), CW_V4))
		ft_printf("\tA process has been created to arena[" B_PINK "%d"
										RESET"]\n", i_pc(inst->value[0]));
	return (TRUE);
}

/*
**-----------------------------------------------------------------------
** zjmp :
**
** Skip to the address passed in parameter if the carry is in state one.
** The address then becomes the address of the next instruction.
** If the carry is in the zero state, nothing happens and the flow continues
** normally until the next instruction.
** There is no indication whether the instruction consumes all of the
** these cycles in this case, it's up to you to decide.
*/

t_bool	zjmp(t_core *cw, t_inst *inst, t_process *p)
{
	int	value;

	play_jump(cw, cw->vm.cycle_total % 1024);
	if (test_bit(&(cw->utils.flags), CW_DIFF))
		ft_printf("P %4d | %s %d ", p->number, cw->tab[inst->op - 1].name,
				inst->value[0]);
	if (p->carry == 1)
	{
		value = convert_adress(p, inst, inst->value[0]);
		inst->size = i_pc(value);
		if (test_bit(&(cw->utils.flags), CW_V4))
			ft_printf("\tProcess moved to arena[" B_PINK "%d"RESET"]\n", value);
		else if (test_bit(&(cw->utils.flags), CW_DIFF))
			ft_printf("OK\n");
		cw->vm.color[i_pc(p->pc)] = 20 + p->player + 1;
		cw->vm.pc[i_pc(p->pc)] = 20 + p->player + 1;
	}
	if (test_bit(&(cw->utils.flags), CW_V4) && !p->carry)
		ft_printf("\tZJMP failed\n");
	else if (test_bit(&(cw->utils.flags), CW_DIFF) && !p->carry)
		ft_printf("FAILED\n");
	if (!p->carry)
		return (FALSE);
	return (TRUE);
}

/*
**-----------------------------------------------------------------------
** aff :
**
** Displays on the screen the tank corresponding to the value of the register
** passed in parameter, modulo 256. If this tank is NULL,
** then the carry goes to state 1, otherwise to state 0.
** It is up to you to choose the formatting of the screen output.
** For example, you can specify to each aff the id of are
** original process, or assign a color to
** each process, or assign one aff line per process,
** or anything else with the processes,
** the important thing is that your exit from the affair is as swag as possible.
**-----------------------------------------------------------------------
*/

t_bool	aff(t_core *cw, t_inst *inst, t_process *p)
{
	if (!convert_value(cw, p, inst, CW_P1))
		return (FALSE);
	if (test_bit(&(cw->utils.flags), CW_F_AFF) ||
			test_bit(&(cw->utils.flags), CW_V4))
		ft_printf("\taff '" B_WHITE "%C"RESET"'\n", inst->value[0] % 256);
	return (TRUE);
}
