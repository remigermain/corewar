/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strfsub.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 11:13:59 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 21:12:40 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfsub(char **s, unsigned int start, size_t len)
{
	char	*tmp;

	if (!(tmp = ft_strsub(*s, start, len)))
		return (NULL);
	free(*s);
	*s = ft_strdup(tmp);
	free(tmp);
	return (*s);
}
