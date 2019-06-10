/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 16:39:35 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 06:01:05 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (-1);
	while (42)
	{
		if (s[i] == '\0')
			return (i);
		if (s[i + 1] == '\0')
			return (i + 1);
		if (s[i + 2] == '\0')
			return (i + 2);
		if (s[i + 3] == '\0')
			return (i + 3);
		if (s[i + 4] == '\0')
			return (i + 4);
		if (s[i + 5] == '\0')
			return (i + 5);
		if (s[i + 6] == '\0')
			return (i + 6);
		i = i + 6;
	}
}
