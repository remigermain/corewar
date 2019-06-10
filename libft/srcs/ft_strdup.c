/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 07:38:03 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 20:04:44 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*strcpy;
	int		i;

	i = -1;
	if (!((strcpy = (char*)ft_memalloc(sizeof(char) * (ft_strlen(s) + 1)))))
		return (NULL);
	while (s[++i])
		strcpy[i] = s[i];
	strcpy[i] = '\0';
	return (strcpy);
}
