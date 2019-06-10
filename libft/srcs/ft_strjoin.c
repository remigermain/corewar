/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 07:02:10 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 16:59:17 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	char	*str;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(str = (char*)ft_memalloc(sizeof(char) * (l1 + l2) + 1)))
		return (NULL);
	l1 = 0;
	while (s1[l1])
		str[i++] = s1[l1++];
	l2 = 0;
	while (s2[l2])
		str[i++] = s2[l2++];
	str[i] = '\0';
	return (str);
}
