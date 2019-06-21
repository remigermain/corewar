/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_func.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/24 08:38:36 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 14:17:07 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

void	display_vw(t_core *cw)
{
	if (!test_bit(&(cw->utils.flags), CW_DIFF))
		ft_printf("* total cycle = "B_WHITE"%d"RESET
			"   fork = "B_WHITE"%'d"RESET "\n", cw->vm.cycle_total, cw->fork);
	if (test_bit(&(cw->utils.flags), CW_DIFF))
	{
		if (cw->vm.cycle_to_die <= 0 || !cw->total_process)
			ft_printf("Contestant %d, \"%s\", has won !\n",
					-cw->player[cw->last_live].number,
					cw->player[cw->last_live].data.prog_name);
	}
	else if (!cw->total_process || cw->vm.cycle_to_die <= 0)
		ft_printf("Contestant "B_WHITE"%d"RESET", \""B_YELLOW"%s"RESET
			"\" as won !\n\n", cw->player[cw->last_live].number,
			cw->player[cw->last_live].data.prog_name);
	if (test_bit(&(cw->utils.flags), CW_DUMP) &&
			(cw->vm.cycle_total == 0 || cw->total_process))
		print_arena(cw);
}

void	remove_process_verbose(t_core *cw, t_process *p)
{
	if (test_bit(&(cw->utils.flags), CW_V8))
		ft_printf("\tProcess n°"B_WHITE"%d"RESET" has been killed at cycle "
		B_WHITE"%d"RESET"\n\n", p->number, cw->vm.cycle_total);
	else if (test_bit(&(cw->utils.flags), CW_DIFF))
		ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
				p->number, cw->vm.cycle_total - p->live_cycle,
				cw->vm.cycle_to_die);
}

void	cycle_verbose(t_core *cw)
{
	if (test_bit(&(cw->utils.flags), CW_V2))
		ft_printf("\tIt is now cycle "B_WHITE"%d"RESET"\n\n",
															cw->vm.cycle_total);
	else if (test_bit(&(cw->utils.flags), CW_DIFF) && cw->vm.cycle_total)
		ft_printf("It is now cycle %d\n", cw->vm.cycle_total);
}

void	introducing_player_verbose(t_core *cw)
{
	int	i;

	i = -1;
	if (test_bit(&(cw->utils.flags), CW_DIFF))
	{
		ft_printf("Introducing contestants...\n");
		while (++i < cw->nb_player)
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			ft_abs(cw->player[i].number), cw->player[i].data.prog_size,
			cw->player[i].data.prog_name, cw->player[i].data.comment);
		return ;
	}
	ft_printf("\nIntroducing contestants...\n");
	while (++i < cw->nb_player)
		ft_printf("* Player "B_WHITE"%d"RESET", weighting "B_WHITE"%3d"RESET
		" bytes, \""B_YELLOW"%s"RESET"\" (\""B_WHITE"%s"RESET"\")!\n",
		cw->player[i].number, cw->player[i].data.prog_size,
		cw->player[i].data.prog_name, cw->player[i].data.comment);
	ft_printf("\n");
}
