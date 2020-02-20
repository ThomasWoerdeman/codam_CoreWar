/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handling_flags.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/07 14:37:04 by bbremer        #+#    #+#                */
/*   Updated: 2019/05/08 00:03:31 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handling_plus(char **str)
{
	if (!ft_strchr(*str, '-'))
		*str = ft_strjoin_s2("+", *str);
}

void	handling_space(char **str)
{
	if (**str != '-')
		*str = ft_strjoin_s2(" ", *str);
}

void	handling_hashtag(t_params *parsing, char **str)
{
	if (ft_strchr("oO", parsing->type))
		*str = ft_strjoin_s2("0", *str);
	if (ft_strchr("x", parsing->type))
		*str = ft_strjoin_s2("0x", *str);
	if (ft_strchr("X", parsing->type))
		*str = ft_strjoin_s2("0X", *str);
}

void	handling_minus(t_params *parsing, char **str)
{
	while (ft_strlen(*str) < (size_t)parsing->width)
		*str = ft_strjoin_s1(*str, " ");
}

void	handling_zero(t_params *parsing, char **str)
{
	if (parsing->dot && parsing->type == 'i')
	{
		handling_width(parsing, str);
		return ;
	}
	if (ft_strchr("p", parsing->type))
		*str = ft_strsub_free(*str, 2, ft_strlen(*str) - 2);
	while (ft_strlen(*str) < (size_t)parsing->width)
	{
		if (ft_strchr("dioOuUxX", parsing->type) && parsing->precision &&
		!ft_strchr(*str, '-'))
			*str = ft_strjoin_s2(" ", *str);
		else if (ft_strchr("p", parsing->type))
		{
			parsing->width -= 2;
			*str = ft_strjoin_s2("0", *str);
		}
		else
			*str = ft_strjoin_s2("0", *str);
	}
	if (ft_strchr("p", parsing->type))
		*str = ft_strjoin_s2("0x", *str);
}
