/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_init_corewar.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 11:16:03 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 17:33:30 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
**		check dump option, you must have a valid number next to dump flag
**-----------------------------------------------------------------------
*/

void	cw_flags_dump(t_core *cw, t_argm *argm)
{
	set_bit(&(cw->utils.flags), CW_DUMP);
	if (argm->argv[++argm->i] &&
			(!ft_strcmp(argm->argv[argm->i], "-c") ||
			!ft_strcmp(argm->argv[argm->i], "--color"))
			&& (argm->i++))
		set_bit(&(cw->utils.flags), CW_DUMP_C);
	if (!argm->argv[argm->i])
		cw_error(cw, argm, CW_WRONG_NO_NUMBER_DUMP, NULL);
	else if (!ft_str_is_digit(argm->argv[argm->i]) ||
		(cw->utils.dump_cycle = ft_atoi(argm->argv[argm->i])) < 0)
		cw_error(cw, argm, CW_WRONG_NUMBER_DUMP, NULL);
	argm->i++;
}

/*
**-----------------------------------------------------------------------
**		check verbose option, you can have number next to verbose flag
**-----------------------------------------------------------------------
*/

void	cw_flags_verbo(t_core *cw, t_argm *argm)
{
	int	mode;

	set_bit(&(cw->utils.flags), CW_VERBO);
	if (argm->argv[++argm->i] && ft_str_is_digit(argm->argv[argm->i]))
	{
		mode = ft_atoi(argm->argv[argm->i]);
		if (mode > 32 || mode < 0)
			cw_error(cw, argm, CW_WRONG_NUMBER_VERBO, NULL);
		else
			cw->utils.flags += ft_atoi(argm->argv[argm->i++]) << 8;
	}
	else if (argm->argv[argm->i] && !cw_isflags(argm->argv[argm->i]))
		cw_error(cw, argm, CW_WRONG_NUMBER_VERBO, NULL);
}

/*
**-----------------------------------------------------------------------
**		check visual option, you can have number next to verbose flag
**-----------------------------------------------------------------------
*/

void	cw_flags_visu(t_core *cw, t_argm *argm)
{
	set_bit(&(cw->utils.flags), CW_VISU);
	if (argm->argv[++argm->i] && ft_str_is_digit(argm->argv[argm->i]))
	{
		if ((cw->utils.speed = ft_atoi(argm->argv[argm->i++])) < 0)
			cw_error(cw, argm, CW_WRONG_NUMBER_VISU, NULL);
	}
}

void	get_screen_size(t_core *cw, t_argm *argm, t_visu *visu)
{
	if (!(argm->argv[++argm->i]) || !(argm->argv[argm->i + 1]))
		cw_error(NULL, argm, CW_ERROR_MISS_SIZE, NULL);
	else if (!ft_str_is_digit(argm->argv[argm->i]))
		cw_error(NULL, argm, CW_ERROR_MISS_SIZE, NULL);
	else if (!ft_str_is_digit(argm->argv[argm->i + 1]))
	{
		argm->i++;
		cw_error(NULL, argm, CW_ERROR_MISS_SIZE, NULL);
	}
	else
	{
		if ((visu->win_w = ft_atoi(argm->argv[argm->i])) < 600)
			cw_error(NULL, argm, CW_ERROR_BAD_SIZE, NULL);
		if ((visu->win_h = ft_atoi(argm->argv[++argm->i])) < 600)
			cw_error(NULL, argm, CW_ERROR_BAD_SIZE, NULL);
		set_bit(&(cw->utils.flags), CW_VISU_SIZE);
		argm->i++;
	}
}
