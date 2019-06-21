/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strfsub.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 11:13:59 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 14:19:49 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfsub(char **s, unsigned int start, size_t len)
{
	char	*tmp;

	if (!(tmp = ft_strsub(*s, start, len)))
		return (NULL);
	ft_strdel(s);
	*s = tmp;
	return (*s);
}
