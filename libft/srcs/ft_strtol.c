/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtol.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 16:41:48 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 09:32:56 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		convert(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	return (c - '0');
}

static int		is_valid(char c, int base)
{
	if ((c >= '0' && c <= base - 1 + '0') \
									|| (c >= 'A' && c <= base - 11 + 'A')
									|| (c >= 'a' && c <= base - 11 + 'a'))
		return (1);
	return (0);
}

static int		check_base(char **s, int base)
{
	if (**s == '0' && *(*s + 1) == 'x' && base == 0)
	{
		*s += 2;
		return (16);
	}
	if (**s == '0' && base == 0)
		return (8);
	return (base == 0 ? 10 : base);
}

static long		extract(char **s, int base, int *len)
{
	int res;

	res = 0;
	*len = 0;
	while (**s == '0')
		*s += 1;
	while (is_valid(**s, base))
	{
		res = res * base + convert(**s);
		*s += 1;
		*len += 1;
	}
	return (res);
}

long			ft_strtol(char *s, char **endptr, int base)
{
	long	res;
	char	neg;
	char	*tmp;
	int		len;
	char	*bidule;

	tmp = s;
	res = 0;
	if (endptr == NULL)
		endptr = &bidule;
	*endptr = "";
	if (base < 0 || base > 32 || base == 1)
		return (0);
	while (ft_iswhitespace(*s))
		s++;
	neg = *s == '-' ? 1 : 0;
	if (*s == '-' || *s == '+')
		s++;
	base = check_base(&s, base);
	res = extract(&s, base, &len);
	if (!is_valid(*s, base) && *s != '\0')
		*endptr = s - 1 == tmp ? tmp : s;
	if ((len == 19 && (*(s - 1) > '6' + neg || *(s - 2) > '0')) || len > 19)
		return (neg == 1 ? -9223372036854775807 : FT_LONG_MAX);
	return (neg == 1 ? -res : res);
}
