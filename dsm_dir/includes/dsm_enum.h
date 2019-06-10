/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   corewar.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 11:10:55 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/05 11:59:43 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef DSM_ENUM_H
# define DSM_ENUM_H
# define TRUE 1
# define FALSE 0

typedef unsigned char	t_bool;

/*
**-----------------------------------------------------------------------
**			enum instruction
**-----------------------------------------------------------------------
*/
enum {
	CW_LIVE = 1,
	CW_LD,
	CW_ST,
	CW_ADD,
	CW_SUB,
	CW_AND,
	CW_OR,
	CW_XOR,
	CW_ZJMP,
	CW_LDI,
	CW_STI,
	CW_FORK,
	CW_LLD,
	CW_LLDI,
	CW_LFORK,
	CW_AFF
};

/*
**-----------------------------------------------------------------------
**			enum error
**-----------------------------------------------------------------------
*/
enum {
	DSM_MALLOC,
	DSM_ERROR,
	DSM_UNK_FLAGS,
	DSM_NO_FILE,
	DSM_WRONG_FILE,
	DSM_WRONG_FILE_MISSING,
	DSM_WRONG_PROG_SIZE,
	DSM_WRONG_HEADER_SIZE,
	DSM_WRONG_MAGIC,
	DSM_WRONG_EXET,
	DSM_WRONG_NEW_FILE,
	DSM_WRONG_GET,
	DSM_WRONG_INST,
	DSM_CMD,
};

/*
**-----------------------------------------------------------------------
**			flags  dsm
**-----------------------------------------------------------------------
*/
enum {
	DSM_LABELS,
	DSM_HEXA,
};

#endif
