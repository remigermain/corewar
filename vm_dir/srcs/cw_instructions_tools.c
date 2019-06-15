/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_instructions_tools.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/23 12:47:14 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/13 00:18:18 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
**		put "value" into reg[i_reg]
**-----------------------------------------------------------------------
*/

t_bool	put_reg(t_core *cw, t_process *p, int i_reg, int value)
{
	int	j;

	j = -1;
	if ((i_reg >= REG_NUMBER || i_reg < 0))
		return (FALSE);
	if (test_bit(&(cw->utils.flags), CW_V4))
		ft_printf("\tPut "B_WHITE"%d"RESET" into "COL_REG"r%d\n"RESET, value,
				i_reg + 1);
	while (++j < REG_SIZE)
		p->reg[i_reg][j] = (value << (j * 8)) >> 24;
	return (TRUE);
}

/*
**-----------------------------------------------------------------------
**		put "value" into arena[i_are]
**-----------------------------------------------------------------------
*/

void	put_arena(t_core *cw, t_process *pro, int i_are, int value)
{
	int	i;

	i = -1;
	if (test_bit(&(cw->utils.flags), CW_V4))
		ft_printf("\tPut "B_WHITE"%d"RESET" to arena[" B_PINK "%d"RESET"]\n"
				RESET, value, i_are);
	while (++i < DIR_SIZE)
	{
		cw->vm.arena[i_pc(i_are + i)] = (value << (i * 8)) >> 24;
		cw->vm.color[i_pc(i_are + i)] = pro->player + 1;
	}
}

/*
**-----------------------------------------------------------------------
**		convert add to adresses
**-----------------------------------------------------------------------
*/

int		convert_adress(t_process *p, t_inst *inst, int add)
{
	if (inst->op == CW_LLD || inst->op == CW_LLDI || inst->op == CW_LFORK)
		return (p->pc + add);
	return (p->pc + (add % IDX_MOD));
}

/*
**-----------------------------------------------------------------------
**		modify carry, if param worth 0 carry pass to 1, otherwise to 0
**-----------------------------------------------------------------------
*/

void	mod_carry(int param, t_process *p)
{
	p->carry = (!param ? 1 : 0);
}

/*
**-----------------------------------------------------------------------
**		convert negative or taller index to MEM_SIZE format
**-----------------------------------------------------------------------
*/

int		i_pc(int dest)
{
	if (dest < 0)
		return (MEM_SIZE + (dest % MEM_SIZE));
	else if (dest >= MEM_SIZE)
		return (dest % MEM_SIZE);
	return (dest);
}
