/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_instructions3.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/23 12:50:49 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/14 14:21:43 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
**		st :
**
** Direct transfer Registry > RAM / Registry. Load the content of the
** register passed in the first parameter in the second parameter.
** If the value of the first parameter is equal to zero,
** then the carry goes to state one, otherwise to state zero.
**-----------------------------------------------------------------------
*/

t_bool	st(t_core *cw, t_inst *inst, t_process *p)
{
	int	tmp[3];

	play_st(cw);
	cw->vm.color[i_pc(p->pc)] = 40 + p->player + 1;
	cw->vm.pc[i_pc(p->pc)] = 40 + p->player + 1;
	ft_memcpy(tmp, inst->value, 4 * 3);
	if (!convert_value(cw, p, inst, CW_P1))
		return (FALSE);
	if (((inst->ocp >> 4) & 0x3) == REG_CODE &&
			!put_reg(cw, p, inst->value[1] - 1, inst->value[0]))
		return (FALSE);
	else if (((inst->ocp >> 4) & 0x3) == IND_CODE)
		put_arena(cw, p, convert_adress(p, inst, inst->value[1]),
				inst->value[0]);
	if (test_bit(&(cw->utils.flags), CW_DIFF))
	{
		ft_printf("P %4d | %s ", p->number, cw->tab[inst->op - 1].name);
		ft_printf("r%d %d\n", tmp[0], tmp[1]);
	}
	return (TRUE);
}

/*
**-----------------------------------------------------------------------
**		sti :
**
** Indirect transfer Registry > RAM. Load the value contained in
** the register passed as the first parameter to the resulting address of
** the addition of the last two parameters.
** If this value is nil, then the carry passes to state one,
** otherwise to the zero state.
**-----------------------------------------------------------------------
*/

t_bool	sti(t_core *cw, t_inst *inst, t_process *p)
{
	int value;
	int	add;
	int	mem;

	play_st(cw);
	cw->vm.color[i_pc(p->pc)] = 40 + p->player + 1;
	cw->vm.pc[i_pc(p->pc)] = 40 + p->player + 1;
	if (test_bit(&(cw->utils.flags), CW_DIFF))
		if (((inst->ocp >> 6) & 0x3) == T_REG)
			mem = inst->value[0];
	if (!convert_value(cw, p, inst, CW_P123))
		return (FALSE);
	if (test_bit(&(cw->utils.flags), CW_V4))
		ft_printf("\tstore to pc + (("B_WHITE"%d"RESET" + "
		B_WHITE"%d"RESET") %% IDX_MOD)\n", inst->value[1], inst->value[2]);
	value = inst->value[1] + inst->value[2];
	add = convert_adress(p, inst, value);
	diff_sti(cw, inst, p, mem);
	put_arena(cw, p, add, inst->value[0]);
	return (TRUE);
}

/*
**-----------------------------------------------------------------------
**		ld :
**
** Direct RAM transfer > Registry. Load the first parameter into
** the register passed in second parameter. If the value of the first
** parameter is equal to zero,
** then the carry goes to state one, otherwise to state zero.
**
**		lld:
**
** Same as ld but without addressing restrictions.
**-----------------------------------------------------------------------
*/

t_bool	ld(t_core *cw, t_inst *inst, t_process *p)
{
	int	mem;

	play_ld(cw);
	cw->vm.color[i_pc(p->pc)] = 40 + p->player + 1;
	cw->vm.pc[i_pc(p->pc)] = 40 + p->player + 1;
	mem = inst->value[0];
	if (!convert_value(cw, p, inst, CW_P1))
		return (FALSE);
	if (put_reg(cw, p, inst->value[1] - 1, inst->value[0]))
		mod_carry(inst->value[0], p);
	else
		return (FALSE);
	if (test_bit(&(cw->utils.flags), CW_DIFF))
	{
		if (((inst->ocp >> 4) & 0x3) == T_REG)
			mem = inst->value[0];
		ft_printf("P %4d | %s %d ", p->number, cw->tab[inst->op - 1].name, mem);
		if (((inst->ocp >> 4) & 0x3) == T_REG)
			ft_printf("r");
		ft_printf("%d\n", inst->value[1]);
	}
	return (TRUE);
}

/*
**-----------------------------------------------------------------------
**		ldi :
**
** Indirect RAM transfer > Registry. Load the value to the address
** resulting from the addition of the first two parameters,
** in the register passed in the third parameter.
** If this value is nil, then the carry passes to state one,
** otherwise to the zero state.
**
**		lldi :
**
** Same as ldi but without addressing restrictions.
**-----------------------------------------------------------------------
*/

t_bool	ldi(t_core *cw, t_inst *inst, t_process *p)
{
	int	value;
	int	add;
	int	mem;

	play_ld(cw);
	cw->vm.color[i_pc(p->pc)] = 40 + p->player + 1;
	cw->vm.pc[i_pc(p->pc)] = 40 + p->player + 1;
	if (!convert_value(cw, p, inst, CW_P12))
		return (FALSE);
	if (test_bit(&(cw->utils.flags), CW_V4))
	{
		if (inst->op == CW_LDI)
			ft_printf("\tstore to pc + (("B_WHITE"%d"RESET" + "
			B_WHITE"%d"RESET") %% IDX_MOD)\n", inst->value[1], inst->value[2]);
		else
			ft_printf("\tstore to pc + ("B_WHITE"%d"RESET" + "
			B_WHITE"%d"RESET")\n", inst->value[1], inst->value[2]);
	}
	value = inst->value[0] + inst->value[1];
	mem = convert_adress(p, inst, value);
	add = add_bytes(cw->vm.arena, mem, REG_SIZE);
	if (put_reg(cw, p, inst->value[2] - 1, add) && inst->op == CW_LLDI)
		mod_carry(add, p);
	diff_ldi(cw, inst, p);
	return (TRUE);
}
