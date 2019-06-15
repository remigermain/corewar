/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_errors.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/15 07:49:21 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 09:56:53 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

void	asm_quit(int todo, void *data)
{
	static t_linelst *list = NULL;

	if (todo & INIT)
		list = (t_linelst*)data;
	if (todo & QUIT)
	{
		if (list)
			delete_linelst(list);
		manage_labels(NULL, NULL, 0, ML_FREE);
		if (todo & ERROR)
			ft_putstr_fd(B_RED "fatal:"B_WHITE" \
					memory allocation failed.\n"RESET, 1);
		exit(0);
	}
}

void	error_resume(void)
{
	int errors;
	int warnings;

	errors = put_error(NULL, -1, NULL, PE_GET_ERRORS);
	warnings = put_error(NULL, -1, NULL, PE_GET_WARNINGS);
	if (errors || warnings)
		ft_printf("\n");
	if (errors)
		ft_printf("%d errors generated.\n", errors);
	if (warnings)
		ft_printf("%d warnings generated.\n", warnings);
}

void	print_error(t_linelst *file, const char *error, int col, int todo)
{
	int i;

	i = -1;
	if (todo & PE_ERR)
		ft_printf(B_WHITE "%d:%d: " B_RED "error: ", file->line_nb, col);
	else if (todo & PE_WARN)
		ft_printf(B_WHITE "%d:%d: " B_PINK "warning: ", file->line_nb, col);
	ft_printf(B_WHITE "%s" RESET, error);
	if (!(todo & PE_NONL))
		ft_printf("\n");
	ft_printf("%s\n", file->line);
	while (++i < col)
	{
		if (file->line[i] == '\t')
			ft_printf("\t");
		else
			ft_printf(" ");
	}
	ft_printf(B_RED "\u2191\n" RESET);
}

int		put_error(t_linelst *file, int col, const char *error, int todo)
{
	static int	count_err = 0;
	static int	count_warn = 0;

	if (todo & PE_GET_ERRORS)
		return (count_err);
	if (todo & PE_GET_WARNINGS)
		return (count_warn);
	count_err += todo & PE_ERR;
	count_warn += todo & PE_WARN;
	if (file && file->line_nb >= 0 && col >= 0)
		print_error(file, error, col, todo);
	else
	{
		if (todo & PE_ERR)
			ft_printf(B_RED "error: " B_WHITE "%s" RESET, error);
		else if (todo & PE_WARN)
			ft_printf(B_PINK "warning: " B_WHITE "%s" RESET, error);
		if (!(todo & PE_NONL))
			ft_printf("\n");
	}
	if (todo & PE_EXIT)
		asm_quit(QUIT, NULL);
	return (0);
}
