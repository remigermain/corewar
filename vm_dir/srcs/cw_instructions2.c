/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_instructions2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/13 00:05:50 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/13 00:12:47 by rgermain    ###    #+. /#+    ###.fr     */
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

t_bool	add(t_core *cw, t_inst *inst, t_process *p)
{
	int	tmp[3];
	int	value;

	ft_memcpy(tmp, inst->value, 4 * 3);
	if (!convert_value(cw, p, inst, CW_P12))
		return (FALSE);
	if (test_bit(&(cw->utils.flags), CW_V4))
		ft_printf("\t("B_WHITE"%d"RESET" + "B_WHITE"%d"RESET")\n",
												inst->value[0], inst->value[1]);
	value = inst->value[0] + inst->value[1];
	if (!put_reg(cw, p, inst->value[2] - 1, value))
		return (FALSE);
	if (test_bit(&(cw->utils.flags), CW_DIFF))
	{
		ft_printf("P %4d | %s ", p->number, cw->tab[inst->op - 1].name);
		ft_printf("r%d r%d r%d\n", tmp[0], tmp[1], tmp[2]);
	}
	mod_carry(value, p);
	return (TRUE);
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

t_bool	sub(t_core *cw, t_inst *inst, t_process *p)
{
	int	value;
	int	tmp[3];

	ft_memcpy(tmp, inst->value, 4 * 3);
	if (!convert_value(cw, p, inst, CW_P12))
		return (FALSE);
	if (test_bit(&(cw->utils.flags), CW_V4))
		ft_printf("\t("B_WHITE"%d"RESET" - "B_WHITE"%d"RESET")\n",
												inst->value[0], inst->value[1]);
	value = inst->value[0] - inst->value[1];
	if (!put_reg(cw, p, inst->value[2] - 1, value))
		return (FALSE);
	if (test_bit(&(cw->utils.flags), CW_DIFF))
	{
		ft_printf("P %4d | %s ", p->number, cw->tab[inst->op - 1].name);
		ft_printf("r%d r%d r%d\n", tmp[0], tmp[1], tmp[2]);
	}
	mod_carry(value, p);
	return (TRUE);
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

t_bool	and(t_core *cw, t_inst *inst, t_process *p)
{
	int	value;
	int	tmp[3];

	if (!convert_value(cw, p, inst, CW_P12))
		return (FALSE);
	ft_memcpy(tmp, inst->value, 4 * 3);
	if (test_bit(&(cw->utils.flags), CW_V4))
		ft_printf("\t("B_WHITE"%d"RESET" & "B_WHITE"%d"RESET")\n",
												inst->value[0], inst->value[1]);
	value = inst->value[0] & inst->value[1];
	if (!put_reg(cw, p, inst->value[2] - 1, value))
		return (FALSE);
	if (test_bit(&(cw->utils.flags), CW_DIFF))
	{
		ft_printf("P %4d | %s ", p->number, cw->tab[inst->op - 1].name);
		ft_printf("%d %d r%d\n", tmp[0], tmp[1], tmp[2]);
	}
	mod_carry(value, p);
	return (TRUE);
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

t_bool	or(t_core *cw, t_inst *inst, t_process *p)
{
	int	value;
	int	tmp[3];

	if (!convert_value(cw, p, inst, CW_P12))
		return (FALSE);
	ft_memcpy(tmp, inst->value, 4 * 3);
	if (test_bit(&(cw->utils.flags), CW_V4))
		ft_printf("\t("B_WHITE"%d"RESET" | "B_WHITE"%d"RESET")\n",
												inst->value[0], inst->value[1]);
	value = inst->value[0] | inst->value[1];
	if (!put_reg(cw, p, inst->value[2] - 1, value))
		return (FALSE);
	if (test_bit(&(cw->utils.flags), CW_DIFF))
	{
		ft_printf("P %4d | %s ", p->number, cw->tab[inst->op - 1].name);
		ft_printf("%d %d r%d\n", tmp[0], tmp[1], tmp[2]);
	}
	mod_carry(value, p);
	return (TRUE);
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

t_bool	xor(t_core *cw, t_inst *inst, t_process *p)
{
	int	value;
	int	tmp[3];

	if (!convert_value(cw, p, inst, CW_P12))
		return (FALSE);
	ft_memcpy(tmp, inst->value, 4 * 3);
	if (test_bit(&(cw->utils.flags), CW_V4))
		ft_printf("\t("B_WHITE"%d"RESET" ^ "B_WHITE"%d"RESET")\n",
												inst->value[0], inst->value[1]);
	value = inst->value[0] ^ inst->value[1];
	if (!put_reg(cw, p, inst->value[2] - 1, value))
		return (FALSE);
	if (test_bit(&(cw->utils.flags), CW_DIFF))
	{
		ft_printf("P %4d | %s ", p->number, cw->tab[inst->op - 1].name);
		ft_printf("%d %d r%d\n", tmp[0], tmp[1], tmp[2]);
	}
	mod_carry(value, p);
	return (TRUE);
}
