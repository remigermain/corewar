/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/17 09:39:51 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 10:20:32 by rcepre      ###    #+. /#+    ###.fr     */
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
	int printed_labels;

	printed_labels = 0;
	if (!ft_options("v", DECODE))
		return ;
	display_tab_header();
	while (file)
	{
		printed_labels += display_line_data(file);
		file = file->nxt;
	}
	display_leftovers_labels(file_data, printed_labels);
	ft_printf("%86@\n", "char", '-');
	if (file_data)
		display_header_data(file_data->header);
}

int			display_label_link(t_linelst *file)
{
	int		label_nb;
	int		i;
	char	*name;
	int		ret;

	i = -1;
	ret = 0;
	name = NULL;
	label_nb = manage_labels(NULL, NULL, 0, ML_GET_LAB_NB);
	while (++i < label_nb)
	{
		if (manage_labels(NULL, NULL, i, ML_GET_ADDR) == file->addr)
		{
			manage_labels(NULL, &name, i, ML_GET_LAB_NAME);
			ft_printf(YELLOW "<- %s " RESET, name);
			ret++;
		}
	}
	return (ret);
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

int			display_line_data(t_linelst *file)
{
	static const t_op	*op_tab = NULL;
	int					printed_labels;

	printed_labels = 0;
	if (!op_tab)
		op_tab = get_op_tab();
	if (file->opcode > 0)
	{
		ft_printf("l%-3d | ", file->line_nb);
		ft_printf(GREEN "%#-5.5s ", op_tab[file->opcode - 1].name);
		ft_printf(BLUE"%2d " RESET " | ", file->opcode);
		ft_printf(RESET"%08b  "RESET"%2x |", file->octal, file->octal);
		display_arg_values(file, op_tab);
		ft_printf("" CYAN " 0x%-4x"RESET"  " RESET, file->addr);
		printed_labels = display_label_link(file);
		ft_printf("\n");
	}
	return (printed_labels);
}
