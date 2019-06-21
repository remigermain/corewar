/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   corewar_enum.h                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 11:10:55 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/17 13:56:08 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef COREWAR_ENUM_H
# define COREWAR_ENUM_H
# define V_MO	63

typedef unsigned char	t_bool;

/*
**-----------------------------------------------------------------------
**			enum cw flags
**-----------------------------------------------------------------------
*/
enum	e_flags
{
	CW_VISU,
	CW_VISU_AN,
	CW_VERBO,
	CW_VERBO_S,
	CW_DUMP,
	CW_DUMP_C,
	CW_V0 = 7,
	CW_V1 = 8,
	CW_V2 = 9,
	CW_V4 = 10,
	CW_V8 = 11,
	CW_V16 = 12,
	CW_F_AFF,
	CW_DIFF,
};

/*
**-----------------------------------------------------------------------
**			enum instruction
**-----------------------------------------------------------------------
*/
enum	e_inst
{
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
**			enum flags for convervalue
**-----------------------------------------------------------------------
*/
enum	e_conv {
	CW_P1 = 0b001,
	CW_P2 = 0b010,
	CW_P3 = 0b100,
	CW_P12 = 0b011,
	CW_P13 = 0b101,
	CW_P23 = 0b110,
	CW_P123 = 0b111,
};

/*
**-----------------------------------------------------------------------
**			enum error parse
**-----------------------------------------------------------------------
*/
enum	e_error
{
	CW_UNK_FLAG,
	CW_WRONG_NUMBER_PLAYER,
	CW_WRONG_NUMBER_DUMP,
	CW_WRONG_NUMBER_VISU,
	CW_WRONG_NUMBER_VERBO,
	CW_WRONG_NO_NUMBER_DUMP,
	CW_OPEN,
	CW_FILE_COR,
	CW_WTF,
	CW_CHAMP_SIZE,
	CW_PROG_SIZE,
	CW_WRONG_FILE,
	CW_WRONG_FILE_MISSING,
	CW_WRONG_PROG_SIZE,
	CW_WRONG_HEADER_SIZE,
	CW_WRONG_MAGIC,
	CW_WRONG_PLAYER,
	CW_ERROR_MISS_SIZE,
	CW_ERROR_BAD_SIZE,
	CW_TO_MANY_PLAYER,
	CW_NO_PLAYER,
	CW_DEF_CYCLEDIE,
	CW_DEF_DELTA,
	CW_DEF_NBR_LIVE,
	CW_DEF_MAX_CHECKS,
	CW_DEF_NAME_LENGTH,
	CW_DEF_COMMENT_LENGTH,
	CW_DEF_MAX_ARGS_NUM,
	CW_DEF_MAX_PLAYERS,
	CW_DEF_MAX_ARGS_PLAYERS,
	CW_DEF_REG_NUM,
	CW_DEF_REG_SIZE,
	CW_DEF_IDX_MOD,
	CW_DEF_CHAMP,
	CW_DEF_RD,
	CW_DEF_RI,
	CW_DEF_ID,
	CW_NEED_VISU,
	CW_NEED_VERBO,
	CW_NEED_DUMP,
	CW_NUM_H,
	CW_NUM_L,
};

/*
**-----------------------------------------------------------------------
**			warnning run time
**-----------------------------------------------------------------------
*/
enum	e_warning
{
	SDL_PLAY_CHAN,
	SDL_LOAD_SAM,
	SDL_RENDER_CLEAR,
	SDL_LOAD_BMP,
	SDL_CREATE_TEXT,
};

/*
**-----------------------------------------------------------------------
**			enum error run time
**-----------------------------------------------------------------------
*/
enum	e_error_r
{
	CW_MALLOC,
	SDL_INIT,
	CW_MALLOC_R,
	SDL_TTF_INIT,
	SDL_TTF_OPEN,
	SDL_OPEN_AUDIO,
	SDL_CREATE_WIN,
	SDL_SDL_QUIT,
};

/*
**-----------------------------------------------------------------------
**			enum for sdl flags
**-----------------------------------------------------------------------
*/
enum	e_flags_sdl
{
	CYCLES,
	PROCESS,
	SPEED,
	MS,
	PLAYERS
};

/*
**-----------------------------------------------------------------------
**			enum for sdl player
**-----------------------------------------------------------------------
*/

enum	e_player
{
	PL1,
	PL2,
	PL3,
	PL4
};

#endif
