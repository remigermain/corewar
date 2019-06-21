/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pasing_memory.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 17:28:26 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 09:53:15 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

static int	weigher(t_linelst *file, int param, const t_op *op_tab)
{
	int	octal;
	int	weight;

	octal = file->octal >> binary_shift(param) & 0x3;
	weight = octal == REG_CODE ? 1 : 0;
	weight = octal == IND_CODE ? 2 : weight;
	weight = octal == DIR_CODE ? op_tab[file->opcode - 1].dir_size : weight;
	return (weight);
}

int			get_memory(t_linelst *file)
{
	static const t_op	*op_tab = NULL;
	int					param;
	static int			addr = 0;

	if (!addr)
	{
		if (!op_tab)
			op_tab = get_op_tab();
		while (file)
		{
			if (file->opcode > 0)
			{
				param = 0;
				file->weight = 1 + op_tab[file->opcode - 1].octal;
				while (++param <= op_tab[file->opcode - 1].nb_args)
					file->weight += weigher(file, param, op_tab);
				file->addr = addr;
				addr += file->weight;
			}
			file = file->nxt;
		}
	}
	return (addr);
}
