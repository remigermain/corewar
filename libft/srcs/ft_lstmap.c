/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 06:20:50 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 06:20:51 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin_list;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	begin_list = new;
	lst = lst->nxt;
	while (lst)
	{
		tmp = f(lst);
		if (!(new->nxt = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		lst = lst->nxt;
		new = new->nxt;
	}
	return (begin_list);
}
