/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display2.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/17 09:39:51 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 09:36:40 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

void	display_tab_header(void)
{
	ft_printf("\n");
	ft_printf(g_str[DATA_TAB_HEADER]);
	ft_printf("%86@\n", "char", '-');
}

void	display_leftovers_labels(t_file *file_data, int printed_labels)
{
	char *str;

	if (printed_labels + 1 < manage_labels(NULL, NULL, 0, ML_GET_LAB_NB))
	{
		ft_printf("%81@", "char", ' ');
		ft_printf("" CYAN " 0x%-4x" RESET "  " RESET, \
												file_data->header.prog_size);
		while (printed_labels < manage_labels(NULL, NULL, 0, ML_GET_LAB_NB))
		{
			manage_labels(NULL, &str, printed_labels++, ML_GET_LAB_NAME);
			ft_printf(YELLOW "<- %s " RESET, str);
		}
		ft_printf("\n");
	}
}
