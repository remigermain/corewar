/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_ins.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/16 12:04:53 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/20 06:07:57 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

static int		is_instruction(char *line)
{
	int			head;

	head = spn_whspaces(line);
	if (ft_strnstr(line + head, COMMENT_STR, ft_strlen(COMMENT_STR)))
		return (0);
	if (ft_strnstr(line + head, NAME_STR, ft_strlen(NAME_STR)))
		return (0);
	return (1);
}

void			get_instructions(t_linelst *file)
{
	t_linelst	*start;
	int			n;

	start = file;
	n = 0;
	while ((file))
	{
		if (is_instruction(file->line))
		{
			if ((file->opcode = get_opcode(file->line, file)) == 0 && n)
				file = delete_linelst_elem(start, file);
			else
				get_arguments(file);
		}
		n++;
		file = file->nxt;
	}
	file = start;
}
