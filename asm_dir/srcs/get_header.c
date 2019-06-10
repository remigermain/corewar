/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_header.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 06:34:25 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/09 17:43:33 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

int		get_name(t_file *file_data, t_linelst *file, int head, int set_name)
{
	int size;

	if (!set_name)
	{
		head += ft_strlen(NAME_STR);
		head += spn_whspaces(file->line + head);
		if (!file->line[head])
			return (put_error(file, head, ERR_EXP_EXPR, PE_ERR));
		if (file->line[head++] != '"')
			put_error(file, head - 1, ERR_UNEXP_EXPR, PE_ERR);
		if (!ft_strchr(file->line + head, '"'))
			return (put_error(file, head, ERR_MISS_QUOT, PE_ERR));
		size = ft_strchri(file->line + head, '"');
		ft_strncpy(file_data->header.prog_name, file->line + head, size);
		head += size + 1;
		head += spn_whspaces(file->line + head);
		if (file->line[head] && file->line[head] != COMMENT_CHAR)
			put_error(file, head, "unexpected expression", PE_ERR);
		return (1);
	}
	else
		return (put_error(file, head, "name already set", PE_WARN));
}

int		get_comment(t_file *file_data, t_linelst *file, int head, \
														int set_comment)
{
	int size;

	if (!set_comment)
	{
		head += ft_strlen(COMMENT_STR);
		head += spn_whspaces(file->line + head);
		if (!file->line[head])
			return (put_error(file, head, ERR_EXP_EXPR, PE_ERR));
		if (file->line[head++] != '"')
			return (put_error(file, head - 1, ERR_UNEXP_EXPR, PE_ERR));
		if (!ft_strchr(file->line + head, '"'))
			return (put_error(file, head, ERR_MISS_QUOT, PE_ERR));
		size = ft_strchri(file->line + head, '"');
		ft_strncpy(file_data->header.comment, file->line + head, size);
		head += size + 1;
		head += spn_whspaces(file->line + head);
		if (file->line[head] && file->line[head] != COMMENT_CHAR)
			return (put_error(file, head, ERR_UNEXP_EXPR, PE_ERR));
		return (1);
	}
	else
		return (put_error(file, head, "comment already set", PE_WARN));
}

void	check_missing(t_linelst *file, int set_comment, int set_name)
{
	if (!set_comment)
		put_error(file, 12, "missing comment", PE_ERR);
	if (!set_name)
		put_error(file, -1, "missing name", PE_ERR);
}

int		get_header(t_file *file_data, t_linelst *file)
{
	int head;
	int set_name;
	int set_comment;

	set_name = 0;
	set_comment = 0;
	while (file)
	{
		if (!file->opcode)
		{
			head = spn_whspaces(file->line);
			if (ft_strnstr(file->line + head, NAME_STR, ft_strlen(NAME_STR)))
				set_name = get_name(file_data, file, head, set_name);
			if (ft_strnstr(file->line, COMMENT_STR, ft_strlen(COMMENT_STR)))
				set_comment = get_comment(file_data, file, head, set_comment);
		}
		file = file->nxt;
	}
	check_missing(file, set_comment, set_name);
	return (0);
}
