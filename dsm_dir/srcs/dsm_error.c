/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dsm_error.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/25 17:25:27 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/17 14:50:49 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "dsm.h"

static void	print_line(t_core *dsm)
{
	int total;
	int error_s;
	int error_e;
	int i;

	i = 0;
	total = 0;
	error_s = 0;
	error_e = 0;
	ft_dprintf(2, "     " RESET);
	while (dsm->argm.argv[i])
	{
		if (i == dsm->argm.i && (error_s = total))
			ft_dprintf(2, B_RED);
		total += ft_dprintf(2, " %s", dsm->argm.argv[i]);
		if (i == dsm->argm.i)
			error_e = total - error_s - 2;
		ft_dprintf(2, RESET);
		i++;
	}
	if (dsm->argm.i == i)
		error_s = total;
	if (error_s)
		ft_dprintf(2, "\n%*c^%*@\n", error_s + 6, ' ', error_e, "char", '~');
}

static void	dsm_error2(enum e_error error, char *str)
{
	if (error == DSM_WRONG_HEADER_SIZE)
		ft_dprintf(2, "Bad header size in file : "RESET"\"%s"B_WHITE"\"\n",
				str);
	else if (error == DSM_WRONG_EXET)
	{
		ft_dprintf(2, "Wrong \""RESET"%s"B_WHITE"\" file ", str);
		ft_dprintf(2, "champions must have a \".cor\" extension\n");
	}
	else if (error == DSM_CMD)
		ft_dprintf(2, "Wrong command \""RESET"%c"B_WHITE"\"\n", (*str));
	else if (error == DSM_MALLOC)
		ft_dprintf(2, "Malloc fail from function \""RESET"%s"B_WHITE"\"\n",\
				str);
	else if (error == DSM_UNK_FLAGS)
		ft_dprintf(2, "Unknow flag.\n");
	else if (error == DSM_NO_FILE)
		ft_dprintf(2, "No file !\n");
	else if (error == DSM_WRONG_INST)
		ft_dprintf(2, "Instruction not valid in file\n");
	else if (error == DSM_UNK_PARAMS)
		ft_dprintf(2, "Unknow params.\n");
}

t_bool		dsm_error(t_core *dsm, enum e_error error, char *str)
{
	if (error != DSM_ERROR)
		ft_dprintf(2, B_RED"error: "RESET);
	if (error == DSM_ERROR)
		ft_dprintf(2, "%d error generated\n", dsm->argm.error);
	if (error == DSM_WRONG_FILE)
		ft_dprintf(2, "wrong file"RESET" \"%s\"\n", str);
	else if (error == DSM_WRONG_FILE_MISSING)
		ft_dprintf(2, "Can't open file, %m.\n");
	else if (error == DSM_WRONG_PROG_SIZE)
		ft_dprintf(2, "Bad program size : "RESET"\"%s\"\n", str);
	else if (error == DSM_WRONG_MAGIC)
		ft_dprintf(2, "Magic number invalid for "RESET"%s"B_WHITE\
				" magic = \""RESET"%p\""B_WHITE"  must be:"RESET"\"%p\"\n",
				str,\
				ft_reverse_uint_bytes(dsm->data.magic),\
				COREWAR_EXEC_MAGIC);
	else
		dsm_error2(error, str);
	if (error != DSM_ERROR && error != DSM_CMD && error != DSM_MALLOC)
		print_line(dsm);
	ft_printf(RESET);
	dsm->argm.error++;
	return (FALSE);
}
