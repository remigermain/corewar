/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_labels_name.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/09 12:06:23 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 22:35:48 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

int		check_existing_label(t_linelst *file, int col, t_label *lab_tab, int nb, char *tmp)
{
	int i;

	i = -1;
	while (++i < nb)
	{
		if (!ft_strcmp(lab_tab[i].name, tmp))
		{
			put_error(file, col, g_str[E_LAB_SET], PE_WARN);
			return (1);
		}
	}
	return (0);
}

int		get_label_names(t_linelst *file, t_label *lab_tab)
{
	int		count;
	int		i;
	int		j;
	char	tmp[LABEL_LENGTH];
	int		ret;

	count = 0;
	ret = 0;
	while (file)
	{
		ft_bzero(tmp, LABEL_LENGTH);
		if (is_label(file->line))
		{
			i = spn_whspaces(file->line);
			j = ft_strchri(file->line + i, LABEL_CHAR);
			ft_strncpy(tmp, file->line + i, j);
			if (!check_existing_label(file, i, lab_tab, count, tmp))
			{
				if (!ft_strvalids(tmp, LABEL_CHARS))
					ft_strncpy(lab_tab[count].name, file->line + i, j);
				count++;
			}
			else 
				ret++;
		}
		file = file->nxt;
	}
	return (ret);
}
