/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_labels_check.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/09 11:51:03 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/20 06:05:07 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

static void	check_alone_label_char(t_linelst *file)
{
	int	i;
	int	error;

	i = -1;
	error = 1;
	while (file->line[++i])
	{
		if (file->line[i] == LABEL_CHAR && (i > 0 && file->line[i - 1]) && \
															file->line[i + 1])
		{
			if ((file->line[i - 1] == LABEL_CHAR ||
						ft_iswhitespace(file->line[i - 1])) &&
					(file->line[i + 1] == LABEL_CHAR ||
					ft_iswhitespace(file->line[i + 1])))
			{
				if (error)
					put_error(file, i, g_str[E_UNEXPT_CHAR_LAB], PE_ERR);
				file->line[i] = ' ';
				if (file->line[i + 1] == LABEL_CHAR)
					error = 0;
			}
		}
	}
}

int			label_too_long(int st, int end, t_linelst *file)
{
	if (end - st > LABEL_LENGTH)
	{
		put_error(file, st, g_str[E_LONG_LAB], PE_ERR);
		ft_memset(file->line + st, ' ', end - st + 1);
		return (1);
	}
	return (0);
}

void		check_valid_name(char *label_str, int st, int end, t_linelst *file)
{
	int		i;

	if ((i = ft_strvalids(label_str, LABEL_CHARS)) != -1)
	{
		put_error(file, st + i, g_str[E_CHAR_LAB], PE_ERR);
		ft_memset(file->line + st, ' ', end - st + 1);
	}
}

int			check_and_remove_labels(t_linelst *file)
{
	int		st;
	int		end;
	char	label_str[LABEL_LENGTH];

	while (file)
	{
		check_alone_label_char(file);
		ft_bzero(label_str, LABEL_LENGTH);
		if ((end = ft_strchri(file->line, LABEL_CHAR)))
		{
			while (file->line[end + 1] && file->line[end + 1] == LABEL_CHAR)
				end++;
			if (!file->line[end + 1] || ft_iswhitespace(file->line[end + 1]))
			{
				st = spn_whspaces(file->line);
				if (!label_too_long(st, end, file))
				{
					ft_strncpy(label_str, file->line + st, end - st);
					check_valid_name(label_str, st, end, file);
				}
			}
		}
		file = file->nxt;
	}
	return (0);
}
