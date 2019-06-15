/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_ins_arguments_value_check.c              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 17:14:46 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 10:41:18 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

void	check_maxs(t_linelst *file, int head, int arg_type, long value)
{
	static const t_op	*op_tab = NULL;

	if (!op_tab)
		op_tab = get_op_tab();
	if (arg_type == REG_CODE && (value < 1 || value > REG_NUMBER))
		put_error(file, head, g_str[E_INV_REG_VAL], PE_ERR);
	else if (arg_type == IND_CODE)
	{
		if (value > FT_SHRT_MAX || value < FT_SHRT_MIN)
			value > FT_SHRT_MAX ? put_error(file, head, g_str[E_IND_SHRT_MAX],
			PE_WARN) : put_error(file, head, g_str[E_IND_EX_SHRT_MIN], PE_WARN);
	}
	else if (arg_type == DIR_CODE && op_tab[file->opcode - 1].dir_size == 2)
	{
		if (value > FT_SHRT_MAX || value < FT_SHRT_MIN)
			value > FT_SHRT_MAX ? put_error(file, head, g_str[E_DIR_SHRT_MAX],
			PE_WARN) : put_error(file, head, g_str[E_DIR_EX_SHRT_MIN], PE_WARN);
	}
	else if (arg_type == DIR_CODE && op_tab[file->opcode - 1].dir_size == 4)
	{
		if (value > FT_INT_MAX)
			put_error(file, head, g_str[E_DIR_EX_INT_MAX], PE_WARN);
		else if (value < FT_INT_MIN)
			put_error(file, head, g_str[E_DIR_EX_INT_MIN], PE_WARN);
	}
}
