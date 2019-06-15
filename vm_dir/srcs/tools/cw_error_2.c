/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cw_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 15:24:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 21:47:43 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
**-----------------------------------------------------------------------
** print error message and show where it is then free struct and exit
**-----------------------------------------------------------------------
*/

void		cw_error_argv(t_argm *argm)
{
	int total;
	int error_s;
	int error_e;
	int i;

	i = 0;
	total = 0;
	error_s = 0;
	error_e = 0;
	ft_dprintf(2, "     " RESET);
	while (argm->argv[i])
	{
		if (i == argm->i && (error_s = total))
			ft_dprintf(2, B_RED);
		total += ft_dprintf(2, " %s", argm->argv[i]);
		if (i == argm->i)
			error_e = total - error_s - 2;
		ft_dprintf(2, RESET);
		i++;
	}
	if (argm->i == i)
		error_s = total;
	if (error_s)
		ft_dprintf(2, "\n%*c^%*@\n", error_s + 6, ' ', error_e, "char", '~');
}

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
