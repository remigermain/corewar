/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/10 16:13:24 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 10:59:00 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "colors.h"
# include "gnl.h"
# include "ft_options.h"
# include "limits.h"

# define WHITESPACES "\t \f\n\v\r"
# define DIGITS "0123456789"

typedef unsigned long long t_uint64;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*nxt;
}					t_list;

int					ft_abs(int nb);
int					get_next_line(const int fd, char **line);
int					ft_options(char *str, int instruction);
void				ft_option_error(char c, char *name, char *valids);
char				ft_options_encode(char **av, int ac, char *valids);
unsigned int		ft_reverse_uint_bytes(unsigned int nb);
unsigned int		ft_reverse_ushort_bytes(unsigned int nb);

/*
****************************** DISPLAY *****************************************
*/
void				ft_putchar(char c);
void				ft_putnbr(int nb);
void				ft_putstr_fd(char const *s, int fd);
int					ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstrlst(t_list *lst, char c);
void				ft_putdbstr(char **dbstr, char c);
void				ft_puttab(int *tab, int size);
void				ft_putcolor(char *s, int type, int color);
int					ft_lllen(long long n, int base);
int					ft_ulllen(unsigned long long n, unsigned long long base);

/*
******************************** READ ******************************************
*/
char				ft_getchar(void);

/*
****************************** CONVERT *****************************************
*/
char				*ft_itoa(int n);
char				*ft_lltoa(long long int n);
char				*ft_ulltoa(size_t n, unsigned int base);
int					ft_atoi(const char *str);

/*
****************************** STRINGS *****************************************
*/
char				*ft_strrev(char *str);
char				ft_strlastchr(char *str);
long				ft_strtol(char *s, char **endptr, int base);
size_t				ft_strspn(const char *str1, const char *str2);
size_t				ft_strcspn(const char *s1, const char *s2);
char				*ft_strstr(const char *s, const char *needle);
char				*ft_strnstr(const char *s, const char *needle, size_t len);
char				*ft_strchr(const char *s, int c);
int					ft_strchri(char *s, char c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnew(size_t size);
char				*ft_strrcpy(char *dest, const char *src);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striter(char *s, void (*f)(char *));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnjoin(char const *s1, char const *s2, int n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strcat(char *dest, const char *src);
size_t				ft_strlen(const char *s);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_strclr(char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
void				ft_striter(char *s, void (*f)(char *));
char				*ft_strncpy(char *dest, const char *src, size_t n);
void				ft_strdel(char **as);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strupcase(char *str);
char				*ft_strlowcase(char *str);
int					ft_strcountwords(const char *s, char c);
char				*ft_strfsub(char **s, unsigned int start, size_t len);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_iswhitespace(int c);
int					ft_strvalids(char *str, char *valids);
char				ft_str_is_digit(char *str);

/*
******************************* MEMORY *****************************************
*/
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_realloc(void *ptr, size_t size);
void				ft_freedbtab(void **tab);

/*
******************************** OTHER *****************************************
*/
void				ft_sorttab(int *tab, int size);

/*
******************************** PRINTF*****************************************
*/
int					ft_stprintf(char ind, const char *str, ...);
int					ft_dprintf(int fd, const char *str, ...);
int					ft_sprintf(unsigned char **dest, const char *format, ...);
int					ft_vaprintf(const char *str, va_list va);
int					ft_printf(const char *format, ...);

#endif
