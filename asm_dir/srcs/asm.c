/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/01 20:19:55 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/20 08:15:36 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

static void	display_usage(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc > 1)
	{
		while (argv[++i])
			if (!ft_strcmp(argv[i], "-h") || !ft_strcmp(argv[i], "--help"))
				break ;
		if (!argv[i])
			return ;
	}
	ft_printf(g_str[USAGE]);
	exit(0);
}

void		init_header(t_header *header)
{
	ft_bzero(header, sizeof(t_header));
	header->magic = ft_reverse_uint_bytes(COREWAR_EXEC_MAGIC);
}

void		label_to_value(t_linelst *file)
{
	int		i;

	while (file)
	{
		if (file->opcode > 0)
		{
			i = -1;
			while (++i < 3)
				if (file->labels & 1 << i)
					file->param[i] = manage_labels(file, NULL, file->param[i], \
													ML_GET_ADDR) - file->addr;
		}
		file = file->nxt;
	}
}

int			main(int ac, char **av)
{
	t_linelst	*file;
	t_file		file_data;

	file = NULL;
	display_usage(ac, av);
	ft_bzero(&file_data, sizeof(t_file));
	file = read_file(ac, av, file, &file_data);
	get_header(&file_data, file);
	manage_labels(file, NULL, 0, ML_INIT);
	get_instructions(file);
	if ((file_data.header.prog_size = get_memory(file)) > CHAMP_MAX_SIZE)
		put_error(NULL, -1, g_str[E_PROG_BIG], PE_WARN);
	manage_labels(file, NULL, 0, ML_ADD_ADDR);
	label_to_value(file);
	error_resume();
	display_data(&file_data, file);
	output(file, &file_data);
	asm_quit(QUIT, NULL);
	return (0);
}
