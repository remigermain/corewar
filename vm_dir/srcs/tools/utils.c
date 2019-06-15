/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 15:07:13 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/13 02:39:36 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
** display arena on the standard output
**-----------------------------------------------------------------------
*/

static void	print_dumpcolor(t_core *cw, int i, int j)
{
	if (cw->vm.color[i * 64 + j] == 1)
		ft_printf(BLUE);
	else if (cw->vm.color[i * 64 + j] == 2)
		ft_printf(YELLOW);
	else if (cw->vm.color[i * 64 + j] == 3)
		ft_printf(PINK);
	else if (cw->vm.color[i * 64 + j] == 4)
		ft_printf(RED);
	else
		ft_printf(BLACK);
}

void		print_arena(t_core *cw)
{
	int i;
	int j;

	i = -1;
	while (++i < 64)
	{
		j = -1;
		ft_printf("0x%.4x : ", (i * 64));
		while (++j < 64)
		{
			if (test_bit((&cw->utils.flags), CW_DUMP_C))
				print_dumpcolor(cw, i, j);
			ft_printf("%.2x ", cw->vm.arena[(i * 64) + j]);
		}
		if (test_bit((&cw->utils.flags), CW_DUMP_C))
			ft_printf(RESET);
		ft_printf("\n");
	}
}

/*
**-----------------------------------------------------------------------
** return player index
**-----------------------------------------------------------------------
*/

int			find_player(t_core *cw, int i)
{
	int j;

	j = -1;
	while (++j < cw->nb_player)
	{
		if (cw->player[j].number == i)
			return (j);
	}
	return (-1);
}

int			registre_player(t_core *cw, t_process *origi)
{
	int	j;
	int	i;

	j = -1;
	i = 0;
	while (++j < 4)
		i += ((origi->reg[0][j] << (j * 8)) >> 24);
	return (find_player(cw, i));
}

/*
**-----------------------------------------------------------------------
**	free last processs
**-----------------------------------------------------------------------
*/

void		cw_free(t_core *cw)
{
	if (cw->process)
		ft_memdel((void**)&cw->process);
}
