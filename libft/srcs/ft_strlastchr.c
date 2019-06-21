/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlastchr.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/03 12:22:00 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 14:58:44 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	ft_strlastchr(char *str)
{
	int i;

	i = ft_strlen(str);
	while (i--)
	{
		if (ft_iswhitespace(str[i]))
			return (str[i]);
	}
	return (0);
}
