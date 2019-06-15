/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   alphabet.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 17:01:19 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 12:18:05 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static const t_letter	*get_alphabet(void)
{
	static const t_letter alphabet[22] = {
{{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1}},
{{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1}},
{{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1}},
{{1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0}},
{{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1}},
{{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0}},
{{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1}},
{{1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1}},
{{1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1}},
{{1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0}},
{{1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1}},
{{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1}},
{{1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1}},
{{1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1}},
{{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1}},
{{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0}},
{{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1}},
{{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1}},
{{1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0}},
{{1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1}},
{{1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1}},
{{1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0}}};

	return (alphabet);
}

/*
**-----------------------------------------------------------------------
** write letter to arena
**-----------------------------------------------------------------------
*/

static void				print_letter(int letter, unsigned char *arena,
											const t_letter *alphabet, int *pos)
{
	int	i;
	int	j;
	int	l;
	int	pos_tmp;

	i = -1;
	if (letter == 'W')
		letter = 20;
	else if (letter == 'Y')
		letter = 21;
	else
		letter < 'Q' ? letter -= 65 : (letter -= 66);
	l = 0;
	while (++i < 5 && (j = -1))
	{
		pos_tmp = *pos;
		while (++j < 5)
			arena[pos_tmp + j + (l * 64)] = alphabet[letter].l[j + (l * 5)];
		l++;
	}
	*pos += 6;
}

/*
**-----------------------------------------------------------------------
** write a string to arena -> it mustn't exceed one line
**-----------------------------------------------------------------------
*/

static void				print_word(char *word, unsigned char *arena,
										const t_letter *alphabet, int nb_line)
{
	int	len;
	int	i;

	i = -1;
	len = ft_strlen(word);
	nb_line = (nb_line * 64) + (64 - ((len * 5) + len - 1)) / 2;
	while (++i < len)
		print_letter(word[i], arena, alphabet, &nb_line);
}

int						display_intro(int mod, t_visu *visu)
{
	unsigned char	arena[MEM_SIZE];
	const t_letter	*alphabet;

	ft_bzero(arena, MEM_SIZE);
	alphabet = get_alphabet();
	if (!mod)
	{
		print_word("WELCOME", arena, alphabet, 17);
		print_word("TO", arena, alphabet, 28);
		print_word("COREWAR", arena, alphabet, 39);
	}
	else
	{
		print_word("PRESENTED", arena, alphabet, 7);
		print_word("BY", arena, alphabet, 16);
		print_word("RGERMAIN", arena, alphabet, 30);
		print_word("RCEPRE", arena, alphabet, 39);
		print_word("LOIBERTI", arena, alphabet, 48);
	}
	return (up_down_animation(visu, arena, mod));
}
