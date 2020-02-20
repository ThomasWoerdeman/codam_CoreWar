/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   support_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/07 14:40:37 by bbremer        #+#    #+#                */
/*   Updated: 2019/05/08 00:23:48 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	switching(char **str)
{
	int i;

	i = 0;
	while (str[0][i] && str[0][i] != '0' && str[0][i] != '-')
		i++;
	if (i != (int)ft_strlen(str[0]))
		str[0][i] = '-';
	i++;
	while (str[0][i] && str[0][i] != '-')
		i++;
	if (i != (int)ft_strlen(str[0]))
		str[0][i] = '0';
}

int		print_null_character(char *str, t_params *parsing)
{
	int ret;

	if (parsing->minus)
		handling_minus(parsing, &str);
	if (parsing->width && (!parsing->zero || !parsing->minus))
	{
		parsing->width--;
		handling_width(parsing, &str);
	}
	ret = ft_putstr_int(str);
	print_null();
	return (ret + 1);
}

int		initialise_printf(char *str, char *fmt, t_params *parsing)
{
	int		ret;
	char	*tmp;

	ret = 0;
	if (str > fmt)
	{
		tmp = ft_strndup(fmt, str - fmt);
		ret += ft_putstr_int(tmp);
		ft_strdel(&tmp);
	}
	initialise_varargs(parsing);
	getting_flags(str + 1, parsing);
	setting_error(parsing);
	return (ret);
}

int		get_specifiers(va_list ap, t_params *parsing)
{
	int ret;

	ret = 0;
	if (ft_strchr("%cCpoOZR", (int)parsing->type))
		ret += get_specifier(ap, parsing);
	else if (ft_strchr("sS", (int)parsing->type))
		ret += get_specifier_string(ap, parsing);
	else if (ft_strchr("xXuUdifFD", (int)parsing->type))
		ret += get_specifier_numbers(ap, parsing);
	return (ret);
}

void	handling_dot(char **str, t_params *parsing)
{
	if (parsing->dot && ft_strchr("sSdioOuUxXfFp", parsing->type))
	{
		if (parsing->precision > 0 || !ft_strchr("sS", parsing->type))
			handling_precision(parsing, str);
		else
		{
			ft_strdel(str);
			*str = ft_strnew(0);
		}
	}
}
