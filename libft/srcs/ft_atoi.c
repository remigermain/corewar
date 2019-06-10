/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 16:41:48 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 13:44:38 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	unsigned long	nb;
	int				sign;
	int				count;

	sign = 1;
	nb = 0;
	count = 0;
	while (ft_iswhitespace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0')
		str++;
	while (ft_isdigit(*str) == 1)
	{
		nb = nb * 10 + (*str - '0');
		count++;
		str++;
	}
	if (nb > 9223372036854775807 || count > 19)
		return (sign < 0 ? 0 : 1);
	return ((int)nb * sign);
}
