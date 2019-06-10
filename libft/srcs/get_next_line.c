/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 14:22:36 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 15:41:20 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int			extract_line(char **line, char **rest)
{
	int		i;

	i = 0;
	while ((*rest)[i] != '\0' && (*rest)[i] != '\n')
		i++;
	if (!(*line = ft_strsub(*rest, 0, i)))
		return (-1);
	if (!(*rest = ft_strfsub(rest, i + 1, ft_strlen(*rest) - i)))
		return (-1);
	return (0);
}

int					all_free(int ret, char **line, char *rest)
{
	if (ret == 0 && !**line)
	{
		free(*line);
		free(rest);
		return (0);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*rest = NULL;
	char			buf[BUFF_SIZE];
	char			*tmp;

	ret = 1;
	if (fd < 0 || line == NULL)
		return (-1);
	while ((!rest || !ft_strrchr(rest, '\n')) && ret)
	{
		tmp = rest;
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		if (ret == -1 || !(rest = ft_strnjoin(rest, buf, ret)))
			return (-1);
		if (rest && tmp)
			free(tmp);
	}
	if (extract_line(line, &rest) == -1)
		return (-1);
	if (!all_free(ret, line, rest))
		return (0);
	return (1);
}
