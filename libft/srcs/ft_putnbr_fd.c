/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   putnbr.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 12:32:14 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 11:16:06 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int nb_copy;

	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	nb_copy = nb;
	if (nb_copy > 9)
	{
		ft_putnbr_fd(nb_copy / 10, fd);
		ft_putnbr_fd(nb_copy % 10, fd);
	}
	else
		ft_putchar_fd(nb_copy + '0', fd);
}
