/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_read_instructions.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/16 11:56:11 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/14 01:15:34 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
** get value depending on ocp encoding
**-----------------------------------------------------------------------
*/

static int		get_value(t_core *cw, t_inst *inst, int binary)
{
	int	value;

	value = 0;
	if (binary == REG_CODE)
		return (cw->vm.arena[i_pc(inst->size++)]);
	else if (binary == DIR_CODE)
	{
		value = add_bytes(cw->vm.arena, i_pc(inst->size),
				cw->tab[inst->op - 1].dir_size);
		if (cw->tab[inst->op - 1].dir_size == 2)
			value = (short)value;
	}
	else if (binary == IND_CODE)
		value = (short)add_bytes(cw->vm.arena, i_pc(inst->size), 2);
	inst->size = i_pc(inst->size + (binary == IND_CODE ? 2 :
				cw->tab[inst->op - 1].dir_size));
	return (value);
}

/*
**-----------------------------------------------------------------------
** if there is an ocp error, get OCP size regardless of OCP validity
**-----------------------------------------------------------------------
*/

static t_bool	error_ocp(t_core *cw, t_inst *inst, t_process *p)
{
	int	param_nb;
	int	binary;

	param_nb = 0;
	inst->size = i_pc(p->pc + 1);
	if (cw->tab[inst->op - 1].octal)
		inst->size = i_pc(inst->size + 1);
	while (++param_nb <= cw->tab[inst->op - 1].nb_args)
	{
		binary = (inst->ocp >> binary_shift(param_nb)) & 0x03;
		if (binary == REG_CODE)
			inst->size = i_pc(inst->size + 1);
		else if (binary == DIR_CODE)
			inst->size = i_pc(inst->size +
					cw->tab[inst->op - 1].dir_size);
		else if (binary == IND_CODE)
			inst->size = i_pc(inst->size + 2);
	}
	return (FALSE);
}

/*
**-----------------------------------------------------------------------
** check ocp validity and get encoding informations
**-----------------------------------------------------------------------
*/

static t_bool	check_ocp(t_core *cw, t_inst *inst, t_process *p)
{
	int	param_nb;
	int	binary;

	param_nb = 0;
	if (cw->tab[inst->op - 1].octal)
		inst->ocp = cw->vm.arena[i_pc(inst->size++)];
	else
		inst->ocp = (inst->op == CW_AFF) ? (REG_CODE << 6) : (DIR_CODE << 6);
	while (++param_nb <= cw->tab[inst->op - 1].nb_args)
	{
		binary = (inst->ocp >> binary_shift(param_nb)) & 0x03;
		if (!binary)
			return (error_ocp(cw, inst, p));
		if (!(cw->tab[inst->op - 1].args[param_nb - 1] & (1 << (binary - 1))))
			return (error_ocp(cw, inst, p));
		else
			inst->value[param_nb - 1] = get_value(cw, inst, binary);
	}
	return (TRUE);
}

/*
**-----------------------------------------------------------------------
** get OP code and return the corresponding number of cycles,
** if it doesn't exist return 1
**-----------------------------------------------------------------------
*/

int				next_inst(t_core *cw, t_process *p)
{
	p->op = cw->vm.arena[i_pc(p->pc)];
	if (p->op >= CW_LIVE && p->op <= CW_AFF)
		return (cw->tab[p->op - 1].cycles);
	else
		return (1);
}

/*
**-----------------------------------------------------------------------
** execute instruction if OP code and OCP are valid
** otherwise replace PC by OCP size
**-----------------------------------------------------------------------
*/

void			launch_instruction(t_core *cw, t_process *p)
{
	t_inst	inst;

	ft_bzero(&inst, sizeof(t_inst));
	inst.size = i_pc(p->pc + 1);
	inst.pc = i_pc(p->pc);
	inst.op = p->op;
	if (p->op >= CW_LIVE && p->op <= CW_AFF)
	{
		if (check_ocp(cw, &inst, p))
		{
			inst.mem = inst.size - inst.pc;
			execute_instruction(cw, p, &inst);
		}
		inst.mem = inst.size - inst.pc;
		if (inst.op != CW_FORK && inst.op != CW_LFORK)
			diff_base(cw, p, &inst, inst.mem);
	}
	if (inst.op != CW_FORK && inst.op != CW_LFORK)
	{
		p->pc = i_pc(inst.size);
		cw->vm.pc[i_pc(inst.size)] = p->player + 1;
	}
}
