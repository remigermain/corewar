/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_sdl.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/06 18:14:08 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/17 19:00:02 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CW_SDL_H
# define CW_SDL_H
#  include "corewar.h"
# ifdef __linux__
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_ttf.h>
#  include <SDL2/SDL_mixer.h>
# else
#  include "SDL2/SDL.h"
#  include "SDL2/SDL_ttf.h"
#  include "SDL2/SDL_mixer.h"
# endif
# define DIR_S "ressources_sdl/"
# define SCREEN(cw, value) ((value / 4) * visu->screen.coef)
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
# define IMG_COMMODORE_4k_BASE "ressources_sdl/background_4k.bmp"
# define IMG_COMMODORE_4k_LIGHT "ressources_sdl/background_4k_light.bmp"
# define IMG_COMMODORE_4k_GRAPH "ressources_sdl/background_4k_graph.bmp"
# define IMG_COMMODORE_1080_BASE "ressources_sdl/background_1080.bmp"
# define IMG_COMMODORE_1080_LIGHT "ressources_sdl/background_1080_light.bmp"
# define IMG_COMMODORE_1080_GRAPH "ressources_sdl/background_1080_graph.bmp"
# define RESIZE 8
# define LIVE_CHAN 0
# define FORK_CHAN 1
# define JUMP_CHAN 2
# define ST_CHAN 3
# define LD_CHAN 4
# define GR_POWER_1	1915
# define GR_POWER_2	1970
# define GR_POWER_3	1170
# define GR_POWER_4	1970
# define CO_POWER_1	1925
# define CO_POWER_2	1978
# define CO_POWER_3	1163
# define CO_POWER_4	1194
# define CO_LIGHT_1	15
# define CO_LIGHT_2	75
# define CO_LIGHT_3	110
# define CO_LIGHT_4	140
# define CO_MU_1 280
# define CO_MU_2 320
# define CO_MU_3 1120
# define CO_MU_4 1150

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
**	screen structure
**-----------------------------------------------------------------------
*/

typedef struct s_screen
{
	char *base;
	char *light;
	char *graph;
	int coef;
}				t_screen;


/*
**-----------------------------------------------------------------------
**	main structure
**-----------------------------------------------------------------------
*/

typedef struct	s_visu
{
	t_screen		screen;
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
	int				refresh;
	int				step;
	TTF_Font		*font;
	char			pause;
	char			sound;
	char			mod_back;
	char			light;
	char			responsive_mode;
	SDL_Texture		*background;
}				t_visu;
#endif
