/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_ins_arguments_value.c                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 06:49:19 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 10:03:21 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

static int	get_arg_type(char *line, int head)
{
	if (ft_isdigit(line[head]) || line[head] == '-')
		return (IND_CODE);
	if (line[head] == DIRECT_CHAR)
		return (DIR_CODE);
	if (line[head] == 'r')
		return (REG_CODE);
	return (0);
}

static int	value_from_str(t_linelst *file, char *str, int arg_type, int head)
{
	long	value;

	if (str[0] == LABEL_CHAR)
		return (0);
	if ((ft_strtoi(str, &value) == -1))
		put_error(file, head, g_str[E_INV_FORM], PE_ERR);
	else
		check_maxs(file, head, arg_type, value);
	return (value);
}

static int	sub_str_arg_value(char **str, t_linelst *file, int head)
{
	int		size;
	int		i;
	char	*tmp;

	size = 0;
	tmp = file->line + head;
	while (tmp[size] && tmp[size] != SEPARATOR_CHAR && tmp[size] != '\n'       \
												&& !ft_iswhitespace(tmp[size]))
	{
		size++;
	}
	i = size + spn_whspaces(tmp + size);
	if (!(*str = ft_strsub(tmp, 0, size)))
		asm_quit(QUIT);
	else if (!**str)
		put_error(file, head, g_str[E_MISS_VAL], PE_ERR);
	else if (tmp[i] && tmp[i] != SEPARATOR_CHAR)
		put_error(file, head + i, g_str[E_UNEXP_EXPR], PE_ERR);
	return (0);
}

int			get_label_value(t_linelst *file, int head, int param)
{
	char *tmp;

	if (file->line[head] == LABEL_CHAR || file->line[head + 1] == LABEL_CHAR)
	{
		tmp = file->line + head + 1;
		if ((file->param[param - 1] = manage_labels(file, &tmp, 0,
														ML_GET_INDEX)) == -1)
		{
			put_error(file, head, g_str[E_UNDECL_LAB], PE_ERR);
		}
		file->labels += 1 << (param - 1);
		if (file->line[head] == LABEL_CHAR)
			return (1);
	}
	return (0);
}

int			get_arguments_value(t_linelst *file, int head, int param)
{
	long	value;
	char	*str;
	int		arg_type;

	value = 0;
	if (get_label_value(file, head, param))
		return (IND_CODE);
	if ((arg_type = get_arg_type(file->line, head)))
	{
		sub_str_arg_value(&str, file, head +
				(arg_type == REG_CODE || arg_type == DIR_CODE));
		if (*str == '-' && !ft_isdigit(str[1]))
			put_error(file, head + 1, g_str[E_INV_FORM], PE_ERR);
		else if (file->param[param - 1] == 0)
		{
			value = value_from_str(file, str, arg_type, head);
			file->param[param - 1] = value;
		}
		free(str);
		return (arg_type);
	}
	else
		return (0);
}
