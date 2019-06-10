/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strspn.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/15 08:58:05 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 16:01:15 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *str1, const char *str2)
{
	const char	*s1 = str1;
	const char	*s2;

	while (*s1)
	{
		s2 = str2;
		while (1)
		{
			if (*s1 == *s2)
				break ;
			else if (*s2++ == '\0')
				return (s1 - str1);
		}
		s1++;
	}
	return (s1 - str1);
}
