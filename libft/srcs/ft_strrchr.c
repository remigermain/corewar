/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:51:31 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 06:49:48 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (c == 0)
		return (&((char*)s)[i]);
	while (i--)
		if (s[i] == (unsigned char)c)
			return (&((char*)s)[i]);
	return (NULL);
}
