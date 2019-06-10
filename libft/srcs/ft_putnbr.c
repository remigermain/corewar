/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   putnbr.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 12:32:14 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 18:00:18 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	unsigned int nb_copy;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	nb_copy = nb;
	if (nb_copy > 9)
	{
		ft_putnbr(nb_copy / 10);
		ft_putnbr(nb_copy % 10);
	}
	else
		ft_putchar(nb_copy + '0');
}
