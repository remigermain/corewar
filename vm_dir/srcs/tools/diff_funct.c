/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_instructions3.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/23 12:50:49 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/14 00:43:56 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

void	diff_sti(t_core *cw, t_inst *inst, t_process *p, int mem)
{
	int value;
	int	add;

	value = inst->value[1] + inst->value[2];
	add = convert_adress(p, inst, value);
	if (test_bit(&(cw->utils.flags), CW_DIFF))
	{
		ft_printf("P %4d | %s ", p->number, cw->tab[inst->op - 1].name);
		if (((inst->ocp >> 6) & 0x3) == T_REG)
			ft_printf("r");
		ft_printf("%d %d %d", mem, inst->value[1], inst->value[2]);
		ft_printf("\n       | -> store to %d + %d = %d (with pc and mod %d)\n",
				inst->value[1], inst->value[2], value, add);
	}
}

void	diff_ldi(t_core *cw, t_inst *inst, t_process *p)
{
	int	value;
	int	mem;

	value = inst->value[0] + inst->value[1];
	mem = convert_adress(p, inst, value);
	add_bytes(cw->vm.arena, mem, REG_SIZE);
	if (test_bit(&(cw->utils.flags), CW_DIFF))
	{
		ft_printf("P %4d | %s ", p->number, cw->tab[inst->op - 1].name);
		ft_printf("%d %d r%d", inst->value[0], inst->value[1], inst->value[2]);
		ft_printf("\n       | -> load from %d + %d = %d ",
			inst->value[0], inst->value[1], value);
		if (inst->op == CW_LLDI)
			ft_printf("(with pc %d)\n", mem);
		else
			ft_printf("(with pc and mod %d)\n", mem);
	}
}

void	diff_fork(t_core *cw, t_inst *inst, t_process *fork)
{
	if (test_bit(&(cw->utils.flags), CW_DIFF))
	{
		ft_printf("P %4d | %s %d (%d)\n", fork->number,
				cw->tab[inst->op - 1].name, inst->value[0],
				convert_adress(fork, inst, inst->value[0]));
		diff_base(cw, fork, inst, inst->mem);
	}
}

void	diff_base(t_core *cw, t_process *p, t_inst *inst, int mem)
{
	if (test_bit(&(cw->utils.flags), CW_DIFF) &&
			(inst->op != CW_ZJMP || !p->carry))
	{
		ft_printf("ADV %d (%.4p -> %.4p) ", i_pc(inst->size - inst->pc),
				i_pc(inst->pc), i_pc(inst->pc) + i_pc(mem));
		mem = i_pc(mem);
		while (mem > 0)
		{
			ft_printf("%.2x ", cw->vm.arena[i_pc(inst->pc++)]);
			mem--;
		}
		ft_printf("\n");
	}
}
