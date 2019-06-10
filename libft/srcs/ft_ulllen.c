/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ulllen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 08:59:37 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 08:59:38 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_ulllen(unsigned long long n, unsigned long long base)
{
	int i;

	i = 0;
	while (n > base - 1)
	{
		n /= base;
		i++;
	}
	return (i + 1);
}
