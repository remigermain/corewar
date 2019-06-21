/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dsm.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 11:10:55 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/17 14:04:06 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef DSM_H
# define DSM_H
# include "op.h"
# include "libft.h"
# include "dsm_enum.h"
# include <fcntl.h>
# include "cw_colors.h"
# include <errno.h>

typedef struct	s_inst_l
{
	int				op;
	int				ocp;
	int				value[3];
	int				labels_nb;
	char			labels[20];
	char			this_labels[20];
	int				size;
	int				t_size;
	struct s_inst_l	*next;
	struct s_inst_l	*prev;
}				t_inst_l;

typedef	struct	s_argm
{
	char	**argv;
	int		argc;
	int		i;
	int		error;
}				t_argm;

typedef struct	s_core
{
	const t_op		*tab;
	int				flags;
	t_header		data;
	unsigned char	file[CHAMP_MAX_SIZE + 1];
	int				inst_limit;
	int				fd;
	int				ar_i;
	char			*file_name;
	t_inst_l		*lst;
	t_argm			argm;
}				t_core;

/*
**-----------------------------------------------------------------------
**  		instruction	main
**			dsm_read_instruction.c && dsm_convert_labels.c
**-----------------------------------------------------------------------
*/

void			dsm_convert(t_core *dsm, char **argv);
void			detect_labels(t_core *dsm);
t_bool			check_ocp(t_core *dsm, t_inst_l *lst);
void			put_file(t_core *dsm);

/*
**-----------------------------------------------------------------------
**  		bit	tools
**			tools_bits.c
**-----------------------------------------------------------------------
*/
t_bool			dsm_error(t_core *dsm, enum e_error error, char *str);
t_bool			test_bit(int *st, int i);
void			set_bit(int *st, int i);
void			clear_bit(int *st, int i);
int				add_octet(unsigned char *str, int i, int mod);
int				binary_shift(int param);
const t_op		*get_op_tab();
#endif
