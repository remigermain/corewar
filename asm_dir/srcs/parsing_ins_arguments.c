/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_ins_arguments.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 06:46:56 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 12:28:57 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

static int	check_arg_type(t_linelst *file, int head, int param, int arg_type)
{
	const	t_op *op_tab = NULL;

	if (!op_tab)
		op_tab = get_op_tab();
	arg_type = arg_type == 3 ? 4 : arg_type;
	if (!(arg_type & op_tab[file->opcode - 1].args[param - 1]))
		put_error(file, head, ERR_ARG_TYPE, PE_ERR);
	return (0);
}

static void	extract_data(t_linelst *file, int *head, int param)
{
	int		arg_type;

	*head += spn_whspaces(file->line + *head);
	if ((arg_type = get_arguments_value(file, *head, param)))
	{
		file->octal += arg_type << binary_shift(param);
		check_arg_type(file, *head, param, arg_type);
	}
	else
	{
		if (file->line[*head] && file->line[*head] != LABEL_CHAR)
		{
			put_error(file, *head, ERR_UNEXP_EXPR, PE_ERR);
			file->line[*head] = ' ';
		}
		else if (ft_strlastchr(file->line) == SEPARATOR_CHAR)
			put_error(file, *head, ERR_EXP_EXPR, PE_ERR);
		else
			put_error(file, *head, ERR_INV_ARG, PE_ERR);
	}
	file->param_type[param - 1] = arg_type;
	*head += ft_strchri(file->line + *head, SEPARATOR_CHAR) + 1;
}

static void	check_too_many_args(t_linelst *file, int head)
{
	if (ft_strchr(file->line + head - 1, SEPARATOR_CHAR))
	{
		if (*(file->line + head + spn_whspaces(file->line + head)))
			put_error(file, head + spn_whspaces(file->line + head), \
												ERR_TOO_ARG, PE_ERR);
		else
			put_error(file, head - 1, ERR_EXP_EXPR, PE_ERR);
	}
}

static int	check_arg_nb(t_linelst *file, int head, int param, int nb_args)
{
	if (!ft_strchr(file->line + head, SEPARATOR_CHAR) && param < nb_args)
	{
		put_error(file, spn_label(file->line), ERR_MISS_ARG, PE_ERR);
		return (1);
	}
	return (0);
}

int			get_arguments(t_linelst *file)
{
	int					param;
	int					head;
	static const t_op	*op_tab = NULL;

	if (!op_tab)
		op_tab = get_op_tab();
	if (file->opcode < 0)
		return (0);
	param = 0;
	head = spn_label(file->line);
	if (ft_strnstr(file->line + head, op_tab[file->opcode - 1].name,\
									ft_strlen(op_tab[file->opcode - 1].name)))
	{
		head += ft_strlen(op_tab[file->opcode - 1].name);
	}
	while (++param <= op_tab[file->opcode - 1].nb_args)
	{
		if (check_arg_nb(file, head, param, op_tab[file->opcode - 1].nb_args))
			return (0);
		extract_data(file, &head, param);
	}
	check_too_many_args(file, head);
	return (0);
}
