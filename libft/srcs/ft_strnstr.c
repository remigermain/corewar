/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 22:13:03 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 15:59:16 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)s);
	while (s[i] && i < len)
	{
		j = 0;
		while (s[i + j] == needle[j] && i + j < len)
			if (needle[++j] == '\0')
				return (&((char*)s)[i]);
		i++;
	}
	return (NULL);
}
