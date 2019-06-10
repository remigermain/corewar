/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_file.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 17:28:50 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 18:20:17 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

static int	is_instruction(char *line)
{
	int	i;

	i = spn_whspaces(line);
	if (ft_strlen(line + i) && line[i] != COMMENT_CHAR)
		return (1);
	return (0);
}

static int	is_name_or_description(char *line)
{
	int	head;

	head = spn_whspaces(line);
	if (ft_strnstr(line + head, NAME_STR, ft_strlen(NAME_STR)))
		return (1);
	if (ft_strnstr(line, COMMENT_STR, ft_strlen(COMMENT_STR)))
		return (1);
	return (0);
}

static void	trim_comments(char *line)
{
	int	i;

	if (!is_name_or_description(line))
		if ((i = ft_strchri(line, COMMENT_CHAR)))
			ft_bzero(line + i, ft_strlen(line) - i);
}

t_linelst	*read_file(int ac, char **av, t_linelst *file, t_file *file_data)
{
	int			i;
	char		*line;
	int			line_nb;
	int			fd;

	line = NULL;
	i = 1;
	fd = input(ac, av, file_data);
	line_nb = 0;
	while ((i = get_next_line(fd, &line)))
	{
		if (i == -1)
			asm_quit(QUIT, NULL);
		line_nb++;
		trim_comments(line);
		if (is_instruction(line))
		{
			if (!(file = add_linelst(file, line, line_nb)))
				asm_quit(QUIT, NULL);
		}
		ft_strdel(&line);
	}
	return (file);
}
