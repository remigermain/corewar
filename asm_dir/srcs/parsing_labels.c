/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_labels.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/08 06:59:35 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 18:26:34 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

int				manage_labels(t_linelst *file, char **str, int index, int todo)
{
	static t_label	*lab_tab = NULL;
	static int		label_nb;

	if (todo == ML_INIT && !lab_tab && file)
	{
		check_labels(file);
		label_nb = count_labels(file);
		if (!(lab_tab = (t_label *)ft_memalloc(sizeof(t_label) * label_nb)))
			asm_quit(QUIT, NULL);
		lab_tab = get_label_names(file, lab_tab);
	}
	if (todo == ML_ADD_ADDR && file)
		get_label_addr(file, lab_tab);
	if (todo == ML_GET_INDEX)
		return (find_index(*str, lab_tab, label_nb));
	if (todo == ML_GET_LAB_NB)
		return (label_nb);
	if (todo == ML_GET_LAB_NAME)
		return (label_name(lab_tab, str, index));
	if (todo == ML_GET_ADDR && index >= 0)
		return (lab_tab[index].addr);
	if (todo == ML_FREE)
		free(lab_tab);
	return (0);
}
