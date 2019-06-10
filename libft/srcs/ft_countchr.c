/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_countchr.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <loiberti@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 10:55:06 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 04:42:52 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_countchr(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
		if (*str++ == c)
			count++;
	return (count);
}
