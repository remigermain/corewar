/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   output.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/14 12:40:49 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 10:04:20 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

void	output_header(t_file file_data, int fd_output)
{
	write(fd_output, &file_data.header, sizeof(t_header));
}

void	output(t_linelst *file, t_file *file_data)
{
	int	fd_output;

	if (file_data->header.prog_size == 0)
		put_error(NULL, -1, g_str[E_SUCK], PE_WARN);
	if (!put_error(NULL, -1, NULL, PE_GET_ERRORS))
	{
		fd_output = open(file_data->output_name, O_CREAT | O_WRONLY | O_TRUNC |
															O_APPEND, S_IRWXU);
		file_data->header.prog_size = ft_reverse_uint_bytes(get_memory(file));
		file_data->header.magic = ft_reverse_uint_bytes(COREWAR_EXEC_MAGIC);
		output_header(*file_data, fd_output);
		output_prog(file, fd_output);
		ft_printf(g_str[COMP_OK], file_data->header.prog_name);
	}
	else
		ft_printf(g_str[COMP_FAIL], file_data->header.prog_name);
}
