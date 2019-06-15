/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm_str.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 06:54:30 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 12:25:41 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ASM_STR_H
# define ASM_STR_H

enum {
	E_DOT_CHAR,
	E_NAME_TOO_LONG,
	E_COM_TOO_LONG,
	E_IND_EX_SHRT_MIN,
	E_IND_SHRT_MAX,
	E_DIR_EX_SHRT_MIN,
	E_DIR_SHRT_MAX,
	E_DIR_EX_INT_MAX,
	E_DIR_EX_INT_MIN,
	E_INV_REG_VAL,
	E_MISS_VAL,
	E_MISS_ARG,
	E_INV_ARG,
	E_INV_FORM,
	E_INV_MNEM,
	E_ARG_TYPE,
	E_EXP_EXPR,
	E_UNEXP_EXPR,
	E_TOO_ARG,
	E_FILE_LONG,
	E_FILE_TYPE,
	E_MISS_FILE,
	E_MISS_OUTPUT,
	E_UNEXP_ARG,
	E_PROG_BIG,
	E_UNDECL_LAB,
	E_LONG_LAB,
	E_CHAR_LAB,
	E_UNEXPT_CHAR_LAB,
	E_OUT_NOEXT,
	E_OUT_BADEXT,
	E_OUT_NO_EXT_D,
	E_SUCK,
	E_LAB_SET,
	E_FILE_CORRUPT,
	E_MISS_TERM_NAM,
	E_MISS_TERM_COM,
	E_COMMENT_SET,
	E_NAME_SET,
	E_MISS_COMMENT,
	E_MISS_NAME,
	E_MISS_EXT,
	E_INV_OPT,
	E_EMPTY_FILE,
	COMP_OK,
	COMP_FAIL,
	DATA_TAB_HEADER,
	USAGE
};

#endif
