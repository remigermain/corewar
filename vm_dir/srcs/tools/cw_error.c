/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 15:24:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 18:42:48 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
** print error message and show where it is then free struct and exit
**-----------------------------------------------------------------------
*/

static void	print_line(t_argm *argm)
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
	while (argm->argv[i])
	{
		if (i == argm->i && (error_s = total))
			ft_dprintf(2, B_RED);
		total += ft_dprintf(2, " %s", argm->argv[i]);
		if (i == argm->i)
			error_e = total - error_s - 2;
		ft_dprintf(2, RESET);
		i++;
	}
	if (argm->i == i)
		error_s = total;
	if (error_s)
		ft_dprintf(2, "\n%*c^%*@\n", error_s + 6, ' ', error_e, "char", '~');
}

static void	cw_error_3(int error)
{
	if (error == CW_DEF_IDX_MOD)
		ft_dprintf(2, "IDX_MOD = " B_WHITE "\"%d\".\n", IDX_MOD);
	else if (error == CW_DEF_CHAMP)
		ft_dprintf(2, "CHAMP_MAX is over or equal to MEM_SIZE = "\
								B_WHITE"\"%d\".\n", CHAMP_MAX_SIZE);
	else if (error == CW_DEF_RD)
		ft_dprintf(2, "T_REG is equal to T_DIR.\n");
	else if (error == CW_DEF_RI)
		ft_dprintf(2, "T_REG is equal to T_IND.\n");
	else if (error == CW_DEF_ID)
		ft_dprintf(2, "T_IND is equal to T_DIR.\n");
	else if (error == CW_NEED_VISU)
		ft_dprintf(2, "You need to be set --visu (-V) %s.\n");
	else if (error == CW_NEED_VERBO)
		ft_dprintf(2, "You need to be set --verbose (-v) %s.\n");
	else if (error == CW_NEED_DUMP)
		ft_dprintf(2, "You need to be set --dump (-d) %s.\n");
	else
		ft_dprintf(2, "no error.\n\n");
}

static void	cw_error_2(int error)
{
	if (error == CW_DEF_DELTA)
		ft_dprintf(2, "CYCLE_DELTA = " B_WHITE "\"%d\".\n", CYCLE_DELTA);
	else if (error == CW_DEF_NBR_LIVE)
		ft_dprintf(2, "NBR_LIVE = " B_WHITE "\"%d\".\n", NBR_LIVE);
	else if (error == CW_DEF_MAX_CHECKS)
		ft_dprintf(2, "MAX_CHECKS = " B_WHITE "\"%d\".\n", MAX_CHECKS);
	else if (error == CW_DEF_NAME_LENGTH)
		ft_dprintf(2, "PROG_NAME_LENGTH = " B_WHITE "\"%d\".\n",\
							PROG_NAME_LENGTH);
	else if (error == CW_DEF_COMMENT_LENGTH)
		ft_dprintf(2, "COMMENT_LENGTH =" B_WHITE " \"%d\".\n", COMMENT_LENGTH);
	else if (error == CW_DEF_MAX_ARGS_NUM)
		ft_dprintf(2, "MAX_ARGS_NUMBER = " B_WHITE "\"%d\".\n",\
						MAX_ARGS_NUMBER);
	else if (error == CW_DEF_MAX_PLAYERS)
		ft_dprintf(2, "MAX_PLAYER = " B_WHITE "\"%d\".\n", MAX_PLAYERS);
	else if (error == CW_DEF_MAX_ARGS_PLAYERS)
		ft_dprintf(2, "MAX_PLAYERS is over MAX_ARGS_NUMBERS = "\
	B_WHITE"\"%d\"" RESET" >"B_WHITE" \"%d\".\n", MAX_PLAYERS, MAX_ARGS_NUMBER);
	else if (error == CW_DEF_REG_NUM)
		ft_dprintf(2, "REG_NUMBER = " B_WHITE "\"%d\".\n", REG_NUMBER);
	else if (error == CW_DEF_REG_SIZE)
		ft_dprintf(2, "REG_SIZE = " B_WHITE "\"%d\".\n", REG_SIZE);
	else
		cw_error_3(error);
}

static void	cw_error_argv(t_core *cw, int error, char *str)
{
	if (error == CW_NO_PLAYER)
		ft_dprintf(2, "No player.\n");
	else if (error == CW_WRONG_NO_NUMBER_DUMP)
		ft_dprintf(2, "Need a number for dump.\n");
	else if (error == CW_WRONG_NUMBER_DUMP)
		ft_dprintf(2, "Wrong number for dump.\n");
	else if (error == CW_WRONG_NUMBER_VERBO)
		ft_dprintf(2, "Wrong mod for verbose.\n");
	else if (error == CW_WRONG_PROG_SIZE)
		ft_dprintf(2, "Wrong size in program : " B_WHITE "\"%s\""RESET
		" size is %lu, normaly is not over %d and not equal to 0.\n", str,\
		cw->player[cw->nb_player].data.prog_size, CHAMP_MAX_SIZE);
	else if (error == CW_WRONG_NUMBER_VISU)
		ft_dprintf(2, "Wrong number for speed in visu's flags.\n");
	else if (error == CW_WRONG_MAGIC)
		ft_dprintf(2, "Wrong Magic Number for file "B_WHITE"%s"RESET\
				" magic : \""B_WHITE "%p\"" RESET " should be : " B_WHITE\
			"\"%p\".\n", str, cw->player[cw->nb_player].data.magic,
			COREWAR_EXEC_MAGIC);
	else if (error == CW_WRONG_HEADER_SIZE)
		ft_dprintf(2, "Wrong header size in file : " B_WHITE "\"%s\".\n", str);
	else if (error == CW_DEF_CYCLEDIE)
		ft_dprintf(2, "CYCLE_TO_DIE = " B_WHITE "\"%d\".\n", CYCLE_TO_DIE);
	else
		cw_error_2(error);
}

void		cw_error(t_core *cw, t_argm *argm, int error, char *str)
{
	ft_dprintf(2, B_RED "error: " RESET);
	if (error == CW_UNK_FLAG)
		ft_dprintf(2, "Unknow flag " B_WHITE "\"%s\".\n", str);
	else if (error == CW_WRONG_PLAYER)
		ft_dprintf(2, "Wrong player.\n");
	else if (error == CW_WRONG_FILE)
		ft_dprintf(2, "Wrong file" B_WHITE " \"%s\".\n", str);
	else if (error == CW_WRONG_FILE_MISSING)
		ft_dprintf(2, "File not found.\n");
	else if (error == CW_WRONG_NUMBER_PLAYER)
		ft_dprintf(2, "Wrong number player.\n");
	else if (error == CW_TO_MANY_PLAYER)
		ft_dprintf(2, "To many players.\n");
	else if (error == CW_ERROR_MISS_SIZE)
		ft_dprintf(2, "Need a window's size.\n");
	else if (error == CW_ERROR_BAD_SIZE)
		ft_dprintf(2, "Min size : 600 * 600 pixels\
				( 0 * 0  for full screen ).\n");
	else
		cw_error_argv(cw, error, str);
	if (error >= CW_UNK_FLAG && error < CW_NO_PLAYER)
		print_line(argm);
	ft_dprintf(2, RESET);
	argm->error++;
}
