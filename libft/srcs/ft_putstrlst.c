/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstrlst.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 08:13:09 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 16:22:36 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrlst(t_list *lst, char c)
{
	if (!lst)
		return ;
	while (lst)
	{
		ft_putstr((char *)lst->content);
		if (lst->nxt != NULL)
			ft_putchar(c);
		lst = lst->nxt;
	}
}
