/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strvalids.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/09 17:20:04 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 19:21:14 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_strvalids(char *str, char *valids)
{
	int i;
	int j;
	int b;

	i = -1;
	while (str[++i])
	{
		b = 0;
		j = -1;
		while (valids[++j])
		{
			if (str[i] == valids[j])
				b = 1;
		}
		if (!b)
		{
			return (i);
		}
	}
	return (-1);
}
