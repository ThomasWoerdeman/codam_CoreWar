/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handling_precision_width.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/07 14:43:43 by bbremer        #+#    #+#                */
/*   Updated: 2019/05/08 01:32:25 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handling_width(t_params *parsing, char **str)
{
	while (ft_strlen(*str) < (size_t)parsing->width)
		*str = ft_strjoin_s2(" ", *str);
}

void	handling_precision(t_params *parsing, char **str)
{
	if (ft_strchr("sS", parsing->type))
		*str = ft_strndup_free(*str, parsing->precision);
	if (ft_strchr("dioOuUxXp", parsing->type) && (size_t)parsing->precision >
		ft_strlen(*str))
	{
		if (ft_strchr("p", parsing->type))
			*str = ft_strsub_free(*str, 2, ft_strlen(*str) - 2);
		if (parsing->hashtag && ft_strchr("oO", parsing->type))
			parsing->precision -= 1;
		while (ft_strlen(*str) < (size_t)parsing->precision)
			*str = ft_strjoin_s2("0", *str);
		if (ft_strchr(*str, '-'))
			*str = ft_strjoin_s2("0", *str);
		if (ft_strchr("p", parsing->type))
			*str = ft_strjoin_s2("0x", *str);
	}
	else if (parsing->precision == 0 && !parsing->hashtag)
		*str = precision_is_zero(parsing, *str);
	else if (ft_strchr("xX", parsing->type) && parsing->hashtag)
	{
		ft_strdel(str);
		*str = ft_strnew(0);
	}
}

char	*precision_is_zero(t_params *parsing, char *str)
{
	char *tmp;

	if (ft_strchr("di", parsing->type) && ft_strcmp(str, "0"))
		return (str);
	else if (ft_strchr("p", parsing->type))
	{
		ft_strdel(&str);
		str = ft_strdup("0x");
	}
	else if (ft_strchr("fF", parsing->type))
	{
		tmp = ft_itoa(ft_round(ft_atof(str)));
		str = ft_strdup_free(tmp);
	}
	else
	{
		ft_strdel(&str);
		str = ft_strnew(0);
	}
	return (str);
}
