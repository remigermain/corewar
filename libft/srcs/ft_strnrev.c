/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnrev.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 04:41:07 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 12:11:23 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_strnrev(char *str, int len)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}
