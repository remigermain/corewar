/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   t_linelst.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 17:38:00 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 18:45:08 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

static int	add_link(t_linelst **elem, char *str, int line_nb)
{
	if (!(*elem = (t_linelst *)malloc(sizeof(t_linelst))))
		return (0);
	ft_bzero(*elem, sizeof(t_linelst));
	(*elem)->line_nb = line_nb;
	if (!((*elem)->line = ft_strdup(str)))
		return (0);
	(*elem)->nxt = NULL;
	return (1);
}

t_linelst	*add_linelst(t_linelst *lst, char *str, int line_nb)
{
	t_linelst	*elem;
	t_linelst	*start;

	start = lst;
	if (!lst)
	{
		if (!(add_link(&elem, str, line_nb)))
			return (NULL);
		asm_quit(INIT, elem);
		return (elem);
	}
	if (!(add_link(&elem, str, line_nb)))
		return (NULL);
	while (lst->nxt)
		lst = lst->nxt;
	lst->nxt = elem;
	return (start);
}

void		delete_linelst(t_linelst *lst)
{
	t_linelst	*tmpnxt;

	if (!lst)
		return ;
	while (lst)
	{
		tmpnxt = lst->nxt;
		ft_strdel(&lst->line);
		free(lst);
		lst = tmpnxt;
	}
}

t_linelst	*delete_linelst_elem(t_linelst *lst, t_linelst *elem)
{
	if (!lst || !elem)
		return (NULL);
	while (lst && lst->nxt != elem)
		lst = lst->nxt;
	if (!lst)
		return (NULL);
	lst->nxt = elem->nxt;
	ft_strdel(&elem->line);
	free(elem);
	return (lst);
}
