/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   instructions5.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/16 15:14:21 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 17:33:47 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
** convert values
** for register get register value, same thing for indirect
**-----------------------------------------------------------------------
*/

t_bool		convert_value(t_core *cw, t_process *p, t_inst *inst, int flag)
{
	int	binary;
	int	value;
	int	par_nb;

	par_nb = -1;
	while (++par_nb <= cw->tab[inst->op - 1].nb_args)
		if (flag & (1 << par_nb))
		{
			binary = (inst->ocp >> binary_shift(par_nb + 1)) & 0x03;
			if (binary == REG_CODE && inst->value[par_nb] > 0 \
				&& inst->value[par_nb] <= REG_NUMBER)
				inst->value[par_nb] =\
				add_bytes(p->reg[inst->value[par_nb] - 1], 0, REG_SIZE);
			else if (binary == REG_CODE)
				return (FALSE);
			else if (binary == IND_CODE)
			{
				value = inst->value[par_nb];
				inst->value[par_nb] = add_bytes(cw->vm.arena, p->pc + value,
						DIR_SIZE);
			}
		}
	return (TRUE);
}

void		execute_instruction(t_core *cw, t_process *p, t_inst *inst)
{
	static void(*exec[16])(t_core*, t_inst*, t_process*) = {
		live, ld, st, add, sub, and, or, xor, zjmp, ldi, sti, ffork, ld,
		ldi, ffork, aff };

	display_head(cw, p, inst);
	exec[inst->op - 1](cw, inst, p);
	if (test_bit(&(cw->utils.flags), CW_V16))
		ft_printf("\tPC increased of ["B_YELLOW"%4d"RESET"] ("B_WHITE"%0#6x"
		RESET" -> "B_WHITE"%0#6x"RESET")\n\n", i_pc(inst->size - p->pc), \
		p->pc, i_pc(inst->size));
	display_foot(cw, p, inst);
}
