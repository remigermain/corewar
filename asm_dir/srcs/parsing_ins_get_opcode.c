/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_ins_get_opcode.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 17:15:53 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 10:00:23 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

int	get_opcode(char *line, t_linelst *file)
{
	int			i;
	const t_op	*op_tab;

	op_tab = get_op_tab();
	i = 16;
	line += spn_label(line);
	if (!*line)
		return (-1);
	while (--i >= 0)
	{
		if (!ft_strncmp(line, op_tab[i].name, ft_strlen(op_tab[i].name)))
			if (ft_iswhitespace(line[ft_strlen(op_tab[i].name)]) ||
					!line[ft_strlen(op_tab[i].name)])
				return (i + 1);
	}
	if (ft_isalpha(file->line[spn_label(file->line)]))
		put_error(file, spn_label(file->line), g_str[E_INV_MNEM], PE_ERR);
	else
		put_error(file, spn_label(file->line), g_str[E_UNEXP_EXPR], PE_ERR);
	return (0);
}
