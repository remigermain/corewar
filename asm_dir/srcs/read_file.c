/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_file.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 17:28:50 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 19:44:46 by rcepre      ###    #+. /#+    ###.fr     */
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

static void	check_errors(unsigned char *line, int gnl_ret)
{
	int			i;
	static int	bytes = 0;

	i = -1;
	bytes += ft_strlen((char*)line);
	if (bytes > MAX_FILE_LENGHT)
	{
		put_error(NULL, -1, g_str[E_FILE_TOO_BIG], PE_ERR);
		asm_quit(QUIT, line);
	}
	if (errno)
	{
		put_error(NULL, -1, strerror(errno), PE_ERR);
		asm_quit(QUIT, line);
	}
	if (gnl_ret == -1)
		asm_quit(QUIT | ERROR, line);
	while (line[++i])
		if (line[i] == 255 || (line[i] > 0 && line[i] < 8) || \
												(line[i] > 13 && line[i] < 32))
		{
			put_error(NULL, -1, g_str[E_FILE_CORRUPT], PE_ERR);
			asm_quit(QUIT, line);
		}
}

t_linelst	*read_file(int ac, char **av, t_linelst *file, t_file *file_data)
{
	int			gnl_ret;
	char		*line;
	int			line_nb;
	int			fd;

	line = NULL;
	gnl_ret = 1;
	fd = input(ac, av, file_data);
	line_nb = 0;
	while ((gnl_ret = get_next_line(fd, &line)))
	{
		check_errors((unsigned char *)line, gnl_ret);
		line_nb++;
		trim_comments(line);
		if (is_instruction(line))
		{
			if (!(file = add_linelst(file, line, line_nb)))
				asm_quit(QUIT, line);
		}
		ft_strdel(&line);
	}
	if (!line_nb)
		put_error(NULL, -1, g_str[E_EMPTY_FILE], PE_ERR | PE_EXIT);
	return (file);
}
