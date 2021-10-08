/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 15:24:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/17 13:56:45 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static void	cw_error_4(enum e_error error, char *str)
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
		ft_dprintf(2, "You need to be set --visu (-V) %s.\n", str);
	else if (error == CW_NEED_VERBO)
		ft_dprintf(2, "You need to be set --verbose (-v) %s.\n", str);
	else if (error == CW_NEED_DUMP)
		ft_dprintf(2, "You need to be set --dump (-d) %s.\n", str);
	else if (error == CW_NUM_H)
		ft_dprintf(2, "The number can't be greater than INT_MAX \"%zd\".\n",
				FT_INT_MAX);
	else if (error == CW_NUM_L)
		ft_dprintf(2, "The number can't be less than "\
				"\"0\".\n", FT_INT_MIN);
	else if (error == CW_VISU_SCREEN)
		ft_dprintf(2, "The value need to be 1080 or 4k\n");
	else
		ft_dprintf(2, "no error.\n\n");
}

static void	cw_error_3(enum e_error error, char *str)
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
		cw_error_4(error, str);
}

static void	cw_error_2(t_core *cw, enum e_error error, char *str)
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
		ft_dprintf(2, "Wrong size in program : " B_WHITE "\"%s\""RESET\
			" size is %lu, normaly is not over %d.\n", str,\
		cw->player[cw->nb_player].data.prog_size, CHAMP_MAX_SIZE);
	else if (error == CW_WRONG_NUMBER_VISU)
		ft_dprintf(2, "Wrong number for speed in visu's flags.\n");
	else if (error == CW_WRONG_MAGIC)
		ft_dprintf(2, "Wrong Magic Number for file "B_WHITE"%s"RESET\
				" magic : \""B_WHITE "%p\"" RESET " should be : " B_WHITE\
			"\"%p\".\n", str, cw->player[cw->nb_player].data.magic,
			COREWAR_EXEC_MAGIC);
	else if (error == CW_WRONG_HEADER_SIZE)
		ft_dprintf(2, "Wrong header size.\n");
	else if (error == CW_DEF_CYCLEDIE)
		ft_dprintf(2, "CYCLE_TO_DIE = " B_WHITE "\"%d\".\n", CYCLE_TO_DIE);
	else
		cw_error_3(error, str);
}

static void	cw_error_1(t_core *cw, enum e_error error, char *str)
{
	if (error == CW_WRONG_NUMBER_PLAYER)
		ft_dprintf(2, "Wrong number player.\n");
	else if (error == CW_TO_MANY_PLAYER)
		ft_dprintf(2, "To many players.\n");
	else if (error == CW_CHAMP_SIZE)
		ft_dprintf(2, "Prog Size \"%d\" is over CHAMP_MAX_SIZE \"%d\".\n",
				cw->player[cw->nb_player].data.prog_size, CHAMP_MAX_SIZE);
	else if (error == CW_PROG_SIZE)
		ft_dprintf(2, "The size of program is different from the one set"
			" in header \"%d\" not equal \"%d\".\n",
				cw->player[cw->nb_player].data.prog_size, CHAMP_MAX_SIZE);
	else
		cw_error_2(cw, error, str);
}

void		cw_error(t_core *cw, t_argm *argm, enum e_error error, char *str)
{
	ft_dprintf(2, B_RED "error: " RESET);
	if (error == CW_UNK_FLAG)
		ft_dprintf(2, "Unknow flags.\n");
	else if (error == CW_WTF)
		ft_dprintf(2, "Unknow params.\n");
	else if (error == CW_WRONG_PLAYER)
		ft_dprintf(2, "Wrong player.\n");
	else if (error == CW_OPEN)
		ft_dprintf(2, "Can't open file %m.\n", str);
	else if (error == CW_FILE_COR)
		ft_dprintf(2, "File have not good extension ( .cor ).\n", str);
	else if (error == CW_WRONG_FILE)
		ft_dprintf(2, "Wrong file" B_WHITE " \"%s\".\n", str);
	else if (error == CW_WRONG_FILE_MISSING)
		ft_dprintf(2, "File not found.\n");
	else
		cw_error_1(cw, error, str);
	if ((error >= CW_UNK_FLAG && error < CW_NO_PLAYER)
			|| error >= CW_NUM_H)
		cw_error_argv(argm);
	ft_dprintf(2, RESET);
	argm->error++;
}
