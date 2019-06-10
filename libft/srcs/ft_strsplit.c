/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 10:05:48 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 18:14:10 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		*get_word(char const *s, char c, int i)
{
	int		j;
	int		word_len;
	int		start;
	char	*word;

	j = 0;
	while (i > 0 && s[j])
	{
		word_len = 0;
		while (s[j] == c && s[j])
			j++;
		start = j;
		while (s[++j] != c && s[j])
			word_len++;
		i--;
	}
	if (!(word = ft_strsub(s, start, word_len + 1)))
		return (NULL);
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	int			nb_words;
	int			i;
	char		**tab;

	if (!s)
		return (NULL);
	nb_words = ft_strcountwords(s, c);
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (nb_words + 1))))
		return (NULL);
	i = -1;
	while (++i < nb_words)
		if (!(tab[i] = get_word(s, c, i + 1)))
		{
			ft_freedbtab((void**)tab);
			return (NULL);
		}
	tab[i] = 0;
	return (tab);
}
