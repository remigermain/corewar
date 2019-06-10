/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/06 18:14:08 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 14:23:50 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CW_SDL_H
# define CW_SDL_H
# include "corewar.h"
# include "SDL2/SDL.h"
# include "SDL2/SDL_ttf.h"
# include "SDL2/SDL_mixer.h"

# define DIR_S "ressources_sdl/"
# define RGB_PLAY_1 0x74d3ae
# define RGB_PLAY_2 0xa6c48a
# define RGB_PLAY_3 0x8b85c1
# define RGB_PLAY_4 0xaf5d63
# define RGB_BCK 0x1e1e1e
# define RGB_INFO_TXT 0xAAEEAA
# define RGB_INFO 0x80AA80
# define RGB_LIVE 0xFFFFFF
# define RGB_JUMP 0xff82fc
# define RGB_FORK 0xf8ff38
# define RGB_COM 0x5b65a3
# define IMG_NB 1
# define IMG_COMMODORE_SCREEN "../img/purple_monitor.bmp"
# define RESIZE 8
# define LIVE_CHAN 0
# define FORK_CHAN 1
# define JUMP_CHAN 2
# define ST_CHAN 3
# define LD_CHAN 4

/*
**-----------------------------------------------------------------------
**	SDL rectangles
**-----------------------------------------------------------------------
*/

typedef struct	s_bytetab
{
	SDL_Rect	coord;
}				t_bytetab;

/*
**-----------------------------------------------------------------------
**	letters
**-----------------------------------------------------------------------
*/

typedef struct	s_letter
{
	int	l[25];
}				t_letter;

/*
**-----------------------------------------------------------------------
**	main structure
**-----------------------------------------------------------------------
*/

typedef struct	s_visu
{
	int				win_w;
	int				win_h;
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event		event;
	SDL_Rect		arena;
	SDL_Rect		info;
	SDL_Rect		info_gl[5];
	SDL_Rect		info_players[4];
	t_bytetab		bytetab[MEM_SIZE];
	int				t1;
	int				t2;
	int				speed;
	int				test;
	TTF_Font		*font;
	char			pause;
}				t_visu;
#endif
