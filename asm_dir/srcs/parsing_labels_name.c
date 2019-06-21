/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_labels_name.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/09 12:06:23 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 19:22:46 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

int		check_existing_label(t_label *lab_tab, int nb, char *tmp)
{
	int i;

	i = -1;
	while (++i < nb)
	{
		if (!ft_strcmp(lab_tab[i].name, tmp))
		{
			put_error(NULL, -1, g_str[E_LAB_SET], PE_WARN | PE_NONL);
			ft_printf(" %s\n", tmp);
			return (1);
		}
	}
	return (0);
}

void	extract_name(char *line, char *tmp)
{
	int i;
	int j;

	i = spn_whspaces(line);
	j = ft_strchri(line + i, LABEL_CHAR);
	ft_strncpy(tmp, line + i, j);
}

int		delete_label(t_linelst *file, char *tmp)
{
	int i;

	i = spn_whspaces(file->line);
	ft_memset(file->line + i, ' ', ft_strlen(tmp) + 1);
	return (1);
}

int		get_label_names(t_linelst *file, t_label *lab_tab)
{
	int		count;
	char	tmp[LABEL_LENGTH];
	int		ret;

	count = 0;
	ret = 0;
	while (file)
	{
		ft_bzero(tmp, LABEL_LENGTH);
		if (is_label(file->line))
		{
			extract_name(file->line, tmp);
			if (!check_existing_label(lab_tab, count, tmp))
			{
				if (ft_strvalids(tmp, LABEL_CHARS) == -1)
					ft_strcpy(lab_tab[count++].name, tmp);
			}
			else
			{
				ret += delete_label(file, tmp);
			}
		}
		file = file->nxt;
	}
	return (ret);
}
