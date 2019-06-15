/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_instruction.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/16 15:14:21 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 14:02:07 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
**		verbose function for player
**-----------------------------------------------------------------------
*/

void	display_player(t_core *cw, t_process *p)
{
	if (p->player < cw->nb_player)
	{
		ft_printf("%*.@",
			71 - ft_strlen(cw->player[p->player].data.prog_name), "char", ' ');
		ft_printf("by : " COL_PROG_NAME "%s\n" RESET,\
				cw->player[p->player].data.prog_name);
		ft_printf(RESET);
	}
}

/*
**-----------------------------------------------------------------------
**		verbose function for process
**-----------------------------------------------------------------------
*/

void	display_process(t_process *p)
{
	ft_printf("%*.@", 69, "char", ' ');
	ft_printf(B_BLACK"processus n°%d\n", p->number);
	ft_printf(RESET);
}

/*
**-----------------------------------------------------------------------
**		verbose function to display header
**-----------------------------------------------------------------------
*/

void	display_head(t_core *cw, t_process *p, t_inst *inst)
{
	if (test_bit(&(cw->utils.flags), CW_V4) \
				|| (test_bit(&(cw->utils.flags), CW_V1) && inst->op == CW_LIVE))
	{
		ft_printf(CYAN"%-3d", cw->vm.cycle_total);
		ft_printf(B_BLACK" %32@[   ", "char", '-');
		ft_printf(COL_INSTR_NAME "%-5s" RESET, cw->tab[inst->op - 1].name);
		ft_printf(B_BLACK" ]%35@\n"RESET, "char", '-');
		ft_printf(B_BLACK"+%-4d ", cw->tab[inst->op - 1].cycles);
		display_player(cw, p);
		display_process(p);
		display_args(cw, p, inst);
	}
}

/*
**-----------------------------------------------------------------------
**		verbose function to display footer
**-----------------------------------------------------------------------
*/

void	display_foot(t_core *cw, t_process *p, t_inst *inst)
{
	static int	cycles;

	if (test_bit(&(cw->utils.flags), CW_V4) \
				|| (test_bit(&(cw->utils.flags), CW_V1) && inst->op == CW_LIVE))
	{
		if (!cycles)
			cycles = cw->vm.cycle_to_die;
		if (test_bit(&(cw->utils.flags), CW_VERBO))
		{
			if (p->carry)
				ft_printf(YELLOW);
			ft_printf("%d"RESET"" RESET B_BLACK, p->carry);
			ft_printf(" %74@ ", "char", '-');
			ft_printf("%-3d \n\n" RESET, cw->vm.cycle_to_die);
		}
		cycles = cw->vm.cycle_to_die;
		if (test_bit(&(cw->utils.flags), CW_VERBO_S))
			ft_getchar();
	}
}

/*
**-----------------------------------------------------------------------
**		verbose function to display arguments
**-----------------------------------------------------------------------
*/

void	display_args(t_core *cw, t_process *p, t_inst *inst)
{
	int	i;
	int	binary;

	i = -1;
	ft_printf("\tbase instruction -> ");
	while (++i < cw->tab[p->op - 1].nb_args)
	{
		binary = (inst->ocp >> binary_shift(i + 1)) & 0x03;
		if (binary == IND_CODE)
			ft_printf(""B_WHITE"%d"RESET"", inst->value[i]);
		else if (binary == DIR_CODE)
			ft_printf(""B_WHITE"%%%d"RESET"", inst->value[i]);
		else
			ft_printf(""B_WHITE"r%d"RESET"", inst->value[i]);
		if (i + 1 != cw->tab[p->op - 1].nb_args)
			ft_printf(", ");
	}
	ft_printf("\n");
}
