/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input_utils.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 06:23:23 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 16:40:47 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

char	*get_ext(char *str)
{
	char	*ext;

	ext = NULL;
	if (!str || !ft_strchr(str, '.'))
		return (NULL);
	ext = ft_strrchr(str, '.');
	if (ft_strchr(ext, '/'))
		return (NULL);
	else
		return (ext);
}

char	*get_basename(char *str)
{
	char	*ext;

	ext = NULL;
	if (!str || !ft_strchr(str, '/'))
		return (str);
	ext = ft_strrchr(str, '/') + 1;
	return (ext);
}

void	check_ext(int i, char **av)
{
	if (get_ext(av[i + 1]) == NULL)
	{
		put_error(NULL, -1, ERR_OUT_NOEXT, PE_WARN | PE_NONL);
		ft_printf(ERR_OUT_NO_EXT_D);
	}
	else if (ft_strcmp(get_ext(av[i + 1]), ".cor"))
	{
		put_error(NULL, -1, ERR_OUT_BADEXT, PE_WARN | PE_NONL);
		ft_printf(B_BLACK "(the output file should have an \
" B_WHITE ".cor" B_BLACK " extension)\n" RESET);
	}
}
