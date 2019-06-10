/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_instructions2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/23 12:49:44 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/09 17:45:54 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
**		add :
**
** Adds the second parameter to the first parameter, and
** stores the result in the third parameter.
** If the resulting value is equal to zero,
** then the carry goes to state one, otherwise to state zero.
**-----------------------------------------------------------------------
*/

void	add(t_core *cw, t_inst *inst, t_process *p)
{
	int	value;

	if (!convert_value(cw, p, inst, CW_P12))
		return ;
	if (test_bit(&(cw->utils.flags), CW_V4))
		ft_printf("\t("B_WHITE"%d"RESET" + "B_WHITE"%d"RESET")\n",
												inst->value[0], inst->value[1]);
	value = inst->value[0] + inst->value[1];
	if (!put_reg(cw, p, inst->value[2] - 1, value))
		return ;
	mod_carry(value, p);
}

/*
**-----------------------------------------------------------------------
**		sub :
**
** Subtracts the second parameter from the first parameter, and
** stores the result in the third parameter.
** If the resulting value is equal to zero,
** then the carry goes to state one, otherwise to state zero.
**-----------------------------------------------------------------------
*/

void	sub(t_core *cw, t_inst *inst, t_process *p)
{
	int	value;

	if (!convert_value(cw, p, inst, CW_P12))
		return ;
	value = inst->value[0] - inst->value[1];
	if (test_bit(&(cw->utils.flags), CW_V4))
		ft_printf("\t("B_WHITE"%d"RESET" - "B_WHITE"%d"RESET")\n",
												inst->value[0], inst->value[1]);
	if (!put_reg(cw, p, inst->value[2] - 1, value))
		return ;
	mod_carry(value, p);
}

/*
**-----------------------------------------------------------------------
**		and :
**
** Performs a logical AND between the first two parameters and
** stores the result in the third parameter.
** If the resulting value is equal to zero,
** then the carry goes to state one, otherwise to state zero.
**-----------------------------------------------------------------------
*/

void	and(t_core *cw, t_inst *inst, t_process *p)
{
	int	value;

	if (!convert_value(cw, p, inst, CW_P12))
		return ;
	value = inst->value[0] & inst->value[1];
	if (test_bit(&(cw->utils.flags), CW_V4))
		ft_printf("\t("B_WHITE"%d"RESET" & "B_WHITE"%d"RESET")\n",
												inst->value[0], inst->value[1]);
	if (!put_reg(cw, p, inst->value[2] - 1, value))
		return ;
	mod_carry(value, p);
}

/*
**-----------------------------------------------------------------------
**		or :
**
** Performs a logical OR between the first two parameters and
** stores the result in the third parameter.
** If the resulting value is equal to zero,
** then the carry goes to state one, otherwise to state zero.
**-----------------------------------------------------------------------
*/

void	or(t_core *cw, t_inst *inst, t_process *p)
{
	int	value;

	if (!convert_value(cw, p, inst, CW_P12))
		return ;
	value = inst->value[0] | inst->value[1];
	if (test_bit(&(cw->utils.flags), CW_V4))
		ft_printf("\t("B_WHITE"%d"RESET" | "B_WHITE"%d"RESET")\n",
												inst->value[0], inst->value[1]);
	if (!put_reg(cw, p, inst->value[2] - 1, value))
		return ;
	mod_carry(value, p);
}

/*
**-----------------------------------------------------------------------
**		xor :
**
** Performs a logical XOR between the first two parameters and
** stores the result in the third parameter.
** If the resulting value is equal to zero,
** then the carry goes to state one, otherwise to state zero.
**-----------------------------------------------------------------------
*/

void	xor(t_core *cw, t_inst *inst, t_process *p)
{
	int	value;

	if (!convert_value(cw, p, inst, CW_P12))
		return ;
	value = inst->value[0] ^ inst->value[1];
	if (test_bit(&(cw->utils.flags), CW_V4))
		ft_printf("\t("B_WHITE"%d"RESET" ^ "B_WHITE"%d"RESET")\n",
												inst->value[0], inst->value[1]);
	if (!put_reg(cw, p, inst->value[2] - 1, value))
		return ;
	mod_carry(value, p);
}
