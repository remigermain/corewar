/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   t_linelst.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 17:38:00 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 18:38:47 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

t_linelst	*add_linelst(t_linelst *lst, char *str, int line_nb)
{
	t_linelst	*elem;
	t_linelst	*start;

	start = lst;
	if (!lst)
	{
		if (!(elem = (t_linelst *)malloc(sizeof(t_linelst))))
			return (0);
		ft_bzero(elem, sizeof(t_linelst));
		elem->line_nb = line_nb;
		elem->line = ft_strdup(str);
		elem->nxt = NULL;
		asm_quit(INIT, elem);
		return (elem);
	}
	if (!(elem = (t_linelst *)malloc(sizeof(t_linelst))))
		return (0);
	ft_bzero(elem, sizeof(t_linelst));
	elem->line_nb = line_nb;
	elem->line = ft_strdup(str);
	elem->nxt = NULL;
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
