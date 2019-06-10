/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_init_corewar.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 11:16:03 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 18:42:31 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
** give to players a number different to other one
**-----------------------------------------------------------------------
*/

static int		check_number_player(t_core *cw, int nb_player)
{
	int i;
	int	nb;
	int	exist;

	i = -1;
	nb = 0;
	exist = 0;
	while (++i < cw->nb_player)
	{
		if (nb == nb_player || nb == cw->player[i].number)
			nb++;
		if (nb_player == cw->player[i].number)
			exist = 1;
	}
	return (exist ? nb : nb_player);
}

/*
**-----------------------------------------------------------------------
** test validity of .cor file
**-----------------------------------------------------------------------
*/

static void		read_player2(t_core *cw, t_argm *argm, int i, int fd)
{
	size_t	size;

	if (cw->player[i].data.prog_size > CHAMP_MAX_SIZE ||
			cw->player[i].data.prog_size <= 0 ||
		((size = read(fd, cw->player[i].inst, cw->player[i].data.prog_size + 1))
			!= cw->player[i].data.prog_size))
		cw_error(cw, argm, CW_WRONG_PROG_SIZE, "read_player");
}

static t_bool	read_player(t_core *cw, t_argm *argm, char *name, int nb_player)
{
	int		fd;
	int		i;

	i = cw->nb_player;
	if ((fd = open(name, O_RDONLY)) <= 0)
		return (FALSE);
	if (read(fd, &cw->player[i].data, sizeof(t_header)) != sizeof(t_header))
		cw_error(cw, argm, CW_WRONG_HEADER_SIZE, name);
	else if (ft_reverse_uint_bytes(cw->player[i].data.magic) != CW_MAGIC)
	{
		cw->player[i].data.magic =
			ft_reverse_uint_bytes(cw->player[i].data.magic);
		cw_error(cw, argm, CW_WRONG_MAGIC, name);
	}
	else
		cw->player[i].data.prog_size =
			ft_reverse_uint_bytes(cw->player[i].data.prog_size);
	read_player2(cw, argm, i, fd);
	close(fd);
	cw->player[cw->nb_player++].number = check_number_player(cw, nb_player);
	argm->i++;
	return (TRUE);
}

/*
**-----------------------------------------------------------------------
** check validity of player number
**-----------------------------------------------------------------------
*/

void			put_player(t_core *cw, t_argm *argm)
{
	int	nb_player;

	nb_player = cw->nb_player + 1;
	if (nb_player == MAX_PLAYERS + 1)
		cw_error(cw, argm, CW_TO_MANY_PLAYER, NULL);
	if (argm->argv[argm->i + 1] && (!ft_strcmp(argm->argv[argm->i + 1], "-n") ||
			!ft_strcmp(argm->argv[argm->i + 1], "--number")))
	{
		if (argm->argv[++argm->i + 1] &&
					ft_strlen(argm->argv[argm->i + 1]) <= 12)
			nb_player = ft_atoi(argm->argv[++argm->i]);
		if (!argm->argv[argm->i] || !ft_str_is_digit(argm->argv[argm->i]) ||
				nb_player > MAX_ARGS_NUMBER)
			cw_error(cw, argm, CW_WRONG_NUMBER_PLAYER, NULL);
	}
	if (!argm->argv[++argm->i] ||
				!read_player(cw, argm, argm->argv[argm->i], nb_player))
	{
		cw_error(cw, argm, CW_WRONG_FILE_MISSING, NULL);
		if (!cw_isflags(argm->argv[argm->i]))
			argm->i++;
	}
}
