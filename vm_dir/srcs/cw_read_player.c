/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_init_corewar.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 11:16:03 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/21 14:45:28 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
** give to players a number different to other one
**-----------------------------------------------------------------------
*/

static int	check_number_player(t_core *cw, int nb_player)
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

static void	read_player2(t_core *cw, t_argm *argm, int nb_player, int fd)
{
	size_t	size;
	int		i;

	i = cw->nb_player;
	cw->player[i].number = -1;
	cw->player[i].data.prog_size =
			ft_reverse_uint_bytes(cw->player[i].data.prog_size);
	if (cw->player[i].data.prog_size > CHAMP_MAX_SIZE)
		cw_error(cw, argm, CW_CHAMP_SIZE, cw->player[i].name_file);
	else if ((size = read(fd, cw->player[i].inst,
		cw->player[i].data.prog_size + 1)) != cw->player[i].data.prog_size)
		cw_error(cw, argm, CW_PROG_SIZE, cw->player[i].name_file);
	cw->player[cw->nb_player++].number =
			check_number_player(cw, nb_player);
}

static void	read_player(t_core *cw, t_argm *argm, char *name, int nb_player)
{
	int		fd;
	int		i;

	i = cw->nb_player;
	cw->player[i].name_file = name;
	errno = 0;
	cw->player[i].name_file = name;
	if ((fd = open(name, O_RDONLY | O_NOFOLLOW)) <= 0)
		cw_error(cw, argm, CW_OPEN, name);
	else if (read(fd, &cw->player[i].data, sizeof(t_header))
			!= sizeof(t_header))
	{
		if (errno)
			cw_error(cw, argm, CW_OPEN, name);
		else
			cw_error(cw, argm, CW_WRONG_HEADER_SIZE, name);
	}
	else if ((cw->player[i].data.magic =
		ft_reverse_uint_bytes(cw->player[i].data.magic)) == CW_MAGIC)
		read_player2(cw, argm, nb_player, fd);
	else
		cw_error(cw, argm, CW_WRONG_MAGIC, name);
	close(fd);
	argm->i++;
}

/*
**-----------------------------------------------------------------------
** check validity of player number
**-----------------------------------------------------------------------
*/

void		put_player(t_core *cw, t_argm *argm)
{
	int	nb_player;

	nb_player = cw->nb_player + 1;
	if (nb_player >= MAX_PLAYERS + 1)
		cw_error(cw, argm, CW_TO_MANY_PLAYER, NULL);
	if (argm->argv[argm->i] && (!ft_strcmp(argm->argv[argm->i], "-n") ||
			!ft_strcmp(argm->argv[argm->i], "--number")))
	{
		if (argm->argv[++argm->i] &&
					ft_strlen(argm->argv[argm->i]) <= 12)
			nb_player = ft_atoi(argm->argv[argm->i]);
		if (!argm->argv[argm->i] || !ft_str_is_digit(argm->argv[argm->i]))
			cw_error(cw, argm, CW_WRONG_NUMBER_PLAYER, NULL);
		else if (nb_player > FT_INT_MAX || nb_player < FT_INT_MIN)
			cw_error(cw, argm, nb_player < FT_INT_MIN ? CW_NUM_L : CW_NUM_H, 0);
		else
			argm->i++;
	}
	if (!argm->argv[argm->i] || !cw_is_champ(argm->argv[argm->i]) ||
			nb_player >= MAX_PLAYERS + 1)
	{
		cw_error(cw, argm, CW_WRONG_FILE_MISSING, NULL);
		argm->i++;
	}
	else
		read_player(cw, argm, argm->argv[argm->i], nb_player);
}
