/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_parsed_values.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/07 13:15:55 by bbremer        #+#    #+#                */
/*   Updated: 2019/05/08 00:03:21 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handling_null_c(char *str, t_params *parsing)
{
	int ret;

	ret = 0;
	if (parsing->zero)
	{
		parsing->width -= 1;
		handling_zero(parsing, &str);
	}
	ret = print_null_character(str, parsing);
	return (ret);
}

void	checking_flags(char **str, t_params *parsing)
{
	if (parsing->plus && ft_strchr("difF", parsing->type))
		handling_plus(str);
	if (parsing->hashtag && ft_strchr("oOxXsSpfF", parsing->type) &&
		ft_strlen(*str) > 0 && ft_strcmp(*str, "0"))
		handling_hashtag(parsing, str);
	if (parsing->minus)
		handling_minus(parsing, str);
	if (parsing->width && (!parsing->zero || !parsing->minus))
		handling_width(parsing, str);
	if (ft_strchr("difF", parsing->type) && ft_strchr(*str, '-') &&
		(parsing->zero || parsing->dot))
		switching(str);
}

void	handling_zero_numbers(char **str, t_params **parsing)
{
	if ((*parsing)->zero && !(*parsing)->minus && !(*parsing)->hashtag &&
	ft_strchr("di", (*parsing)->type))
	{
		if ((*parsing)->hashtag && ft_strchr("xX", (*parsing)->type) &&
		(*parsing)->width > 2)
			(*parsing)->width -= 2;
		if ((*parsing)->plus && !ft_strchr(*str, '-') && (*parsing)->width > 0)
			(*parsing)->width -= 1;
		if ((*parsing)->space && (*parsing)->width > 0)
			(*parsing)->width -= 1;
		handling_zero((*parsing), str);
		if ((*parsing)->space)
			handling_space(str);
	}
}

void	handling_zero_flags(char **str, t_params **parsing)
{
	if ((*parsing)->zero && !(*parsing)->minus && ft_strchr("oOuUxXfF%sScCpZ",
	(*parsing)->type))
	{
		if ((*parsing)->hashtag && ft_strchr("xX", (*parsing)->type) &&
		(*parsing)->width > 2)
			(*parsing)->width -= 2;
		if ((*parsing)->plus && !ft_strchr(*str, '-'))
			(*parsing)->width -= 1;
		handling_zero((*parsing), str);
	}
}

int		print_parsing(char *str, t_params *parsing)
{
	int ret;

	ret = 0;
	if (parsing->type == 0)
		return (ret);
	if (ft_strchr("cC", parsing->type) && str[0] == '\0')
	{
		ret = handling_null_c(str, parsing);
		return (ret);
	}
	handling_dot(&str, parsing);
	if (parsing->space && !parsing->zero && !parsing->plus &&
	ft_strchr("difF", parsing->type))
		handling_space(&str);
	handling_zero_flags(&str, &parsing);
	handling_zero_numbers(&str, &parsing);
	checking_flags(&str, parsing);
	if (str)
		ret = ft_putstr_int(str);
	ft_strdel(&str);
	return (ret);
}
