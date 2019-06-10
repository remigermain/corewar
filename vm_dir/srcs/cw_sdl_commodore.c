/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   animation.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/04 12:03:31 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/09 18:09:22 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static void	fill_from_to(unsigned char *commo, int start, int end, int nb_line)
{
	int	tmp;

	tmp = start;
	while (tmp <= end)
		commo[tmp++] = 1;
	start += (40 - nb_line) * 64;
	end += (40 - nb_line) * 64;
	while (start <= end)
		commo[start++] = 1;
}

static void	write_commodore(unsigned char *commodore)
{
	fill_from_to(commodore, 794, 803, 1);
	fill_from_to(commodore, 856, 868, 3);
	fill_from_to(commodore, 918, 932, 5);
	fill_from_to(commodore, 980, 996, 7);
	fill_from_to(commodore, 1043, 1060, 9);
	fill_from_to(commodore, 1106, 1124, 11);
	fill_from_to(commodore, 1169, 1188, 13);
	fill_from_to(commodore, 1232, 1252, 15);
	fill_from_to(commodore, 1295, 1316, 17);
	fill_from_to(commodore, 1358, 1375, 19);
	fill_from_to(commodore, 1378, 1380, 19);
	fill_from_to(commodore, 1421, 1432, 21);
	fill_from_to(commodore, 1485, 1495, 23);
	fill_from_to(commodore, 1509, 1525, 23);
}

static void	write_commodore2(unsigned char *commodore)
{
	fill_from_to(commodore, 1548, 1558, 25);
	fill_from_to(commodore, 1573, 1588, 25);
	fill_from_to(commodore, 1612, 1621, 27);
	fill_from_to(commodore, 1637, 1651, 27);
	fill_from_to(commodore, 1676, 1684, 29);
	fill_from_to(commodore, 1701, 1714, 29);
	fill_from_to(commodore, 1739, 1747, 31);
	fill_from_to(commodore, 1765, 1777, 31);
	fill_from_to(commodore, 1803, 1811, 33);
	fill_from_to(commodore, 1829, 1840, 33);
	fill_from_to(commodore, 1867, 1874, 35);
	fill_from_to(commodore, 1893, 1903, 35);
	fill_from_to(commodore, 1931, 1937, 37);
	fill_from_to(commodore, 1957, 1966, 37);
	fill_from_to(commodore, 1995, 2000, 39);
}

/*
**-----------------------------------------------------------------------
**	display commodore logo
**-----------------------------------------------------------------------
*/

int			display_outro(t_visu *visu)
{
	unsigned char	commodore[4096];

	ft_bzero(commodore, MEM_SIZE);
	write_commodore(commodore);
	write_commodore2(commodore);
	return (left_right_animation(visu, commodore));
}
