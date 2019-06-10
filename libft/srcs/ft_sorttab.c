/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sorttab.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 17:22:16 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 14:49:49 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		ft_swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void			ft_sorttab(int *tab, int size)
{
	int i;
	int wall;

	if (size <= 1)
		return ;
	i = 0;
	wall = -1;
	while (i < size - 1)
	{
		if (tab[i] < tab[size - 1])
		{
			if (i != ++wall)
				ft_swap_int(tab + wall, tab + i);
		}
		i++;
	}
	if (++wall != size - 1)
		ft_swap_int(tab + wall, tab + size - 1);
	ft_sorttab(tab, wall);
	ft_sorttab(tab + wall + 1, size - 1 - wall);
}
