/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dbstr_to_strlst.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 08:15:10 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 16:03:35 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_dbstr_to_strlst(char **dbstr)
{
	int		i;
	t_list	*lst;
	t_list	*begin_list;

	if (!dbstr)
		return (NULL);
	i = 0;
	if (!(lst = ft_lstnew(dbstr[i], sizeof(char) * ft_strlen(dbstr[i]))))
		return (NULL);
	begin_list = lst;
	while (dbstr[++i])
	{
		if (!(lst->nxt = ft_lstnew(dbstr[i], ft_strlen(dbstr[i]))))
			return (NULL);
		lst = lst->nxt;
	}
	lst->nxt = NULL;
	return (begin_list);
}
