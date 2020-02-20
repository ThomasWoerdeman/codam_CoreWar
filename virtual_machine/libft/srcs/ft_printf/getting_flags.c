/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   getting_flags.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 14:12:35 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/08 00:21:49 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*length_flags(char *str, t_params *parsing)
{
	if (!ft_strncmp(str, "ll", 2))
	{
		parsing->flag = "ll";
		return (str + 1);
	}
	if (!ft_strncmp(str, "hh", 2))
	{
		parsing->flag = "hh";
		return (str + 1);
	}
	if (!ft_strncmp(str, "jh", 2))
	{
		parsing->flag = "j";
		return (str + 1);
	}
	if (!ft_strncmp(str, "zh", 2))
	{
		parsing->flag = "z";
		return (str + 1);
	}
	else if (!ft_strncmp(str, "h", 1) || !ft_strncmp(str, "l", 1) ||
	!ft_strncmp(str, "L", 1) || !ft_strncmp(str, "j", 1) ||
	!ft_strncmp(str, "z", 1))
		parsing->flag = length_single_flags(str);
	return (str);
}

char		*length_single_flags(char *str)
{
	if (!ft_strncmp(str, "h", 1))
		return ("h");
	if (!ft_strncmp(str, "l", 1))
		return ("l");
	if (!ft_strncmp(str, "L", 1))
		return ("L");
	if (!ft_strncmp(str, "j", 1))
		return ("j");
	if (!ft_strncmp(str, "z", 1))
		return ("z");
	else
		return (NULL);
}

char		*getting_flags(char *str, t_params *parsing)
{
	while (!parsing->type && *str)
	{
		if (*str == '#')
			parsing->hashtag++;
		else if (!parsing->dot && *str == '0')
			parsing->zero++;
		else if (*str == '-')
			parsing->minus++;
		else if (*str == '+')
			parsing->plus++;
		else if (*str == ' ')
			parsing->space++;
		else if (ft_strchr("sSpdDioOuUxXcCfF%ZR", (int)*str))
			parsing->type = (char)*str;
		else if (*str >= '1' && *str <= '9' && !parsing->width)
		{
			parsing->width = ft_atoi(str);
			str = str + ft_numlen(parsing->width) - 1;
		}
		else if (*str == '.')
			str = if_dot(str, &parsing);
		str = length_flags(str, parsing);
		str++;
	}
	return (str);
}

char		*if_dot(char *str, t_params **parsing)
{
	(*parsing)->dot++;
	str++;
	(*parsing)->precision = ft_atoi(str);
	if ((*parsing)->precision)
		str = str + ft_numlen((*parsing)->precision) - 1;
	else
		str = str - 1;
	return (str);
}
