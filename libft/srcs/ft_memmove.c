/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 12:30:47 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 15:07:10 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (src < dest)
		while ((int)--len >= 0)
			*(char *)(dest + len) = *(char *)(src + len);
	else
		while (++i < len)
			*(char *)(dest + i) = *(char *)(src + i);
	return (dest);
}
