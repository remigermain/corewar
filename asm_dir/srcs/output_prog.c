/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   output_prog.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/10 00:31:11 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 17:12:13 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

void	output_arg_value(t_linelst *file, int param, int fd_output,
															const t_op *op_tab)
{
	int	size;
	int	value;

	size = file->param_type[param - 1] == REG_CODE ? 1 : 0;
	size = file->param_type[param - 1] == IND_CODE ? 2 : size;
	if (file->param_type[param - 1] == DIR_CODE)
		size = op_tab[file->opcode - 1].dir_size;
	value = file->param[param - 1];
	if (size == 2)
		value = ft_reverse_ushort_bytes((short)value);
	if (size == 4)
		value = ft_reverse_uint_bytes((int)value);
	write(fd_output, &value, size);
}

void	output_line(t_linelst *file, int fd_output)
{
	static const t_op	*op_tab = NULL;
	int					param;

	if (!op_tab)
		op_tab = get_op_tab();
	param = 0;
	write(fd_output, &file->opcode, 1);
	if (op_tab[file->opcode - 1].octal)
		write(fd_output, &file->octal, 1);
	while (++param <= op_tab[file->opcode - 1].nb_args)
		output_arg_value(file, param, fd_output, op_tab);
}

void	output_prog(t_linelst *file, int fd_output)
{
	while (file)
	{
		if (file->opcode > 0)
			output_line(file, fd_output);
		file = file->nxt;
	}
}
