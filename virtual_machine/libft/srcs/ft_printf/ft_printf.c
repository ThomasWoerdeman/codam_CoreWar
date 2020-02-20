/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 10:14:26 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/07 23:49:41 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	setting_error(t_params *parsing)
{
	if (parsing->minus > 1 || parsing->zero > 1 || parsing->plus > 1 ||
		parsing->space > 1 || parsing->hashtag > 1 || parsing->dot > 1)
		parsing->flag_error = 1;
	if (ft_strchr("OUDS", (int)parsing->type) && parsing->flag)
		parsing->flag_error = 2;
	if (ft_strchr("scC", (int)parsing->type) && parsing->flag
		&& ft_strcmp(parsing->flag, "l"))
		parsing->flag_error = 3;
	if (!ft_strchr("di", (int)parsing->type) && (parsing->plus ||
		parsing->space))
		parsing->flag_error = 4;
	if (!ft_strchr("xXo", (int)parsing->type) && parsing->hashtag)
		parsing->flag_error = 5;
}

int		get_specifier_numbers(va_list ap, t_params *parsing)
{
	int ret;

	ret = 0;
	if (ft_strchr("x", (int)parsing->type))
		ret += handling_x(ap, *parsing);
	else if (ft_strchr("X", (int)parsing->type))
		ret += handling_upperx(ap, *parsing);
	else if (ft_strchr("u", (int)parsing->type))
		ret += handling_u(ap, *parsing);
	else if (ft_strchr("U", (int)parsing->type))
		ret += handling_upperu(ap, *parsing);
	else if (ft_strchr("di", (int)parsing->type))
		ret += handling_di(ap, *parsing);
	else if (ft_strchr("fF", (int)parsing->type))
		ret += handling_f(ap, *parsing);
	else if (ft_strchr("D", (int)parsing->type))
		ret += handling_upperd(ap, *parsing);
	return (ret);
}

int		get_specifier(va_list ap, t_params *parsing)
{
	int ret;

	ret = 0;
	if (ft_strchr("%", (int)parsing->type))
		ret += print_parsing(ft_strdup("%"), parsing);
	if (ft_strchr("cC", (int)parsing->type))
		ret += handling_c(ap, *parsing);
	else if (ft_strchr("p", (int)parsing->type))
		ret += handling_p(ap, *parsing);
	else if (ft_strchr("o", (int)parsing->type))
		ret += handling_o(ap, *parsing);
	else if (ft_strchr("O", (int)parsing->type))
		ret += handling_uppero(ap, *parsing);
	else if (ft_strchr("Z", (int)parsing->type))
		ret += print_parsing(ft_strdup("Z"), parsing);
	else if (ft_strchr("R", (int)parsing->type))
		ret += print_parsing(ft_strdup("R"), parsing);
	return (ret);
}

int		get_specifier_string(va_list ap, t_params *parsing)
{
	int		ret;
	char	*tmp;

	ret = 0;
	if (!parsing->flag)
	{
		tmp = va_arg(ap, char*);
		if (tmp)
			ret += print_parsing(ft_strdup(tmp), parsing);
		else
			ret += print_parsing(ft_strdup("(null)"), parsing);
	}
	else if (!ft_strcmp(parsing->flag, "l"))
	{
		tmp = (char*)va_arg(ap, wchar_t*);
		if (tmp)
			ret += print_parsing(ft_strdup(tmp), parsing);
		else
			ret += print_parsing(ft_strdup("(null)"), parsing);
	}
	return (ret);
}

int		ft_printf(const char *fmt, ...)
{
	int			ret;
	char		*str;
	t_params	parsing;
	va_list		ap;

	ret = 0;
	va_start(ap, fmt);
	str = ft_strchr(fmt, '%');
	while (str)
	{
		ret += initialise_printf(str, (char*)fmt, &parsing);
		if (checking_fmt(str))
		{
			fmt = getting_fmt(str);
			break ;
		}
		ret += get_specifiers(ap, &parsing);
		fmt = getting_rest_fmt(str, parsing);
		str = ft_strchr(fmt, '%');
	}
	if (fmt != NULL)
		ret += ft_putstr_int(fmt);
	va_end(ap);
	return (ret);
}
