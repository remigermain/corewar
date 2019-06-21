/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_header.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 06:34:25 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 14:53:11 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

int		get_name(t_file *file_data, t_linelst *file, int head)
{
	int size;

	if (!ft_strlen(file_data->header.prog_name))
	{
		ft_bzero(file_data->header.prog_name, PROG_NAME_LENGTH);
		head += ft_strlen(NAME_STR);
		head += spn_whspaces(file->line + head);
		if (!file->line[head])
			return (put_error(file, head, g_str[E_EXP_EXPR], PE_ERR));
		if (file->line[head++] != '"')
			return (put_error(file, head - 1, g_str[E_UNEXP_EXPR], PE_ERR));
		if (!ft_strchr(file->line + head, '"'))
			return (put_error(file, head, g_str[E_MISS_TERM_NAM], PE_ERR));
		size = ft_strchri(file->line + head, '"');
		if (size > PROG_NAME_LENGTH)
			return (put_error(file, head, g_str[E_NAME_TOO_LONG], PE_ERR));
		ft_strncpy(file_data->header.prog_name, file->line + head, size);
		head += size + 1;
		head += spn_whspaces(file->line + head);
		if (file->line[head] && file->line[head] != COMMENT_CHAR)
			put_error(file, head, g_str[E_UNEXP_EXPR], PE_ERR);
	}
	else
		put_error(file, head, g_str[E_NAME_SET], PE_WARN);
	return (0);
}

int		get_comment(t_file *file_data, t_linelst *file, int head)
{
	int size;

	if (!ft_strlen(file_data->header.comment))
	{
		ft_bzero(file_data->header.comment, COMMENT_LENGTH);
		head += ft_strlen(COMMENT_STR);
		head += spn_whspaces(file->line + head);
		if (!file->line[head])
			return (put_error(file, head, g_str[E_EXP_EXPR], PE_ERR));
		if (file->line[head++] != '"')
			return (put_error(file, head - 1, g_str[E_UNEXP_EXPR], PE_ERR));
		if (!ft_strchr(file->line + head, '"'))
			return (put_error(file, head, g_str[E_MISS_TERM_COM], PE_ERR));
		size = ft_strchri(file->line + head, '"');
		if (size > COMMENT_LENGTH)
			return (put_error(file, head, g_str[E_COM_TOO_LONG], PE_ERR));
		ft_strncpy(file_data->header.comment, file->line + head, size);
		head += size + 1;
		head += spn_whspaces(file->line + head);
		if (file->line[head] && file->line[head] != COMMENT_CHAR)
			return (put_error(file, head, g_str[E_UNEXP_EXPR], PE_ERR));
	}
	else
		put_error(file, head, g_str[E_COMMENT_SET], PE_WARN);
	return (0);
}

void	check_missing(t_file *file_data, t_linelst *file)
{
	if (!ft_strlen(file_data->header.comment))
		put_error(file, 12, g_str[E_MISS_COMMENT], PE_WARN);
	if (!ft_strlen(file_data->header.prog_name))
		put_error(file, -1, g_str[E_MISS_NAME], PE_WARN);
}

int		get_header(t_file *file_data, t_linelst *file)
{
	int head;

	while (file)
	{
		head = spn_whspaces(file->line);
		if (ft_strnstr(file->line + head, NAME_STR, ft_strlen(NAME_STR)))
			get_name(file_data, file, head);
		else if (ft_strnstr(file->line + head, COMMENT_STR,\
														ft_strlen(COMMENT_STR)))
			get_comment(file_data, file, head);
		else if (file->line[head] == '.')
		{
			put_error(file, head, g_str[E_DOT_CHAR], PE_ERR);
			ft_bzero(file->line, ft_strlen(file->line));
		}
		file = file->nxt;
	}
	check_missing(file_data, file);
	return (0);
}
