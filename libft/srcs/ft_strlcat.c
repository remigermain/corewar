/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 05:08:30 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 05:54:11 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t		lendest;
	size_t		lensrc;
	size_t		len;

	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	if (n == 0)
		return (lensrc);
	if (n < lendest)
		len = lensrc + n;
	else
		len = lendest + lensrc;
	lensrc = -1;
	while (src[++lensrc] && lensrc + lendest < n - 1)
		dest[lendest + lensrc] = src[lensrc];
	dest[lendest + lensrc] = '\0';
	return (len);
}
