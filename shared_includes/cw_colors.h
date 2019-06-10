/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_colors.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/15 05:15:32 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/06 13:45:02 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CW_COLORS_H
# define CW_COLORS_H

# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PINK "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define B_BLACK "\033[1;30m"
# define B_RED "\033[1;31m"
# define B_GREEN "\033[1;32m"
# define B_YELLOW "\033[1;33m"
# define B_BLUE "\033[1;34m"
# define B_PINK "\033[1;35m"
# define B_CYAN "\033[1;36m"
# define B_WHITE "\033[1;37m"
# define RESET "\033[0m"
# define REM_LINE "\033[A"
# define H_WHITE "\033[0m"
# define H_BLACK "\033[40m"
# define H_RED "\033[41m"
# define H_GREEN "\033[42m"
# define H_YELLOW "\033[43m"
# define H_BLUE "\033[44m"
# define H_PURPLE "\033[45m"
# define H_CYAN "\033[46m"
# define H_GREY "\033[47m"
# define F_REVERSE "\033[6m"

# define COL_INSTR_NAME GREEN
# define COL_OPCODE BLUE
# define COL_ADDR CYAN
# define COL_NOTHING B_BLACK
# define COL_REG PINK
# define COL_IND GREEN
# define COL_DIR CYAN
# define COL_LAB YELLOW
# define COL_COMMENT PINK
# define COL_PROG_NAME BLUE
# define COL_OCT RESET
# define COL_OCT_B RESET

#endif
