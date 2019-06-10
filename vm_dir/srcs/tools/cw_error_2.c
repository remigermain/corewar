/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 15:24:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/09 18:32:38 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

void		cw_warning(int warning)
{
	ft_printf(BLUE"warning in run time: "RESET);
	if (warning == SDL_PLAY_CHAN)
		ft_printf("Mix_PlayChannel(): "WHITE"%s" WHITE, Mix_GetError());
	else if (warning == SDL_LOAD_SAM)
		ft_printf("Mix_LoadWav(): "WHITE"%s" WHITE, Mix_GetError());
	else if (warning == SDL_RENDER_CLEAR)
		ft_printf("SDL_RnderClar(): "WHITE"%s" WHITE, SDL_GetError());
	ft_printf(RESET".\n");
}

/*
**-----------------------------------------------------------------------
** display error during execution (VISU), then free and exit
**-----------------------------------------------------------------------
*/

void		cw_error_run(t_core *cw, int error, char *str)
{
	if (error != SDL_SDL_QUIT)
		ft_dprintf(2, B_RED "error in run time: " RESET);
	if (error == CW_MALLOC || error == CW_MALLOC_R)
		ft_dprintf(2, "Malloc fail from function"B_WHITE" \"%s\"", str);
	else if (error == SDL_INIT)
		ft_dprintf(2, "SDL_Init(): "RED"%s", SDL_GetError());
	else if (error == SDL_TTF_INIT)
		ft_dprintf(2, "TTF_Init(): "RED"%s", TTF_GetError());
	else if (error == SDL_TTF_OPEN)
		ft_dprintf(2, "TTF_OpenFont(): "RED"%s", TTF_GetError());
	else if (error == SDL_OPEN_AUDIO)
		ft_dprintf(2, "Mix_OpenAudio(): "RED"%s", Mix_GetError());
	else if (error == SDL_CREATE_WIN)
		ft_dprintf(2, "SDL_CreateWindowAndRenderer(): "RED"%s", SDL_GetError());
	if (error != SDL_SDL_QUIT)
		ft_dprintf(2, RESET".\n");
	if (test_bit(&(cw->utils.flags), CW_VISU) &&
			error != SDL_SDL_QUIT && error > SDL_INIT)
		quit_sdl(cw->visu, cw);
	cw_free(cw);
	exit(0);
}
