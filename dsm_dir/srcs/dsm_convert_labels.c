/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   instructions4.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/16 11:56:11 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 12:29:41 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "dsm.h"

static void		itoa_labels(char *str, int nb)
{
	int tmp;
	int i;

	ft_bzero(str, 12);
	tmp = nb;
	i = 1;
	while (tmp >= 10)
	{
		tmp /= 10;
		i++;
	}
	while (i)
	{
		str[--i] = nb % 10 + '0';
		nb /= 10;
	}
}

static void		labels_name(t_inst_l *tmp, t_inst_l *lst, int size)
{
	static int	nb = 1;
	char		str[12];

	if (size == 0)
	{
		itoa_labels(str, nb++);
		if (!lst->labels[0])
		{
			ft_memcpy(lst->labels, "labels", 6);
			ft_memcpy(lst->labels + 6, str, 2);
			ft_memcpy(tmp->this_labels, lst->labels, 8);
		}
		else
			ft_memcpy(tmp->this_labels, lst->labels, 8);
	}
}

static void		convert_labels(t_inst_l *tmp)
{
	t_inst_l	*lst;
	int			size;

	size = tmp->value[tmp->labels_nb];
	if (tmp->value[tmp->labels_nb] < 0)
		lst = tmp->prev;
	else
		lst = tmp;
	while (lst)
	{
		if (tmp->value[tmp->labels_nb] < 0)
		{
			size += lst->size;
			lst = lst->prev;
		}
		else if (tmp->value[tmp->labels_nb] > 0)
			size -= lst->size;
		if ((tmp->value[tmp->labels_nb] < 0 && size >= 0) ||
				(tmp->value[tmp->labels_nb] > 0 && size <= 0))
			break ;
		if (tmp->value[tmp->labels_nb] > 0)
			lst = lst->next;
	}
	labels_name(tmp, lst, size);
}

void			detect_labels(t_core *dsm)
{
	t_inst_l	*lst;
	int			size;

	lst = dsm->lst;
	size = 0;
	if (test_bit((&dsm->flags), DSM_LABELS))
		while (lst)
		{
			size += lst->size;
			if (lst->labels_nb != -1)
				convert_labels(lst);
			lst = lst->next;
		}
}
