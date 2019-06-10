/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   instructions4.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/16 11:56:11 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/06 11:50:39 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "dsm.h"

/*
**-----------------------------------------------------------------------
**		recupere la valeur selon l'encodage de ocp,
**		et l'affiche dans le fichier
**-----------------------------------------------------------------------
*/

static int		get_value(t_core *dsm, t_inst_l *lst, int binary)
{
	int	value;

	value = 0;
	if (binary == REG_CODE)
		return (dsm->file[lst->size++]);
	else if (binary == DIR_CODE)
	{
		value = add_octet(dsm->file, lst->size,
				dsm->tab[lst->op - 1].dir_size);
		if (dsm->tab[lst->op - 1].dir_size == 2)
			value = (short)value;
	}
	else if (binary == IND_CODE)
		value = (short)add_octet(dsm->file, lst->size, 2);
	lst->size += (binary == IND_CODE ? 2 : dsm->tab[lst->op - 1].dir_size);
	return (value);
}

/*
**-----------------------------------------------------------------------
**		check si ocp est correct , et recupere l'information
**		correspondant a l'encodage
**-----------------------------------------------------------------------
*/

t_bool			check_ocp(t_core *dsm, t_inst_l *lst)
{
	int	param_nb;
	int	binary;

	param_nb = 0;
	lst->labels_nb = -1;
	if (dsm->tab[lst->op - 1].octal)
		lst->ocp = dsm->file[lst->size++];
	else
		lst->ocp = (lst->op == CW_AFF) ? (REG_CODE << 6) : (DIR_CODE << 6);
	while (++param_nb <= dsm->tab[lst->op - 1].nb_args)
	{
		binary = (lst->ocp >> binary_shift(param_nb)) & 0x03;
		if (!binary)
			return (FALSE);
		if (!(dsm->tab[lst->op - 1].args[param_nb - 1] & (1 << (binary - 1))))
			return (FALSE);
		else
			lst->value[param_nb - 1] = get_value(dsm, lst, binary);
		if (binary == DIR_CODE && (lst->value[param_nb - 1] <= dsm->inst_limit
				&& lst->value[param_nb - 1] >= -dsm->inst_limit)
				&& lst->value[param_nb - 1] && lst->op != CW_LIVE
				&& lst->labels_nb == -1)
			lst->labels_nb = param_nb - 1;
	}
	return (TRUE);
}
