/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 10:02:07 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/22 10:23:27 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

# define TYPE_X "0123456789abcdef"
# define UPPER_X "0123456789ABCDEF"

typedef struct	s_params
{
	int			hashtag;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			dot;
	int			width;
	int			precision;
	char		type;
	char		*flag;
	int			flag_chart;
	int			flag_error;
	void		*options;
	char		*str;
}				t_params;

void			setting_error(t_params *parsing);
void			initialise_varargs(t_params *parsing);
char			*getting_flags(char *str, t_params *parsing);
int				get_specifiers(va_list ap, t_params *parsing);
int				get_specifier_numbers(va_list ap, t_params *parsing);
int				get_specifier_string(va_list ap, t_params *parsing);
int				get_specifier(va_list ap, t_params *parsing);
char			*length_single_flags(char *str);
int				checking_fmt(char *str);
void			checking_flags(char **str, t_params *parsing);
char			*getting_fmt(char *str);
char			*getting_rest_fmt(char *str, t_params parsing);
void			handling_hashtag(t_params *parsing, char **str);
void			handling_width(t_params *parsing, char **str);
void			handling_zero(t_params *parsing, char **str);
void			handling_minus(t_params *parsing, char **str);
void			handling_plus(char **str);
void			handling_space(char **str);
void			handling_precision(t_params *parsing, char **str);
int				handling_null_c(char *str, t_params *parsing);
void			handling_zero_numbers(char **str, t_params **parsing);
void			handling_zero_flags(char **str, t_params **parsing);
void			handling_dot(char **str, t_params *parsing);
int				initialise_printf(char *str, char *fmt, t_params *parsing);
char			*precision_is_zero(t_params *parsing, char *str);
void			switching(char **str);
int				print_parsing(char *str, t_params *parsing);
int				print_null_character(char *str, t_params *parsing);
char			*ctostr(char c);
char			*if_dot(char *str, t_params **parsing);
void			print_null();
int				handling_c(va_list ap, t_params parsing);
int				handling_o(va_list ap, t_params parsing);
int				handling_uppero(va_list ap, t_params parsing);
int				handling_x(va_list ap, t_params parsing);
int				handling_upperx(va_list ap, t_params parsing);
int				handling_u(va_list ap, t_params parsing);
int				handling_upperu(va_list ap, t_params parsing);
int				handling_di(va_list ap, t_params parsing);
int				handling_upperd(va_list ap, t_params parsing);
int				handling_f(va_list ap, t_params parsing);
int				handling_p(va_list ap, t_params parsing);
int				ft_printf(const char *fmt, ...);

#endif
