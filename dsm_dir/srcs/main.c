/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 11:14:52 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/16 12:36:02 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "dsm.h"

/*
**-----------------------------------------------------------------------
**  	print l'usage du programe
**-----------------------------------------------------------------------
*/

static void		dsm_usage(void)
{
	ft_printf("Usage: ./dsm [ -flags ] <champions.cor>\n");
	ft_printf("\n [ -flags ]\n");
	ft_printf("\t--labels (l)\tDisassembly with labels.\n");
	ft_printf("\t--hexa (h)\tPrint hex values for eachs intructions.\n");
	ft_printf("\t\t\t\tex: for `DIR = %%436432209` ->  #1A 03 70 06\n\n");
	ft_printf("\t--help\t\tDisplay help\n");
	ft_printf("\n\tcorewar © 2019 le-101  Loiberti - Rcepre - Rgermain\n");
	exit(0);
}

static void		find_help(int argc, char **argv)
{
	int i;

	i = 0;
	while (argv[++i])
		if (!ft_strcmp(argv[i], "--help"))
			dsm_usage();
	if (argc <= 1)
		dsm_usage();
}

static t_bool	dsm_flags(t_core *dsm, int argc, char **argv)
{
	while (++dsm->argm.i < argc)
	{
		if (!ft_strcmp("-l", argv[dsm->argm.i]) ||
				!ft_strcmp("--labels", argv[dsm->argm.i]))
			set_bit(&(dsm->flags), DSM_LABELS);
		else if (!ft_strcmp("-h", argv[dsm->argm.i]) ||
				!ft_strcmp("--hexa", argv[dsm->argm.i]))
			set_bit(&(dsm->flags), DSM_HEXA);
		else if (argv[dsm->argm.i][0] != '-' && ft_strlen(argv[dsm->argm.i])
		> 4 && !ft_strcmp(argv[dsm->argm.i] +
		ft_strlen(argv[dsm->argm.i]) - 4, ".cor"))
			!dsm->ar_i ? dsm->ar_i = dsm->argm.i :
				dsm_error(dsm, DSM_MULTI_FILE, NULL);
		else
			argv[dsm->argm.i][0] == '-' ?
				dsm_error(dsm, DSM_UNK_FLAGS, argv[dsm->argm.i]) :
				dsm_error(dsm, DSM_UNK_PARAMS, argv[dsm->argm.i]);
	}
	dsm->argm.i = (!dsm->ar_i ? argc : dsm->ar_i);
	if (dsm->ar_i && !dsm->argm.error)
		return (TRUE);
	if (!dsm->ar_i)
		dsm_error(dsm, DSM_NO_FILE, NULL);
	dsm_error(dsm, DSM_ERROR, NULL);
	return (FALSE);
}

static void		dsm_free(t_core *dsm)
{
	t_inst_l *del;
	t_inst_l *lst;

	if (dsm->file_name)
		ft_memdel((void**)&dsm->file_name);
	lst = dsm->lst;
	while (lst)
	{
		del = lst;
		lst = lst->next;
		ft_memdel((void**)&del);
	}
}

/*
**-----------------------------------------------------------------------
**	check si il y a une fichier en paramettre
**-----------------------------------------------------------------------
*/

int				main(int argc, char **argv)
{
	t_core dsm;

	ft_bzero(&dsm, sizeof(t_core));
	dsm.argm.argv = argv;
	dsm.argm.argc = argc;
	find_help(argc, argv);
	if (dsm_flags(&dsm, argc, argv))
	{
		dsm_convert(&dsm, argv);
		close(dsm.fd);
	}
	dsm_free(&dsm);
	return (0);
}
