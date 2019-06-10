/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_is_digit.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/10 16:14:21 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 16:14:27 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	ft_str_is_print(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (ft_isprint(str[i]))
			return (1);
	}
	return (0);
}

char	ft_str_is_digit(char *str)
{
	int i;

	i = -1;
	if (str[i + 1] == '+' || str[i + 1] == '-')
		++i;
	if (!str[i + 1])
		return (0);
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	if (i > 12)
		return (0);
	return (1);
}
