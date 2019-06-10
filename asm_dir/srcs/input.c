/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 06:23:23 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 16:37:10 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

int		output_name(int ac, char **av, t_file *file_data)
{
	int		i;
	int		ac_tmp;

	i = -1;
	ac_tmp = ac;
	while (++i < ac)
	{
		if (!ft_strcmp(av[i], "-o"))
		{
			ft_bzero(av[i], ft_strlen(av[i]));
			ac_tmp--;
			if (!av[i + 1])
				put_error(NULL, -1, ERR_MISS_OUTPUT, PE_ERR | PE_EXIT);
			else
			{
				check_ext(i, av);
				ft_strcpy(file_data->output_name, av[i + 1]);
				ft_bzero(av[i + 1], ft_strlen(av[i + 1]));
				ac_tmp--;
			}
		}
	}
	return (ac_tmp);
}

int		check_options(int ac, char **av, int rest)
{
	int		i;
	char	c;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-')
		{
			ft_options(av[i] + 1, ENCODE);
			if ((c = ft_options("v", 666)))
			{
				put_error(NULL, -1, "invalid option: ", PE_ERR | PE_NONL);
				ft_printf("-%c\n", c);
				exit(0);
			}
			ft_bzero(av[i], ft_strlen(av[i]));
			rest--;
		}
	}
	return (rest);
}

char	*get_output_from_filename(char *name)
{
	char	*output;

	output = get_basename(name);
	ft_printf("name: %s\n", name);
	ft_printf("basename: %s\n", output);
	ft_bzero(ft_strrchr(output, '.'), ft_strlen(get_ext(output)));
	ft_strcat(output, ".cor");
	ft_printf("output: %s\n", output);
	return (output);
}

void	get_file_name(int ac, char **av, t_file *file_data)
{
	int		i;
	char	*name;

	i = 0;
	name = NULL;
	while (++i < ac)
	{
		if (*av[i] && !name)
			name = av[i];
		else if (*av[i])
			put_error(NULL, -1, ERR_UNEXP_ARG, PE_ERR | PE_EXIT);
	}
	if (ft_strlen(name) > 128)
		put_error(NULL, -1, ERR_FILE_LONG, PE_ERR | PE_EXIT);
	if (!get_ext(name))
		put_error(NULL, -1, "missing file extension " B_BLACK \
" (should be " B_WHITE ".s" B_BLACK ")" RESET, PE_ERR | PE_EXIT);
	if (ft_strcmp(get_ext(name), ".s"))
		put_error(NULL, -1, ERR_OUT_BADEXT, PE_ERR | PE_EXIT);
	ft_strcpy(file_data->file_name, name);
	if (!*file_data->output_name)
		ft_strcpy(file_data->output_name, get_output_from_filename(name));
}

int		input(int ac, char **av, t_file *file_data)
{
	int		fd;
	int		rest;

	if ((rest = output_name(ac, av, file_data)) < 2)
		put_error(NULL, -1, ERR_MISS_FILE, PE_ERR | PE_EXIT);
	if ((rest = check_options(ac, av, rest)) < 2)
		put_error(NULL, -1, ERR_MISS_FILE, PE_ERR | PE_EXIT);
	get_file_name(ac, av, file_data);
	if ((fd = open(file_data->file_name, O_RDONLY)) == -1)
		put_error(NULL, -1, strerror(errno), PE_ERR | PE_EXIT);
	return (fd);
}
