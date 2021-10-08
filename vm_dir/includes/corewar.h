/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   corewar.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 16:12:52 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 11:40:09 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "op.h"
# include "corewar_enum.h"
# include "libft.h"
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <time.h>
# include "cw_colors.h"
# include "cw_sdl.h"
# define SAMPLE_NB 16
# define STEREO 2

/*
**-----------------------------------------------------------------------
**	contain instruction informations
**-----------------------------------------------------------------------
*/

typedef struct	s_inst
{
	unsigned char	op;
	unsigned char	ocp;
	int				pc;
	int				size;
	int				value[3];
	int				mem;
	t_bool			error;
}				t_inst;

/*
**-----------------------------------------------------------------------
**	arena, color and pc (visual), cycles
**-----------------------------------------------------------------------
*/

typedef struct	s_area
{
	unsigned char	arena[MEM_SIZE];
	unsigned char	color[MEM_SIZE];
	unsigned int	cycles[MEM_SIZE];
	unsigned int	pc[MEM_SIZE];
	int				cycle_to_die;
	int				cycle_total;

}				t_area;

/*
**-----------------------------------------------------------------------
**	process
**-----------------------------------------------------------------------
*/

typedef struct	s_process
{
	unsigned char		reg[REG_NUMBER][REG_SIZE];
	unsigned char		op;
	unsigned			carry : 1;
	int					live;
	int					live_cycle;
	int					cycle_instruction;
	short				pc;
	size_t				number;
	int					player;
}				t_process;

/*
**-----------------------------------------------------------------------
**	each players have is own, contain every informations about it
**-----------------------------------------------------------------------
*/

typedef struct	s_player
{
	unsigned char	inst[CHAMP_MAX_SIZE + 1];
	t_header		data;
	char			*name_file;
	int				number;
	int				start;
	int				nb_process;
	int				nb_live;
}				t_player;

/*
**-----------------------------------------------------------------------
**	structure to parse arguments
**-----------------------------------------------------------------------
*/

typedef	struct	s_argm
{
	char	**argv;
	int		argc;
	int		error;
	int		i;
	int		j;
}				t_argm;

/*
**-----------------------------------------------------------------------
**	flags structure
**-----------------------------------------------------------------------
*/

typedef struct	s_flags
{
	int	flags;
	int	speed;
	int	dump_cycle;
	const char *screen;
}				t_flags;

/*
**-----------------------------------------------------------------------
**	main structure
**-----------------------------------------------------------------------
*/

typedef struct	s_core
{
	const t_op		*tab;
	int				nb_player;
	int				last_live;
	int				total_process;
	int				len_process;
	int				total_live;
	int				fork;
	t_flags			utils;
	t_player		player[MAX_PLAYERS];
	t_area			vm;
	t_process		*process;
	Mix_Chunk		*samples[SAMPLE_NB];
	t_visu			*visu;
}				t_core;

void			cw_vm(t_core *cw, t_visu visu);

/*
**-----------------------------------------------------------------------
**  		SDL function
**			init sdl, display intro/outro and animations,
**			texts, arena, play sounds...
**			cw_sdl****.c
**-----------------------------------------------------------------------
*/
void			open_images(t_visu *visu);
void			handle_events(t_visu *visu, t_core *cw);
void			clear_screen(t_visu *visu);
void			quit_sdl(t_visu *visu, t_core *cw);
void			update_win_size(t_visu *visu, t_core *cw, int todo);
void			put_frame_rect(t_visu *visu, SDL_Rect *rect, int color);
void			update_bytes_pos(t_visu *visu);
void			init_sdl(t_core *cw, t_visu *visu);
void			put_info_gl(t_visu *visu, t_core *cw, int cyles);
void			put_info_gl_end(t_visu *visu, t_core *cw);
void			put_info_players(t_visu *visu, t_core *cw);
void			color_translate(int base, SDL_Color *color);
void			put_fill_rect(t_visu *visu, SDL_Rect *rect, int color);
void			put_fill_rect_prog(t_visu *visu, t_core *cw, int pc);
void			put_dot(t_visu *visu, SDL_Rect *rect, int color);
void			put_text(t_visu *visu, SDL_Rect rect, char *str, int color);
void			put_bytes(t_visu *visu, t_core *cw);
void			put_one_byte(t_visu *visu, t_core *cw, int i);
void			sdl_intro(t_core *cw, t_visu *visu);
void			sdl_outro(t_core *cw, t_visu *visu, int mod);
int				display_intro(int mod, t_visu *visu);
int				display_outro(t_visu *visu);
int				left_right_animation(t_visu *visu, unsigned char *a);
int				up_down_animation(t_visu *visu, unsigned char *a, int mod);
int				diagonal_animation(t_visu *visu, t_core *cw, int mod, int k);
void			play_sample(t_core *cw, int indice, int channel);
void			handle_time(t_visu *visu);
void			put_winner(t_core *cw, t_visu *visu);
void			play_fork(t_core *cw);
void			play_st(t_core *cw);
void			play_ld(t_core *cw);
void			play_live(t_core *cw, int head);
void			play_jump(t_core *cw, int head);
void			load_samples(t_core *cw);
void			put_background(t_visu *visu);
void			update_bytes_pos(t_visu *visu);
void			update_info_gl(t_visu *visu);
void			update_info_players(t_visu *visu, t_core *cw);
void			get_mouse(t_visu *visu, t_core *cw);
/*
**-----------------------------------------------------------------------
**  		init flags , check define , init player
**			cw_process.c
**-----------------------------------------------------------------------
*/
void			cw_flags(t_core *cw, t_argm *argm);
t_bool			cw_isflags(char *str);
t_bool			cw_is_champ(char *str);
void			get_screen_size(t_core *cw, t_argm *argm, t_visu *visu);
void			cw_flags_visu(t_core *cw, t_argm *argm);
void			cw_flags_verbo(t_core *cw, t_argm *argm);
void			cw_flags_dump(t_core *cw, t_argm *argm);
void			put_player(t_core *cw, t_argm *argm);
void			cw_check_define(t_argm *cw);
void			cw_initplayer(t_core *cw);

/*
**-----------------------------------------------------------------------
**			processus execute, add, remove
**			cw_process.c
**-----------------------------------------------------------------------
*/
void			remove_process(t_core *cw);
void			add_process(t_core *cw, t_process *fork, t_inst *inst);
void			covered_process(t_core *cw);

/*
**-----------------------------------------------------------------------
**			instruction
**			cw_instruction [1 && 2 && 3] .c
**-----------------------------------------------------------------------
*/
t_bool			live(t_core *cw, t_inst *inst, t_process *p);
t_bool			st(t_core *cw, t_inst *inst, t_process *p);
t_bool			sti(t_core *cw, t_inst *inst, t_process *p);
t_bool			ld(t_core *cw, t_inst *inst, t_process *p);
t_bool			ldi(t_core *cw, t_inst *inst, t_process *p);
t_bool			add(t_core *cw, t_inst *inst, t_process *p);
t_bool			sub(t_core *cw, t_inst *inst, t_process *p);
t_bool			and(t_core *cw, t_inst *inst, t_process *p);
t_bool			or(t_core *cw, t_inst *inst, t_process *p);
t_bool			xor(t_core *cw, t_inst *inst, t_process *p);
t_bool			ffork(t_core *cw, t_inst *inst, t_process *p);
t_bool			aff(t_core *cw, t_inst *inst, t_process *p);
t_bool			zjmp(t_core *cw, t_inst *inst, t_process *p);

/*
**-----------------------------------------------------------------------
**			instruction main
**			cw_read_instruction.c && cw_execute_instruction.c
**-----------------------------------------------------------------------
*/
void			launch_instruction(t_core *cw, t_process *p);
int				next_inst(t_core *cw, t_process *p);
t_bool			execute_instruction(t_core *cw, t_process *p, t_inst *param);
t_bool			convert_value(t_core *cw, t_process *p, t_inst *inst,
		enum e_conv conv);
void			less_cycle(t_core *cw, t_process *origi);

/*
**-----------------------------------------------------------------------
**  		instruction tools
**			cw_instructions_tools.c
**-----------------------------------------------------------------------
*/
t_bool			put_reg(t_core *cw, t_process *p, int i_reg, int value);
void			put_arena(t_core *cw, t_process *pro, int i_are, int value);
int				convert_adress(t_process *p, t_inst *inst, int add);
void			mod_carry(int param, t_process *p);
int				i_pc(int dest);

/*
**-----------------------------------------------------------------------
**  		bit tools
**			tools_bits.c
**-----------------------------------------------------------------------
*/
t_bool			test_bit(int *st, int i);
void			set_bit(int *st, int i);
void			clear_bit(int *st, int i);
int				add_bytes(unsigned char *str, int i, int mod);
int				binary_shift(int param);

/*
**-----------------------------------------------------------------------
**  		utils
**			utils.c
**-----------------------------------------------------------------------
*/
void			print_arena(t_core *cw);
int				find_player(t_core *cw, int i);
int				registre_player(t_core *cw, t_process *origi);

/*
**-----------------------------------------------------------------------
**  		verbose function
**			utils.c
**-----------------------------------------------------------------------
*/
void			display_vw(t_core *cw);
void			display_foot(t_core *cw, t_process *p, t_inst *inst);
void			display_head(t_core *cw, t_process *p, t_inst *inst);
void			display_args(t_core *cw, t_process *p, t_inst *inst);
void			remove_process_verbose(t_core *cw, t_process *p);
void			cycle_verbose(t_core *cw);
void			introducing_player_verbose(t_core *cw);
void			diff_sti(t_core *cw, t_inst *inst, t_process *pr, int mem);
void			diff_ldi(t_core *cw, t_inst *inst, t_process *process);
void			diff_fork(t_core *cw, t_inst *inst, t_process *process);
void			diff_base(t_core *cw, t_process *p, t_inst *inst, int mem);

/*
**-----------------------------------------------------------------------
**  		error corewar
**			cw_error.c
**-----------------------------------------------------------------------
*/
void			cw_error(t_core *cw, t_argm *argm, enum e_error er, char *str);
void			cw_error_run(t_core *cw, enum e_error_r err, char *str);
void			cw_warning(enum e_warning warning);
void			cw_error_argv(t_argm *argm);

/*
**-----------------------------------------------------------------------
**  		utils function
**			utils_funct.c
**-----------------------------------------------------------------------
*/
void			cw_free(t_core *cw);
const t_op		*get_op_tab();
#endif
