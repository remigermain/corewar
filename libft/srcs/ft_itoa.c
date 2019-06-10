/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 16:37:17 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 07:16:33 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(long nb)
{
	int i;

	i = 0;
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i + 1);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				size;
	int				sign;
	long			n2;

	n2 = n;
	sign = 0;
	if (n2 < 0)
	{
		n2 *= -1;
		sign = 1;
	}
	size = count_size(n2) + sign;
	if (!(str = ft_strnew(size)))
		return (NULL);
	str[size-- + 1] = '\0';
	while (n2 > 9)
	{
		str[size--] = n2 % 10 + '0';
		n2 = n2 / 10;
	}
	str[size] = n2 + '0';
	if (sign == 1)
		str[0] = '-';
	return (str);
}
