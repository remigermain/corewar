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
	ft_printf("usage : ./corewar [ -flags ] -p [ -n <number> ] <champion.cor>"\
"\n\n [ flags ]\n  	--visu\t (-V)\t\t\t:  Visual made in SDL2.\n"
"\n	[ visu flags ]\n\t\t--animation (-a)	: "\
" Print annimation in start and end ( default is off )."\
"\n\t--dump\t (-d)   <Numbe"\
"r>	:  Dumps memory after <Number> cyles and exits.\n	--color\t (-c)		"\
"\t:  Dumps with color player.\n\t--diff\t\t\t\t:  Print verbose same as "\
"zaz's VM.\n  	--verbose (-v)   <Number>	:  Print inf"\
"ormation , <Number> for verbose mode ( Default is 1 ).\n		verbose mode "\
":\n\t\t\t\t1 : print base\n\t\t\t\t2 : Print cycle_to_die\n\t\t\t\t4 : Prin"\
"t instruction \n\t\t\t\t8 : Print Kill process\n\t\t\t\t16 : Print pc mouve"\
"ment\n\n\t--step\t(-s)		\t:  Verbose step by step. ( d"\
"efault if off ).\n	--aff\t(-f)		\t:  print aff result in stdin ( in verbos"\
"e is same as mode 4 ).\n\n [ champion ]\n\t--player (-p)   <Number"\
">	:  Set champion, <Number> for set number to player.\n\t\t\t(Default is UN"\
"SIGNED INT MAX less the numbers of player)\n\n [ visu events ]\n\tm   : "\
"turn ON/OFF music (when turn ON speed is limited to 1).\n\t+/- : inscrease/"\
"decrease speed.\n\tr   : switch to responsive mode.\n\tp   : change backgrou"\
"nd ( only with fullscreen mode ).\n\tesc : quit sdl.\n\nCorewar © 2019 le-10"\
"1 Loiberti - Rcepre - Rgermain\n");
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

static void	init_visu_strcut(t_visu *visu)
{
	ft_bzero(visu, sizeof(t_visu));
	visu->win_h = -1;
	visu->win_w = -1;
	visu->speed = -1;
	visu->pause = 1;
	visu->test = 1;
}

int			main(int argc, char **argv)
{
	t_visu	visu;
	t_argm	argm;
	t_core	cw;

	cw_usage(argc, argv);
	cw_initstruct(&cw, &argm, argc, argv);
	init_visu_strcut(&visu);
	cw_check_define(&argm);
	cw_flags(&cw, &argm);
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
