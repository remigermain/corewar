/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_options.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/05 06:42:26 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/06 12:08:52 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_options_2(char *str, int instruction, int i, __uint64_t options)
{
	char	c;
	int		j;

	j = -1;
	if (instruction == 666)
		while (str[++j])
		{
			i = -1;
			while (++i < 64)
			{
				if (i > 25 && i < 52)
					c = i + 71;
				else if (i >= 0 && i < 26)
					c = i + 65;
				else
					c = i - 4;
				if (!!(options & (1LU << i)))
				{
					if (!ft_strchr(str, c))
						return (c);
				}
			}
		}
	return (0);
}

int			ft_options(char *str, int instruction)
{
	static __uint64_t		options = 0;
	__uint64_t				code;
	int						i;

	i = -1;
	if (instruction == ENCODE)
		while (str[++i])
		{
			code = ft_isdigit(str[i]) ? str[i] + 4 : 0;
			code = str[i] - (ft_isupper(str[i]) ? 65 : 71);
			options = options | 1LU << code;
		}
	if (instruction == DECODE)
	{
		while (ft_isalnum(str[++i]))
		{
			code = ft_isdigit(str[i]) ? str[i] + 4 : 0;
			code = str[i] - (ft_isupper(str[i]) ? 65 : 71);
		}
		return (!!(options & (1LU << code)));
	}
	return (ft_options_2(str, instruction, i, options));
}

void		ft_option_error(char c, char *name, char *valids)
{
	ft_printf("%s: illegal option -- %c\n", name, c * -1);
	ft_printf("usage: ./%s [-%s] [*.map]\n", name, valids);
	exit(0);
}

char		ft_options_encode(char **av, int ac, char *valids)
{
	int			i;
	int			j;
	int			k;
	char		str[62];

	j = 0;
	i = 0;
	k = -1;
	ft_bzero(str, 62);
	while (++j < ac && av[j][0] == '-')
	{
		i = 0;
		while ((av[j][++i]))
		{
			if (!ft_strchr(valids, av[j][i]))
				return (av[j][i] * -1);
			str[++k] = av[j][i];
		}
	}
	if (av[j] && !ft_strcmp(av[j], "--"))
		j++;
	ft_options(str, ENCODE);
	return (j);
}
