/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlastchr.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/03 12:22:00 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 16:01:44 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	ft_strlastchr(char *str)
{
	char	*tmp;

	tmp = ft_strdup(str);
	tmp = ft_strrev(tmp);
	return (tmp[ft_strspn(tmp, WHITESPACES)]);
}
