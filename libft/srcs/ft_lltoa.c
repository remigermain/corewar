/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lltoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 10:17:46 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 10:26:00 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char				*ft_lltoa(long long n)
{
	char			*str;
	int				size;
	int				sign;

	sign = 0;
	if (n < 0)
	{
		n *= -1;
		sign = 1;
	}
	size = ft_lllen(n, 10) + sign;
	if (!(str = ft_strnew(size--)))
		return (NULL);
	while (n > 9)
	{
		str[size--] = n % 10 + '0';
		n = n / 10;
	}
	str[size] = n + '0';
	if (sign == 1)
		str[0] = '-';
	return (str);
}
