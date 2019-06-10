/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 22:13:03 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 15:56:53 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *needle)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)s);
	while (s[i])
	{
		j = 0;
		while (s[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return (&((char*)s)[i]);
		}
		i++;
	}
	return (NULL);
}
