/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_instructions3.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/23 12:50:49 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 14:23:01 by rcepre      ###    #+. /#+    ###.fr     */
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

void	st(t_core *cw, t_inst *inst, t_process *p)
{
	static int head = 0;

	play_audio(cw, head + 12, ST_CHAN);
	head = head == 3 ? 0 : head + 1;
	cw->vm.color[i_pc(p->pc)] = 40 + p->player + 1;
	cw->vm.pc[i_pc(p->pc)] = 40 + p->player + 1;
	if (!convert_value(cw, p, inst, CW_P1))
		return ;
	if (inst->ocp == 0x50 && !put_reg(cw, p, \
										inst->value[1] - 1, inst->value[0]))
		return ;
	else if (inst->ocp == 0x70)
		put_arena(cw, p, p->pc + (inst->value[1] % IDX_MOD), inst->value[0]);
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

void	sti(t_core *cw, t_inst *inst, t_process *p)
{
	static int head = 0;

	play_audio(cw, head + 12, ST_CHAN);
	head = head == 3 ? 0 : head + 1;
	cw->vm.color[i_pc(p->pc)] = 40 + p->player + 1;
	cw->vm.pc[i_pc(p->pc)] = 40 + p->player + 1;
	if (!convert_value(cw, p, inst, CW_P123))
		return ;
	if (test_bit(&(cw->utils.flags), CW_V4))
		ft_printf("\tstore to pc + (("B_WHITE"%d"RESET" + "
		B_WHITE"%d"RESET") %% IDX_MOD)\n", inst->value[1], inst->value[2]);
	put_arena(cw, p, \
		p->pc + ((inst->value[1] + inst->value[2]) % IDX_MOD), inst->value[0]);
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

void	ld(t_core *cw, t_inst *inst, t_process *p)
{
	cw->vm.color[i_pc(p->pc)] = 40 + p->player + 1;
	cw->vm.pc[i_pc(p->pc)] = 40 + p->player + 1;
	if (!convert_value(cw, p, inst, CW_P1))
		return ;
	if (put_reg(cw, p, inst->value[1] - 1, inst->value[0]))
		mod_carry(inst->value[0], p);
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

void	ldi(t_core *cw, t_inst *inst, t_process *p)
{
	int	value;

	cw->vm.color[i_pc(p->pc)] = 40 + p->player + 1;
	cw->vm.pc[i_pc(p->pc)] = 40 + p->player + 1;
	if (!convert_value(cw, p, inst, CW_P12))
		return ;
	if (test_bit(&(cw->utils.flags), CW_V4))
	{
		if (inst->op == CW_LDI)
			ft_printf("\tstore to pc + (("B_WHITE"%d"RESET" + "
			B_WHITE"%d"RESET") %% IDX_MOD)\n", inst->value[1], inst->value[2]);
		else
			ft_printf("\tstore to pc + ("B_WHITE"%d"RESET" + "
			B_WHITE"%d"RESET")\n", inst->value[1], inst->value[2]);
	}
	value = convert_adress(p, inst, inst->value[0] + inst->value[1]);
	value = p->pc + value;
	value = add_bytes(cw->vm.arena, value, DIR_SIZE);
	if (put_reg(cw, p, inst->value[2] - 1, value) && inst->op == CW_LLDI)
		mod_carry(value, p);
}
