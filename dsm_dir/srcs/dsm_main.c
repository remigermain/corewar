/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dsm_main.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/25 17:04:54 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/06 13:51:28 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "dsm.h"

/*
**-----------------------------------------------------------------------
**    ouvre le fichiers .cor , regarde si il exists , si il est comforme
**-----------------------------------------------------------------------
*/

static void		read_player(t_core *dsm, char *name)
{
	int	fd;

	if ((fd = open(name, O_RDONLY)) <= 0)
	{
		close(fd);
		dsm_error(dsm, DSM_WRONG_FILE_MISSING, name);
		return ;
	}
	if (read(fd, &(dsm->data), sizeof(t_header)) != sizeof(t_header))
		dsm_error(dsm, DSM_WRONG_HEADER_SIZE, name);
	if (ft_reverse_uint_bytes(dsm->data.magic) != COREWAR_EXEC_MAGIC)
		dsm_error(dsm, DSM_WRONG_MAGIC, name);
	if (CHAMP_MAX_SIZE < ft_reverse_uint_bytes(dsm->data.prog_size))
		dsm_error(dsm, DSM_WRONG_PROG_SIZE, name);
	else if ((size_t)(dsm->inst_limit = read(fd, dsm->file,
					ft_reverse_uint_bytes(dsm->data.prog_size) + 1))
			!= ft_reverse_uint_bytes(dsm->data.prog_size))
		dsm_error(dsm, DSM_WRONG_PROG_SIZE, name);
	close(fd);
}

/*
**-----------------------------------------------------------------------
**		remplace le .cor par .s && ouvre le fichiers , si il existe
**		demande si on le remplace ou non , sinon si il n'existe pas
**		on le cree.
**-----------------------------------------------------------------------
*/

static void		print_warning_file(t_core *dsm)
{
	ft_dprintf(2, B_PINK"Warning: "B_WHITE);
	ft_dprintf(2, "File %s existe , do you want ", dsm->file_name);
	ft_dprintf(2, "to erase ?\npress ( "RESET"y"B_WHITE" ) ");
	ft_dprintf(2, "for yes and enter\n"RESET);
}

static t_bool	create_file(t_core *dsm, char *str)
{
	int		len;
	int		fd;
	int		i;
	char	c;

	i = 0;
	len = ft_strlen(str);
	if (len > 4)
		i = ft_strlen(ft_strstr(str + len - 4, ".cor"));
	if (i != 4)
		return (dsm_error(dsm, DSM_WRONG_EXET, str));
	if (!(dsm->file_name = ft_strdup(str)))
		return (dsm_error(dsm, DSM_MALLOC, "convert_name"));
	dsm->file_name[len - i + 1] = 's';
	dsm->file_name[len - i + 2] = '\0';
	if ((fd = open(dsm->file_name, O_RDONLY)) > 0)
	{
		print_warning_file(dsm);
		if ((c = ft_getchar()) != 'y')
			return (dsm_error(dsm, DSM_CMD, &c));
	}
	close(fd);
	dsm->fd = open(dsm->file_name, O_CREAT | O_WRONLY | O_TRUNC | O_APPEND,
			S_IRWXU);
	return (TRUE);
}

/*
**-----------------------------------------------------------------------
**		recupere les infos , les labels, puis convetie les labels si flags
**		et print dans le fichier
**-----------------------------------------------------------------------
*/

static t_bool	dsm_file(t_core *dsm)
{
	t_inst_l	*lst;
	size_t		size;

	if (!(dsm->lst = (t_inst_l*)ft_memalloc(sizeof(t_inst_l))))
		return (dsm_error(dsm, DSM_MALLOC, "dsm_file"));
	lst = dsm->lst;
	size = 0;
	while (size < dsm->data.prog_size)
	{
		lst->size = size;
		lst->t_size = size;
		lst->op = dsm->file[lst->size++];
		if (!(lst->op >= CW_LIVE && lst->op <= CW_AFF && check_ocp(dsm, lst)))
			return (dsm_error(dsm, DSM_WRONG_INST, NULL));
		if (!(lst->next = (t_inst_l*)ft_memalloc(sizeof(t_inst_l))))
			return (dsm_error(dsm, DSM_MALLOC, "dsm_file"));
		lst->size = lst->size - size;
		size += lst->size;
		lst->next->prev = lst;
		lst = lst->next;
	}
	ft_memdel((void**)&(lst->prev->next));
	detect_labels(dsm);
	put_file(dsm);
	return (TRUE);
}

/*
**-----------------------------------------------------------------------
**		si tout est ok on decode le fichier
**-----------------------------------------------------------------------
*/

void			dsm_convert(t_core *dsm, char **argv)
{
	dsm->tab = get_op_tab();
	read_player(dsm, argv[dsm->ar_i]);
	if (!dsm->argm.error && create_file(dsm, argv[dsm->ar_i]))
	{
		dsm->data.prog_size = ft_reverse_uint_bytes(dsm->data.prog_size);
		if (dsm_file(dsm))
		{
			ft_printf(B_WHITE"File "RESET"\"%s\"", dsm->file_name);
			ft_printf(B_WHITE" as create !\n"RESET);
		}
	}
	if (dsm->argm.error)
		dsm_error(dsm, DSM_ERROR, "NULL");
}
