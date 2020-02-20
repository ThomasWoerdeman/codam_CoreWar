/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   getting_fmt.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 14:27:10 by bbremer        #+#    #+#                */
/*   Updated: 2019/05/08 00:43:44 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*getting_fmt(char *str)
{
	if (!ft_whitespace(str[1]) && str[1] != 's' && str[1] != 'S' &&
	str[1] != 'p' && str[1] != ' ' && str[1] != '1' && str[1] != '2' &&
	str[1] != '3' && str[1] != '4' && str[1] != '5' && str[1] != '6' &&
	str[1] != '7' && str[1] != '8' && str[1] != '9' && str[1] != 'L' &&
	str[1] != 'd' && str[1] != 'D' && str[1] != 'i' && str[1] != 'o' &&
	str[1] != 'O' && str[1] != 'u' && str[1] != 'U' && str[1] != 'x' &&
	str[1] != 'X' && str[1] != 'c' && str[1] != 'C' && str[1] != 'f' &&
	str[1] != 'F' && str[1] != '%' && str[1] != 'Z' && str[1] != '0' &&
	str[1] != '-' && str[1] != '+' && str[1] != '#' && str[1] != 'h' &&
	str[1] != 'l' && str[1] != '.' && str[1] != 'j' && str[1] != 'z')
	{
		return (str + 1);
	}
	return (NULL);
}

int		checking_fmt(char *str)
{
	if (!ft_whitespace(str[1]) && str[1] != 's' && str[1] != 'S' &&
	str[1] != 'p' && str[1] != ' ' && str[1] != '1' && str[1] != '2' &&
	str[1] != '3' && str[1] != '4' && str[1] != '5' && str[1] != '6' &&
	str[1] != '7' && str[1] != '8' && str[1] != '9' && str[1] != 'L' &&
	str[1] != 'd' && str[1] != 'D' && str[1] != 'i' && str[1] != 'o' &&
	str[1] != 'O' && str[1] != 'u' && str[1] != 'U' && str[1] != 'x' &&
	str[1] != 'X' && str[1] != 'c' && str[1] != 'C' && str[1] != 'f' &&
	str[1] != 'F' && str[1] != '%' && str[1] != 'Z' && str[1] != '0' &&
	str[1] != '-' && str[1] != '+' && str[1] != '#' && str[1] != 'h' &&
	str[1] != 'l' && str[1] != '.' && str[1] != 'j' && str[1] != 'z')
		return (1);
	return (0);
}

char	*getting_rest_fmt(char *str, t_params parsing)
{
	char	*fmt;
	int		i;

	i = 0;
	while (str[i] && !ft_strchr(("sSpdDioOuUxXcCfFZR"), (int)str[i]))
		i++;
	if (ft_strstr(str, "%%"))
		fmt = ft_strstr(str, "%%") + 2;
	else if (parsing.type == 37)
		fmt = ft_strchr((str + 1), 37);
	else if (ft_strchr("%", (int)parsing.type))
		fmt = str + i;
	else
		fmt = str + i + 1;
	return (fmt);
}
