/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl_put_info_players.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/30 12:31:51 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 08:27:49 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
** display player information
**-----------------------------------------------------------------------
*/

static void	print_player(t_visu *visu, t_core *cw, int nb)
{
	unsigned char	*str;
	size_t			max_len;
	int				color;

	max_len = visu->info_players[nb].w / 10;
	ft_sprintf(&str, "[%d] %s ", cw->player[nb].nb_process,
			cw->player[nb].data.prog_name);
	if (ft_strlen((char*)str) > max_len)
	{
		ft_bzero((char *)str + max_len, ft_strlen((char *)str) - max_len);
		ft_strcat((char*)str, "...");
	}
	color = nb == 0 ? RGB_PLAY_1 : 0;
	color = nb == 1 ? RGB_PLAY_2 : color;
	color = nb == 2 ? RGB_PLAY_3 : color;
	color = nb == 3 ? RGB_PLAY_4 : color;
	color = cw->last_live == nb ? 0XFFFF00 : color;
	put_text(visu, visu->info_players[nb], (char *)str, color);
}

void		put_info_players(t_visu *visu, t_core *cw)
{
	int i;

	i = 0;
	while (i < cw->nb_player)
		print_player(visu, cw, i++);
}
