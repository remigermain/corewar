/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 07:31:48 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 07:40:47 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char *tmp;

	if (!size && ptr)
	{
		if (!(tmp = ft_memalloc(1)))
			return (NULL);
		ft_memdel(&ptr);
		return (tmp);
	}
	if (!(tmp = ft_memalloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(tmp, ptr, size);
		ft_memdel(&ptr);
	}
	return (tmp);
}
