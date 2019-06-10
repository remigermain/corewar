/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 14:36:08 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/09 12:48:10 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
**		teste si le "bit_nb" de "bit" est a 1
**		si c'est le cas elle retourne TRUE sinon FALSE
**-----------------------------------------------------------------------
*/

t_bool	test_bit(int *bit, int bit_nb)
{
	return (!(*bit & (1 << bit_nb)) ? FALSE : TRUE);
}

/*
**-----------------------------------------------------------------------
**		met le "bit_nb" de "bit" a 1
**-----------------------------------------------------------------------
*/

void	set_bit(int *bit, int bit_nb)
{
	*bit |= (1 << bit_nb);
}

/*
**-----------------------------------------------------------------------
**		met le "bit_nb" de "bit" a 0
**-----------------------------------------------------------------------
*/

void	clear_bit(int *bit, int bit_nb)
{
	if (test_bit(bit, bit_nb))
		*bit ^= (1 << bit_nb);
}

/*
**-----------------------------------------------------------------------
**		retourne le le nombre de combien on doit ce decale pour obtenir
**		le "param" paramettres
**		exemple : T_REG   T_DIR   T_DIR     NULL
**				   01      10     10        00
**
**		pour obtenir le T_REG paramatre , donc le 1 paramettre
**		je devrais me decale de 6   "  01101000 >> 6   = 00000001"
**-----------------------------------------------------------------------
*/

int		binary_shift(int param)
{
	if (param == 1)
		return (6);
	else if (param == 2)
		return (4);
	else if (param == 3)
		return (2);
	return (0);
}

/*
**-----------------------------------------------------------------------
**		ajout les "mod" octets de "str[i]" et retourne la valeur
**-----------------------------------------------------------------------
*/

int		add_bytes(unsigned char *str, int i, int mod)
{
	int	bin;
	int	nb;
	int j;

	nb = 0;
	j = -1;
	bin = (mod * 8) - 8;
	while (++j < mod)
	{
		nb += (str[i_pc(i + j)] << bin);
		bin -= 8;
	}
	return (nb);
}
