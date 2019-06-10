/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcspn.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/15 09:20:40 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 16:02:00 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s1, const char *s2)
{
	const char	*s1cpy = s1;
	const char	*s2cpy;

	while (*s1)
	{
		s2cpy = s2;
		while (*s2cpy)
		{
			if (*s1cpy == *s2cpy++)
				return (s1cpy - s1);
		}
		s1cpy++;
	}
	return (s1cpy - s1);
}
