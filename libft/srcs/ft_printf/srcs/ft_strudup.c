/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 17:24:37 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/23 15:35:50 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

t_uchar	*ft_ustrdup(unsigned char *s1)
{
	t_uchar	*dest;
	size_t	len;

	len = ft_ustrlen(s1);
	if (!(dest = (unsigned char *)ft_memalloc(len + 1)))
		return (NULL);
	ft_memcpy(dest, s1, len);
	return (dest);
}

t_uchar	*ft_strudup(char *s1)
{
	t_uchar	*dest;
	int		len;

	len = ft_strlen(s1);
	if (!(dest = (unsigned char *)ft_memalloc(len + 1)))
		return (NULL);
	ft_memcpy(dest, s1, len);
	return (dest);
}

int		ft_islowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int		ft_maxlen_tab(char **tab, int index)
{
	int a;
	int b;
	int len;

	a = 0;
	len = 0;
	while (tab[a] != NULL)
	{
		b = 0;
		while (tab[a][b] != '\0')
			b++;
		if (b > len)
			len = b;
		a++;
	}
	if (index == 1)
		return (len);
	return (a);
}
