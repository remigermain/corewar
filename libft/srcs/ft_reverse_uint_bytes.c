/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_reverse_uint_bytes.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/15 07:49:21 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 16:04:13 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_reverse_uint_bytes(unsigned int nb)
{
	nb = ((nb & 0x000000FF) << 24) | ((nb & 0x0000FF00) << 8) |
		((nb & 0x00FF0000) >> 8) | ((nb & 0xFF000000) >> 24);
	return (nb);
}

unsigned int	ft_reverse_ushort_bytes(unsigned int nb)
{
	return ((nb & 0xFF) << 8 | (nb & 0xFF00) >> 8);
}
