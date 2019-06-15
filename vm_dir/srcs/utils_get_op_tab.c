/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_get_op_tab.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2013/10/04 11:43:01 by zaz          #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 15:28:20 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

const t_op	*get_op_tab(void)
{
	static const t_op op_tab[16] = {{"live", 1, {T_DIR}, 1, 10, 0, 4},\
{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, 1, 4},\
{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, 1, 4},\
{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, 1, 4},\
{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, 1, 4},\
{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6, 1, 4},\
{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6, 1, 4},\
{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6, 1, 4},\
{"zjmp", 1, {T_DIR}, 9, 20, 0, 2},\
{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25, 1, 2},\
{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25, 1, 2},\
{"fork", 1, {T_DIR}, 12, 800, 0, 2},\
{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, 1, 4},\
{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50, 1, 2},\
{"lfork", 1, {T_DIR}, 15, 1000, 0, 2},\
{"aff", 1, {T_REG}, 16, 2, 1, 4}, };

	return (op_tab);
}
