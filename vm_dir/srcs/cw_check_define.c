/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_define.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 11:17:55 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/09 17:23:25 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
**	check op.h defines
**-----------------------------------------------------------------------
*/

static void	check_define2(t_argm *argm)
{
	if (REG_NUMBER < 1)
		cw_error(NULL, argm, CW_DEF_REG_NUM, NULL);
	else if (REG_SIZE < 1)
		cw_error(NULL, argm, CW_DEF_REG_SIZE, NULL);
	else if (IDX_MOD >= MEM_SIZE)
		cw_error(NULL, argm, CW_DEF_IDX_MOD, NULL);
	else if ((CHAMP_MAX_SIZE * MAX_PLAYERS) >= MEM_SIZE)
		cw_error(NULL, argm, CW_DEF_CHAMP, NULL);
	else if (REG_CODE == DIR_CODE)
		cw_error(NULL, argm, CW_DEF_RD, NULL);
	else if (REG_CODE == IND_CODE)
		cw_error(NULL, argm, CW_DEF_RI, NULL);
	else if (IND_CODE == DIR_CODE)
		cw_error(NULL, argm, CW_DEF_ID, NULL);
}

void		cw_check_define(t_argm *argm)
{
	if (CYCLE_TO_DIE <= 0)
		cw_error(NULL, argm, CW_DEF_CYCLEDIE, NULL);
	else if (CYCLE_DELTA <= 0)
		cw_error(NULL, argm, CW_DEF_DELTA, NULL);
	else if (NBR_LIVE <= 0)
		cw_error(NULL, argm, CW_DEF_NBR_LIVE, NULL);
	else if (MAX_CHECKS <= 0)
		cw_error(NULL, argm, CW_DEF_MAX_CHECKS, NULL);
	else if (PROG_NAME_LENGTH <= 0)
		cw_error(NULL, argm, CW_DEF_NAME_LENGTH, NULL);
	else if (COMMENT_LENGTH <= 0)
		cw_error(NULL, argm, CW_DEF_COMMENT_LENGTH, NULL);
	else if (MAX_ARGS_NUMBER <= 0)
		cw_error(NULL, argm, CW_DEF_MAX_ARGS_NUM, NULL);
	else if (MAX_PLAYERS <= 0)
		cw_error(NULL, argm, CW_DEF_MAX_PLAYERS, NULL);
	else if (MAX_ARGS_NUMBER < MAX_PLAYERS)
		cw_error(NULL, argm, CW_DEF_MAX_ARGS_PLAYERS, NULL);
	else
		check_define2(argm);
}
