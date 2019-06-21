/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/15 05:15:32 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/20 06:42:59 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "op.h"
# include "asm_str.h"
# include "cw_colors.h"
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "libft.h"

# define ML_INIT 0
# define ML_ADD_ADDR 1
# define ML_GET_ADDR 2
# define ML_GET_INDEX 3
# define ML_FREE 4
# define ML_GET_LAB_NB 5
# define ML_GET_LAB_NAME 6

# define MAX_FILE_LENGHT 32768

# define VALIDS_OPTIONS "v"

# define PE_ERR 1
# define PE_WARN 2
# define PE_GET_ERRORS 4
# define PE_GET_WARNINGS 8
# define PE_EXIT 16
# define PE_NONL 32
# define SUCCESS 1
# define FAILURE 0

# define QUIT 1
# define INIT 2
# define ERROR 4

# define STR_NB 128

extern const char *g_str[STR_NB];

typedef struct	s_linelst
{
	struct s_linelst	*nxt;
	char				*line;
	int					line_nb;
	int					weight;
	int					opcode;
	int					octal;
	int					param[3];
	int					param_type[3];
	int					addr;
	char				labels;
}				t_linelst;

typedef struct	s_file
{
	t_header	header;
	int			fd_output;
	char		output_name[128];
	char		file_name[128];
}				t_file;

typedef struct	s_label
{
	char		name[LABEL_LENGTH];
	int			addr;
}				t_label;

/*
**-----------------------------------------------------------------------
**			INPUT
**-----------------------------------------------------------------------
*/

int				input(int ac, char **av, t_file *file_data);
char			*get_ext(char *str);
char			*get_basename(char *str);
void			check_ext(int i, char **av);

/*
**-----------------------------------------------------------------------
**			OUTPUT
**-----------------------------------------------------------------------
*/

void			output_prog(t_linelst *file, int fd_output);
void			output_header(t_file file_data, int fd_output);
void			output(t_linelst *file, t_file *file_data);

/*
**-----------------------------------------------------------------------
**			LABELS
**-----------------------------------------------------------------------
*/

int				manage_labels(t_linelst *file, char **str, int index, int todo);
int				check_and_remove_labels(t_linelst *file);
int				get_label_names(t_linelst *file, t_label *lab_tab);
int				count_labels(t_linelst *file);
int				find_addr(t_linelst *file);
t_label			*get_label_addr(t_linelst *file, t_label *lab_tab);
int				find_index(char *str, t_label *lab_tab, int label_nb);
int				label_name(t_label *lab_tab, char **str, int index);

/*
**-----------------------------------------------------------------------
**			HEADER
**-----------------------------------------------------------------------
*/

int				get_header(t_file *file_data, t_linelst *file);

/*
**-----------------------------------------------------------------------
**			READ_FILE
**-----------------------------------------------------------------------
*/

t_linelst		*read_file(int ac, char **av, t_linelst *file, \
															t_file *file_data);

/*
**-----------------------------------------------------------------------
**			LINELST
**-----------------------------------------------------------------------
*/

t_linelst		*add_linelst(t_linelst *lst, char *str, int line_nb);
void			delete_linelst(t_linelst *lst);
t_linelst		*delete_linelst_elem(t_linelst *lst, t_linelst *elem);

/*
**-----------------------------------------------------------------------
**			UTILS
**-----------------------------------------------------------------------
*/

const t_op		*get_op_tab();
int				is_label(char *str);
int				spn_label(char *line);
int				binary_shift(int param);
int				spn_whspaces(char *str);
int				ft_strtoi(const char *str, long *number);

/*
**-----------------------------------------------------------------------
**			ERRORS
**-----------------------------------------------------------------------
*/

void			error_resume();
int				put_error(t_linelst *file, int col, const char *error, \
																	int todo);
void			asm_quit(int todo, void *data);

/*
**-----------------------------------------------------------------------
**			PARSING
**-----------------------------------------------------------------------
*/

int				get_arguments(t_linelst *file);
int				get_arguments_value_and_type(t_linelst *file, int head, \
																	int param);
void			check_maxs(t_linelst *file, int head, int arg_type, long value);
int				get_opcode(char *line, t_linelst *file);
void			get_instructions(t_linelst *file);
int				get_memory(t_linelst *file);

/*
**-----------------------------------------------------------------------
**			DISPLAY
**-----------------------------------------------------------------------
*/

void			display_data(t_file *file_data, t_linelst *file);
void			display_header_data(t_header header);
int				display_line_data(t_linelst *file);
void			display_leftovers_labels(t_file *file_data, int printed_labels);
void			display_tab_header();

#endif
