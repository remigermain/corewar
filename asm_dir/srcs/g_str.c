/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   g_str.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 09:46:49 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 17:40:41 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

const char *g_str[STR_NB] =
{
	"file too big",
	"char'.' wait for .comment or .name commands",
	"name too long",
	"comment too long",
	"indirect value should not exceed SHRT_MIN",
	"indirect value should not exceed SHRT_MAX",
	"direct value should not exceed SHRT_MIN",
	"direct value should not exceed SHRT_MAX",
	"direct value should not exceed INT_MAX",
	"direct value should not exceed INT_MIN",
	"invalid reg value",
	"missing value",
	"missing argument",
	"invalid argument",
	"invalid format",
	"invalid mnemonic",
	"bad argument type",
	"expected expression",
	"unexpected expression",
	"too many arguments",
	"file_name too long",
	"invalid file type",
	"no input file",
	"argument to '-o' is missing (expected 1 value)",
	"only one file accepted",
	"program size too big",
	"use of undeclared label",
	"label name too long",
	"bad label char",
	"unexpected label char",
	"output file have no extension ",
	"bad file extension ",
	B_BLACK "(the output file should have an " B_WHITE ".cor"
	B_BLACK " extension)\n",
	"this champion sucks ...",
	"label already set :",
	"corrupted file",
	"missing terminating '\"' character " B_BLACK
	" (do not support multi-lines names)",
	"missing terminating '\"' character " B_BLACK
	" (do not support multi-lines comments)",
	"comment already set",
	"name already set",
	"missing comment",
	"missing name",
	"missing file extension " B_BLACK
	" (should be " B_WHITE ".s"B_BLACK ")" RESET,
	"invalid option: ",
	"empty or corrupted file",
	"Player " B_WHITE "%s" RESET " : compilation " B_GREEN "OK" RESET "\n",
	"Player " B_WHITE "%s" RESET " : compilation " B_RED "FAILED" RESET "\n",
	"line | ins   opc |  oct(b)  oct | arg 1 value   | arg 2 value   "
	"| arg 3 value   | addr\n",
	"usage : ./asm [-flags] <champion.s>\n\n[ flags ]\n"
	"\t--verbose (-v) :  Print compilation information.\n"
	"\t--output  (-o) :  Define the output name.\n"
	"\t--help    (-h) :  Print this Help.\nCorewar"
	"\t© 2019 le-101   Loiberti - Rcepre - Rgermain\n"
};
