/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 09:31:54 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 14:04:40 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*str;
	size_t		i;
	size_t		size;

	if (!s)
		return (NULL);
	while ((*s == ' ' || *s == '\n' || *s == '\t') && *s != '\0')
		s++;
	size = ft_strlen(s);
	i = size;
	while (i-- && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		size--;
	if (!(str = ft_strnew(size)))
		return (NULL);
	ft_strncpy(str, s, size);
	str[size] = '\0';
	return (str);
}
