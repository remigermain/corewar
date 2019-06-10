/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_labels_name.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/09 12:06:23 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 17:26:20 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

t_label	*get_label_names(t_linelst *file, t_label *lab_tab)
{
	int		count;
	int		i;
	int		j;
	char	tmp[LABEL_LENGTH];

	ft_bzero(tmp, LABEL_LENGTH);
	count = 0;
	while (file)
	{
		if (is_label(file->line))
		{
			i = spn_whspaces(file->line);
			j = ft_strchri(file->line + i, LABEL_CHAR);
			ft_strncpy(tmp, file->line + i, j);
			if (!ft_strvalids(tmp, LABEL_CHARS))
				ft_strncpy(lab_tab[count].name, file->line + i, j);
			count++;
		}
		file = file->nxt;
	}
	return (lab_tab);
}
