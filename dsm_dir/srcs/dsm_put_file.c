/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   instructions4.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/16 11:56:11 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 20:01:51 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "dsm.h"

static void		print_hexa(t_core *dsm, int value, int nb)
{
	value = ft_reverse_uint_bytes(value);
	while (nb)
	{
		ft_dprintf(dsm->fd, "%.2x", value & 0xff);
		value = value >> 8;
		if (--nb)
			ft_dprintf(dsm->fd, " ");
	}
}

static void		put_hexa(t_core *dsm, t_inst_l *lst, int size)
{
	int			binary;
	int			param_nb;

	if (test_bit(&(dsm->flags), DSM_HEXA))
	{
		param_nb = 0;
		ft_dprintf(dsm->fd, "%*c# ", 50 - size, ' ');
		while (++param_nb <= dsm->tab[lst->op - 1].nb_args)
		{
			if (param_nb != 1)
				ft_dprintf(dsm->fd, ",   ");
			binary = (lst->ocp >> binary_shift(param_nb)) & 0x03;
			if (binary == REG_CODE)
				ft_dprintf(dsm->fd, "reg: %6d",\
						lst->value[param_nb - 1]);
			else if (binary == DIR_CODE)
				print_hexa(dsm, lst->value[param_nb - 1], 4);
			else if (binary == IND_CODE)
				print_hexa(dsm, lst->value[param_nb - 1], 4);
		}
	}
}

static int		put_param(t_core *dsm, t_inst_l *lst, int param_nb)
{
	int	binary;
	int i;

	i = 0;
	binary = (lst->ocp >> binary_shift(param_nb)) & 0x03;
	if (param_nb != 1)
		i += ft_dprintf(dsm->fd, ", ");
	if (binary == REG_CODE)
		i += ft_dprintf(dsm->fd, "r%d", lst->value[param_nb - 1]);
	else if (binary == DIR_CODE && (param_nb - 1) == lst->labels_nb &&
			lst->this_labels[0])
		i += ft_dprintf(dsm->fd, "%%:%s", lst->this_labels);
	else if (binary == DIR_CODE)
		i += ft_dprintf(dsm->fd, "%%%d", lst->value[param_nb - 1]);
	else if (binary == IND_CODE)
		i += ft_dprintf(dsm->fd, "%d", lst->value[param_nb - 1]);
	return (i);
}

static void		put_header(t_core *dsm)
{
	ft_dprintf(dsm->fd, "#%70@\n#\t\t\t\tdisassembled from %.*scor\
			\n#%70@\n\n", "char", '-', ft_strlen(dsm->file_name) - 1,
			dsm->file_name, "char", '-');
	ft_dprintf(dsm->fd, ".name\t\t\t\"%s\"\n", dsm->data.prog_name);
	ft_dprintf(dsm->fd, ".comment\t\t\"%s\"\n\n", dsm->data.comment);
	ft_dprintf(dsm->fd, "#%70@\n#\t\t\t\tInstructions\
			\n#%70@\n\n", "char", '-', "char", '-');
}

void			put_file(t_core *dsm)
{
	t_inst_l	*lst;
	int			param_nb;
	int			size;

	lst = dsm->lst;
	put_header(dsm);
	while (lst && (size = 0) != 101)
	{
		param_nb = 0;
		size += ft_dprintf(dsm->fd, "\t\t%-15s", dsm->tab[lst->op - 1].name);
		while (++param_nb <= dsm->tab[lst->op - 1].nb_args)
			size += put_param(dsm, lst, param_nb);
		put_hexa(dsm, lst, size);
		ft_dprintf(dsm->fd, "\n");
		if (lst->labels[0])
			ft_dprintf(dsm->fd, "\n%s:\n", lst->labels);
		lst = lst->next;
	}
	ft_dprintf(dsm->fd, "\n#%70@\n#\t\
			corewar © 2019 le-101 Loiberti - Rcepre - Rgermain\
			\n#%70@\n", "char", '-', "char", '-');
}
