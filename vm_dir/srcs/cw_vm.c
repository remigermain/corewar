/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_vm.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/08 10:35:00 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 16:54:57 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
** remove death process when cycle reach cycle to_to_die and decrease
** cycle_to_die of delta if total_live >= nbr_live ou check >= max_checks
**-----------------------------------------------------------------------
*/

static void		vm_check(t_core *cw)
{
	static int	check = 1;

	remove_process(cw);
	if (cw->total_live >= NBR_LIVE || check >= MAX_CHECKS)
	{
		check = 0;
		cw->vm.cycle_to_die -= CYCLE_DELTA;
		if (test_bit(&(cw->utils.flags), CW_V2))
			ft_printf("\t\tCycle to die is now "B_WHITE"%d"RESET"\n\n",
														cw->vm.cycle_to_die);
		else if (test_bit(&(cw->utils.flags), CW_DIFF))
			ft_printf("Cycle to die is now %d\n", cw->vm.cycle_to_die);
	}
	check++;
	cw->total_live = 0;
}

/*
**-----------------------------------------------------------------------
** check visual state and display memory/players update
**-----------------------------------------------------------------------
*/

static void		visu_vm(t_core *cw, t_visu *visu, int cycle)
{
	if (test_bit(&(cw->utils.flags), CW_VISU))
	{
		if ((visu->speed > 0 && visu->test == ft_abs(visu->speed)) ||
			visu->speed <= 0 || (visu->event.type == SDL_KEYDOWN &&
			visu->event.key.keysym.sym == SDLK_s))
		{
			clear_screen(visu);
			put_background(visu);
			put_info_gl(visu, cw, cycle);
			put_info_players(visu, cw);
			put_bytes(visu, cw);
			handle_time(visu);
			SDL_RenderPresent(visu->ren);
		}
		++visu->test;
		visu->test = (visu->test >= ft_abs(visu->speed) + 1) ? 0 : visu->test;
	}
}

/*
**-----------------------------------------------------------------------
** if visual mode is on, display final animation
**-----------------------------------------------------------------------
*/

static void		end_vm(t_core *cw, t_visu *visu)
{
	display_vw(cw);
	if (test_bit(&(cw->utils.flags), CW_VISU))
	{
		sdl_outro(cw, visu, 0);
		sdl_outro(cw, visu, 1);
		cw->visu->sound = 1;
		cw->visu->speed = 1;
		while (42)
		{
			handle_events(visu, cw);
			clear_screen(visu);
			put_background(visu);
			put_info_gl_end(visu, cw);
			if (test_bit(&(cw->utils.flags), CW_VISU_AN))
				display_outro(visu);
			else
				put_bytes(visu, cw);
			SDL_RenderPresent(visu->ren);
		}
		quit_sdl(visu, cw);
	}
	cw_free(cw);
}

/*
**-----------------------------------------------------------------------
** if visual mod is set check if programm isn't on break and if
** dump flag is set covered process for incrementing cycle and nb_cycle
**-----------------------------------------------------------------------
*/

static void		do_vm(t_core *cw, t_visu *visu, int *cycle, int *nb_cycle)
{
	if (test_bit(&(cw->utils.flags), CW_VISU))
	{
		visu->t1 = SDL_GetTicks();
		handle_events(visu, cw);
	}
	if (!test_bit(&(cw->utils.flags), CW_VISU) || (((visu->speed < 0 &&
		visu->test == ft_abs(visu->speed)) || visu->speed > 0) && (!visu->pause
		|| (visu->event.type == SDL_KEYDOWN &&
			visu->event.key.keysym.sym == SDLK_s))))
	{
		cycle_verbose(cw);
		covered_process(cw);
		if (*cycle > cw->vm.cycle_to_die)
		{
			vm_check(cw);
			(*cycle) = 1;
		}
		(*cycle)++;
		if (test_bit(&(cw->utils.flags), CW_DUMP))
			(*nb_cycle)++;
		cw->vm.cycle_total++;
	}
}

/*
**-----------------------------------------------------------------------
** launch VM
** loop x time until cycle < cycle_to_die or there are not alive process
**-----------------------------------------------------------------------
*/

void			cw_vm(t_core *cw, t_visu visu)
{
	int	nb_cycle;
	int	cycle;

	nb_cycle = -1;
	cw->vm.cycle_total = 0;
	cycle = 1;
	cw->visu = &visu;
	introducing_player_verbose(cw);
	sdl_intro(cw, &visu);
	while (cw->total_process &&
			nb_cycle < cw->utils.dump_cycle)
	{
		do_vm(cw, &visu, &cycle, &nb_cycle);
		visu_vm(cw, &visu, cycle);
	}
	end_vm(cw, &visu);
}
