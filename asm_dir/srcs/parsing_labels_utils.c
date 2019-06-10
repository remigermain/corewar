/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_labels_utils.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/08 06:59:35 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 17:25:38 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

int		count_labels(t_linelst *file)
{
	int	count;

	count = 0;
	while (file)
	{
		if (is_label(file->line))
			count++;
		file = file->nxt;
	}
	return (count);
}

int		find_addr(t_linelst *file)
{
	while (file->nxt && file->opcode <= 0)
		file = file->nxt;
	if (file->opcode == 0)
		return (get_memory(NULL));
	else
		return (file->addr);
}

t_label	*get_label_addr(t_linelst *file, t_label *lab_tab)
{
	int	count;

	count = 0;
	while (file)
	{
		if (is_label(file->line))
		{
			lab_tab[count].addr = find_addr(file);
			count++;
		}
		file = file->nxt;
	}
	return (lab_tab);
}

int		find_index(char *str, t_label *lab_tab, int label_nb)
{
	int		i;
	int		st;
	int		end;
	char	tmp[LABEL_LENGTH];

	st = 0;
	end = 0;
	ft_bzero(tmp, LABEL_LENGTH);
	while (str[st] && (str[st] == LABEL_CHAR || str[st] == DIRECT_CHAR))
		st++;
	while (str[end] && str[end] != SEPARATOR_CHAR && !ft_iswhitespace(str[end]))
		end++;
	ft_strncpy(tmp, str + st, end - st);
	i = -1;
	while (++i < label_nb)
		if (!ft_strcmp(tmp, lab_tab[i].name))
			return (i);
	return (-1);
}

int		label_name(t_label *lab_tab, char **str, int index)
{
	*str = lab_tab[index].name;
	return (0);
}
