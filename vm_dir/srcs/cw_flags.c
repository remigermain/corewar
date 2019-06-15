/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_init_corewar.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 11:16:03 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/13 02:00:57 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

t_bool			cw_isflags(char *str)
{
	if (!str)
		return (TRUE);
	if (ft_strcmp(str, "-p") && ft_strcmp(str, "--player") &&
			ft_strcmp(str, "-v") && ft_strcmp(str, "--verbose") &&
			ft_strcmp(str, "-V") && ft_strcmp(str, "--visu") &&
			ft_strcmp(str, "-d") && ft_strcmp(str, "--dump") &&
			ft_strcmp(str, "-n") && ft_strcmp(str, "--number") &&
			ft_strcmp(str, "-c") && ft_strcmp(str, "--color") &&
			ft_strcmp(str, "-s") && ft_strcmp(str, "--step") &&
			ft_strcmp(str, "-a") && ft_strcmp(str, "--animation") &&
			ft_strcmp(str, "-f") && ft_strcmp(str, "--aff") &&
			ft_strcmp(str, "--diff"))
		return (FALSE);
	return (TRUE);
}

t_bool			cw_is_champ(char *str)
{
	int len;

	len = ft_strlen(str);
	if (len < 4)
		return (FALSE);
	else if (ft_strcmp(".cor", str + len - 4))
		return (FALSE);
	else
		return (TRUE);
}

static void		cw_check_finalflags(t_core *cw, t_argm *argm)
{
	if (!test_bit(&(cw->utils.flags), CW_VISU))
	{
		if (test_bit(&(cw->utils.flags), CW_VISU_AN))
			cw_error(cw, argm, CW_NEED_VISU, "for --animation (-a) flags");
	}
	if (!test_bit(&(cw->utils.flags), CW_VERBO) &&
			test_bit(&(cw->utils.flags), CW_VERBO_S))
		cw_error(cw, argm, CW_NEED_VERBO, "for --step (-s) flags");
	if (test_bit(&(cw->utils.flags), CW_VERBO))
	{
		if (!((cw->utils.flags >> CW_V0) & V_MO))
			set_bit(&(cw->utils.flags), CW_V1);
	}
	if (!test_bit(&(cw->utils.flags), CW_DUMP) &&
			test_bit(&(cw->utils.flags), CW_DUMP_C))
		cw_error(cw, argm, CW_NEED_DUMP, "for --color (-c) flags");
}

static t_bool	cw_flags2(t_core *cw, t_argm *argm)
{
	if ((!ft_strcmp(argm->argv[argm->i], "-c") ||
			!ft_strcmp(argm->argv[argm->i], "--color")) && (argm->i++))
		set_bit(&(cw->utils.flags), CW_DUMP_C);
	else if ((!ft_strcmp(argm->argv[argm->i], "-s") ||
			!ft_strcmp(argm->argv[argm->i], "--step")) && (argm->i++))
		set_bit(&(cw->utils.flags), CW_VERBO_S);
	else if ((!ft_strcmp(argm->argv[argm->i], "-a") ||
			!ft_strcmp(argm->argv[argm->i], "--animation")) && (argm->i++))
		set_bit(&(cw->utils.flags), CW_VISU_AN);
	else if ((!ft_strcmp(argm->argv[argm->i], "-f") ||
			!ft_strcmp(argm->argv[argm->i], "--aff")) && (argm->i++))
		set_bit(&(cw->utils.flags), CW_F_AFF);
	else if ((!ft_strcmp(argm->argv[argm->i], "-p") ||
				!ft_strcmp(argm->argv[argm->i], "--player")) && (argm->i++))
		put_player(cw, argm);
	else if (!ft_strcmp(argm->argv[argm->i], "-n") ||
				!ft_strcmp(argm->argv[argm->i], "--number") ||
				(argm->argv[argm->i] && cw_is_champ(argm->argv[argm->i])))
		put_player(cw, argm);
	else if (!ft_strcmp(argm->argv[argm->i], "--diff") && (argm->i++))
		set_bit(&(cw->utils.flags), CW_DIFF);
	else
		return (FALSE);
	return (TRUE);
}

void			cw_flags(t_core *cw, t_argm *argm)
{
	argm->i = 1;
	while (argm->argv[argm->i] && argm->i < argm->argc)
	{
		if (!ft_strcmp(argm->argv[argm->i], "-V") ||
				!ft_strcmp(argm->argv[argm->i], "--visu"))
			cw_flags_visu(cw, argm);
		else if (!ft_strcmp(argm->argv[argm->i], "-v") ||
				!ft_strcmp(argm->argv[argm->i], "--verbose"))
			cw_flags_verbo(cw, argm);
		else if (!ft_strcmp(argm->argv[argm->i], "-d") ||
				!ft_strcmp(argm->argv[argm->i], "--dump"))
			cw_flags_dump(cw, argm);
		else if (!cw_flags2(cw, argm))
		{
			if (argm->argv[argm->i] && argm->argv[argm->i][0] == '-')
				cw_error(cw, argm, CW_UNK_FLAG, argm->argv[argm->i]);
			else
				cw_error(cw, argm, CW_WTF, argm->argv[argm->i]);
			argm->i++;
		}
	}
	if (!cw->nb_player)
		cw_error(cw, argm, CW_NO_PLAYER, NULL);
	cw_check_finalflags(cw, argm);
}
