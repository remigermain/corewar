/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl_animation.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 17:22:55 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 08:13:36 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static int	diagonal_sound(int ret, int are, int k)
{
	if (!ret && k == 1 && are)
		k = -1;
	return (k);
}

/*
**-----------------------------------------------------------------------
** display text and animation
**-----------------------------------------------------------------------
*/

int			up_down_animation(t_visu *visu, unsigned char *arena, int mod)
{
	static int	mem_i = -1;
	static int	mem_mod = -1;
	int			j;
	int			i;
	int			k;

	i = -1;
	k = 1;
	if (mem_mod != mod && (mem_i = -1))
		mem_mod = mod;
	++mem_i;
	while (++i < 64 && (j = -1))
		while (++j < 64)
		{
			k = diagonal_sound((i + 1) - mem_i, arena[i * 64 + j], k);
			put_fill_rect(visu, &visu->bytetab[i * 64 + j].coord,
				(arena[i * 64 + j] == 1 && i < mem_i) ? RGB_COM : RGB_BCK);
		}
	return (mem_i < 64 ? k : 0);
}

int			left_right_animation(t_visu *visu, unsigned char *arena)
{
	static int	mem_i = -1;
	int			j;
	int			i;
	int			k;

	i = -1;
	k = 1;
	++mem_i;
	while (++i < 64 && !(j = 0))
		while (j < 4032)
		{
			k = diagonal_sound((i + 1) - mem_i, arena[i + j], k);
			put_fill_rect(visu, &visu->bytetab[i + j].coord,
				(arena[i + j] == 1 && i < mem_i) ? RGB_COM : RGB_BCK);
			j += 64;
		}
	return (mem_i < 64 ? k : 0);
}

int			diagonal_animation(t_visu *v, t_core *cw, int mod, int k)
{
	static int	mem_i = -1;
	static int	mem_mod = -1;
	int			i;
	int			j;
	int			deep;

	i = -1;
	if (mem_mod != mod && (mem_i = -1))
		mem_mod = mod;
	deep = ++mem_i;
	while (++i < 64 && (j = -1))
	{
		while (++j < 64)
		{
			k = diagonal_sound(j - (deep - i), cw->vm.arena[j + i * 64], k);
			if (!mod)
				j < deep - i ? put_fill_rect(v, &v->bytetab[i * 64 + j].coord,
								RGB_BCK) : put_one_byte(v, cw, j + i * 64);
			else
				mod && j < deep - i ? put_one_byte(v, cw, j + i * 64) :
					put_fill_rect(v, &v->bytetab[i * 64 + j].coord, RGB_BCK);
		}
		deep--;
	}
	return (mem_i < 189 ? k : 0);
}
