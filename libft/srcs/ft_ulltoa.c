/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ulltoa.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 10:17:46 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 08:59:55 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char			to_char(char c)
{
	if (c < 10)
		return (c + '0');
	return (c + 'a' - 10);
}

char				*ft_ulltoa(size_t n, unsigned int base)
{
	char			*str;
	int				size;

	size = ft_ulllen(n, base);
	if (!(str = ft_strnew(size--)))
		return (NULL);
	while (n > base - 1)
	{
		str[size--] = to_char(n % base);
		n = n / base;
	}
	str[size] = to_char(n % base);
	return (str);
}
