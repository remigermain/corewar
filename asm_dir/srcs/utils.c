/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/15 07:49:21 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 17:40:59 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

int	is_label(char *str)
{
	int	i;

	i = spn_whspaces(str);
	if (ft_strchr(str, LABEL_CHAR))
	{
		while (str[i] && ft_isprint(str[i]) && str[i] != LABEL_CHAR)
			i++;
		if (i && str[i] == LABEL_CHAR && (!str[i + 1] \
												|| ft_iswhitespace(str[i + 1])))
			return (1);
	}
	return (0);
}

int	binary_shift(int param)
{
	int	shift;

	shift = param == 1 ? 6 : 0;
	shift = param == 2 ? 4 : shift;
	shift = param == 3 ? 2 : shift;
	return (shift);
}

int	spn_label(char *line)
{
	int	i;

	i = 0;
	if ((i = ft_strchri(line, LABEL_CHAR)))
	{
		while (line[i + 1] && line[i + 1] == LABEL_CHAR)
			i++;
		if (ft_iswhitespace(line[++i]) || !line[i])
		{
			i += spn_whspaces(line + i);
			return (i);
		}
	}
	return (spn_whspaces(line));
}

int	spn_whspaces(char *str)
{
	return (ft_strspn(str, WHITESPACES));
}

int	ft_strtoi(const char *str, long *number)
{
	long	nb;
	int		sign;

	sign = 1;
	nb = 0;
	while (ft_iswhitespace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '+' || *str == '-')
		return (-1);
	while (*str == '0')
		str++;
	while (*str)
	{
		nb = nb * 10 + (*str - '0');
		if (!ft_isdigit(*str))
			return (-1);
		str++;
	}
	*number = nb * sign;
	return (0);
}
