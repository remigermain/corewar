/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm_errors_str.h                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 06:54:30 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 18:35:24 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ASM_ERRORS_STR_H
# define ASM_ERRORS_STR_H

# define ERR_IND_EX_SHRT_MAX	"indirect value should not exceed SHRT_MAX"
# define ERR_IND_EX_SHRT_MIN	"indirect value should not exceed SHRT_MIN"
# define ERR_DIR_EX_SHRT_MAX	"direct value should not exceed SHRT_MAX"
# define ERR_DIR_EX_SHRT_MIN	"direct value should not exceed SHRT_MIN"
# define ERR_DIR_EX_INT_MAX		"direct value should not exceed INT_MAX"
# define ERR_DIR_EX_INT_MIN		"direct value should not exceed INT_MIN"
# define ERR_INV_REG_VAL		"invalid reg value"
# define ERR_MISS_ARG			"missing value"
# define ERR_MISS_VAL			"missing argument"
# define ERR_INV_ARG			"invalid argument"
# define ERR_INV_FORM			"invalid format"
# define ERR_INV_MNEM			"invalid mnemonic"
# define ERR_ARG_TYPE			"bad argument type"
# define ERR_EXP_EXPR			"expected expression"
# define ERR_UNEXP_EXPR			"expected expression"
# define ERR_TOO_ARG			"too many arguments"
# define ERR_FILE_LONG			"file_name too long"
# define ERR_FILE_TYPE			"invalid file type"
# define ERR_MISS_FILE			"no input file"
# define ERR_MISS_OUTPUT		"argument to '-o' is missing (expected 1 value)"
# define ERR_UNEXP_ARG			"only one file accepted"
# define ERR_PROG_BIG			"program size too big"
# define ERR_UNDECL_LAB			"use of undeclared label"
# define ERR_LONG_LAB			"label name too long"
# define ERR_CHAR_LAB			"bad label char"
# define ERR_UNEXPT_CHAR_LAB	"unexpected label char"
# define ERR_OUT_NOEXT			"output file have no extension "
# define ERR_OUT_BADEXT			"bad file extension "
# define ERR_MISS_QUOT          "missing terminating '\"' character"
# define ERR_OUT_NO_EXT_D 		B_BLACK"(missing "B_WHITE".cor"B_BLACK")\n"RESET
#endif
