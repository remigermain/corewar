/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:06:06 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 15:18:21 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = -1;
	if (!s)
		return (NULL);
	while (s[++i])
		if (s[i] == (unsigned char)c)
			return (&((char*)s)[i]);
	if (c == 0)
		return (&((char*)s)[i]);
	return (NULL);
}
