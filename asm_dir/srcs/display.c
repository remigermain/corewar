/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/17 09:39:51 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/09 17:43:05 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

void		display_header_data(t_header header)
{
	ft_printf("name:    "BLUE"%s"RESET"  ", header.prog_name);
	if (header.prog_size > CHAMP_MAX_SIZE)
		ft_printf("size:    "B_RED"%d"RESET"  ", header.prog_size);
	else
		ft_printf("size:    "GREEN"%d"RESET"  ", header.prog_size);
	ft_printf("comment: "PINK"%s\n"RESET, header.comment);
}

void		display_data(t_file *file_data, t_linelst *file)
{
	if (!ft_options("v", DECODE))
		return ;
	ft_printf("\n");
	ft_printf("line | ins   opc |  oct(b)  oct | arg 1 value   | arg 2 value   \
| arg 3 value   | addr\n");
	ft_printf("----------------------------------------------------------------\
----------------------\n");
	while (file)
	{
		display_line_data(file);
		file = file->nxt;
	}
	ft_printf("----------------------------------------------------------------\
----------------------\n");
	if (file_data)
		display_header_data(file_data->header);
}

void		display_label_link(t_linelst *file)
{
	int		label_nb;
	int		i;
	char	*name;

	i = -1;
	name = NULL;
	label_nb = manage_labels(NULL, NULL, 0, ML_GET_LAB_NB);
	while (++i < label_nb)
	{
		if (manage_labels(NULL, NULL, i, ML_GET_ADDR) == file->addr)
		{
			manage_labels(NULL, &name, i, ML_GET_LAB_NAME);
			ft_printf(YELLOW "<- %s " RESET, name);
		}
	}
}

void		display_arg_values(t_linelst *file, const t_op *op_tab)
{
	int i;
	int code;

	i = -1;
	while (++i < 3)
	{
		if (file->labels >> i & 0x1)
			ft_printf(B_YELLOW "*" RESET);
		else
			ft_printf(" ");
		code = (file->octal >> binary_shift(i + 1) & 0x3);
		if (i < op_tab[file->opcode - 1].nb_args && code == REG_CODE)
			ft_printf(PINK " r%-11.1d " RESET "|", file->param[i]);
		else if (i < op_tab[file->opcode - 1].nb_args && code == DIR_CODE)
			ft_printf(GREEN " %%%-11.1d " RESET "|", file->param[i]);
		else if (i < op_tab[file->opcode - 1].nb_args && code == IND_CODE)
			ft_printf(CYAN " %-11.1d  " RESET "|", file->param[i]);
		else
			ft_printf(B_BLACK "      -       " RESET "|");
	}
}

void		display_line_data(t_linelst *file)
{
	static const t_op	*op_tab = NULL;

	if (!op_tab)
		op_tab = get_op_tab();
	if (file->opcode > 0)
	{
		ft_printf("l%-3d | ", file->line_nb);
		ft_printf(GREEN "%#-5.5s ", op_tab[file->opcode - 1].name);
		ft_printf(BLUE"%2d " RESET " | ", file->opcode);
		ft_printf(COL_OCT_B"%08b  "COL_OCT"%2x |", file->octal, file->octal);
		display_arg_values(file, op_tab);
		ft_printf("" CYAN " 0x%-4x"RESET"  " RESET, file->addr);
		display_label_link(file);
		ft_printf("\n");
	}
}
