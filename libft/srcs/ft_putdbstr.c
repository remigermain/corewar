/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putdbstr.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 08:16:03 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 16:09:25 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdbstr(char **dbstr, char c)
{
	int i;

	if (!dbstr)
		return ;
	i = 0;
	while (dbstr[i] != NULL)
	{
		ft_putstr(dbstr[i]);
		if (!(dbstr[i + 1] == '\0'))
			ft_putchar(c);
		i++;
	}
}
