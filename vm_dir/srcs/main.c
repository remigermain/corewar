/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 16:15:00 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/16 20:00:49 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static void	print_usage(void)
{
	ft_printf("usage : ./corewar [ -flags ] -p [ -n <number> ] <champion.cor>\n"
" [ flags ]\n"
"  	--visu	 (-V)			:  Visual made in SDL2.\n"
"\n"
"	[ visu flags ]\n"
"	--screen			:  Change screen resolution (1080 or 4k).\n"
"	--animation (-a)	:  Print annimation in start and end ( default is off ).\n"
"	--dump	 (-d)   <Number>	:  Dumps memory after <Number> cyles and exits.\n"
"	--color	 (-c)			:  Dumps with color player.\n"
"	--diff				:  Print verbose same as zaz's VM.\n"
"  	--verbose (-v)   <Number>	:  Print information , <Number> for verbose mode ( Default is 1 ).\n"
"		verbose mode :\n"
"				1 : print base\n"
"				2 : Print cycle_to_die\n"
"				4 : Print instruction\n"
"				8 : Print Kill process\n"
"				16 : Print pc mouvement\n"
"\n"
"	--step	(-s)			:  Verbose step by step. ( default if off ).\n"
"	--aff	(-f)			:  print aff result in stdin ( in verbose is same as mode 4 ).\n"
"\n"
" [ champion ]\n"
"	--player (-p)   <Number>	:  Set champion, <Number> for set number to player.\n"
"			(Default is UNSIGNED INT MAX less the numbers of player)\n"
"\n"
" [ visu events ]\n"
"	m   : turn ON/OFF music (when turn ON speed is limited to 1).\n"
"	+/- : inscrease/decrease speed.\n"
"	r   : switch to responsive mode.\n"
"	p   : change background ( only with fullscreen mode ).\n"
"	s   : step mode.\n"
"	esc : quit sdl.\n"
"Corewar © 2019 le-101 Loiberti - Rcepre - Rgermain\n");
}

static void	cw_usage(int argc, char **argv)
{
	int		i;

	i = -1;
	while (++i < argc)
		if (!ft_strcmp(argv[i], "--help") || !ft_strcmp(argv[i], "-h"))
			break ;
	if (i == argc && i != 1)
		return ;
	print_usage();
	exit(0);
}

static void	cw_initstruct(t_core *cw, t_argm *argm, int argc, char **argv)
{
	ft_bzero(cw, sizeof(t_core));
	cw->vm.cycle_to_die = CYCLE_TO_DIE;
	cw->tab = get_op_tab();
	cw->last_live = -1;
	ft_bzero(argm, sizeof(t_argm));
	argm->argc = argc;
	argm->argv = argv;
}

static void	init_visu_strcut(t_core *cw, t_visu *visu)
{
	ft_bzero(visu, sizeof(t_visu));
	visu->win_h = -1;
	visu->win_w = -1;
	visu->speed = -1;
	visu->pause = test_bit(&(cw->utils.flags), CW_VISU);
	visu->refresh = 1;
	if (cw->utils.screen) {
		if (!ft_strcmp(cw->utils.screen, "1080")) {
			visu->screen.coef = 3;
			visu->screen.base = IMG_COMMODORE_1080_BASE;
			visu->screen.light = IMG_COMMODORE_1080_LIGHT;
			visu->screen.graph = IMG_COMMODORE_1080_GRAPH;
		} else {
			visu->screen.coef = 4;
			visu->screen.base = IMG_COMMODORE_4k_BASE;
			visu->screen.light = IMG_COMMODORE_4k_LIGHT;
			visu->screen.graph = IMG_COMMODORE_4k_GRAPH;
		}
	}
}

int			main(int argc, char **argv)
{
	t_visu	visu;
	t_argm	argm;
	t_core	cw;

	cw_usage(argc, argv);
	cw_initstruct(&cw, &argm, argc, argv);
	cw_check_define(&argm);
	cw_flags(&cw, &argm);
	init_visu_strcut(&cw, &visu);
	if (!argm.error)
	{
		cw.last_live = cw.nb_player - 1;
		cw_initplayer(&cw);
		cw_vm(&cw, visu);
	}
	else
		ft_dprintf(2, "%d error generated.\n", argm.error);
	return (0);
}
