/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 16:58:30 by dfreire        #+#    #+#                */
/*   Updated: 2019/12/16 14:47:58 by twoerdem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
long long			ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
int					ft_numlen(long int nb);
size_t				ft_numlen_base(unsigned long int n, int base);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strjoin_s2(char *s1, char *s2);
char				*ft_strjoin_s1(char *s1, char *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(long long int n);
char				*ft_un_itoa(unsigned long long int n);
char				*ft_itoa_base(unsigned long int n, int base, char *str);
void				ft_putchar(char c);
int					ft_putchar_int(int c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
int					ft_putnbr_base(long n, char *base);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_memdup(void const *content, size_t content_size);
int					ft_whitespace(char s);
void				ft_swap(char **a, char **b);
char				*ft_caesarcipher(char const *str, int n);
char				*ft_caesarcipher_decrypt(char const *str, int n);
int					ft_sqrt(int nb);
int					ft_count_if(char **tab, int (*f)(char*));
void				ft_writeincolours(char *str, char *colour);
char				*ft_ftoa(long double f, unsigned long digits);
int					ft_putstr_int(char const *s);
void				ft_int_to_array(int *array, int size);
char				*ft_put_pointer(unsigned long long n);
void				ft_put_binary(int n);
double				ft_atof(const char *str);
long int			ft_round(double f);
double				ft_atof_singledecimal(double rez, int d, int dot_seen,
					double *fact);
char				*ft_strndup_free(char *s1, size_t n);
char				*ft_strsub_free(char *s, unsigned int start, size_t len);
char				*ft_strdup_free(char *s1);
void				ft_strarrdel(char ***arr);
int					ft_isprime(int number);
int					ft_isnumber(char *str);
size_t				ft_strlchr(char *s, int c);

#endif
