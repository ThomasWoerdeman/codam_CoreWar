/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handling_f.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/08 15:56:14 by bbremer        #+#    #+#                */
/*   Updated: 2019/05/08 10:31:20 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handling_f(va_list ap, t_params parsing)
{
	int		ret;
	char	*s1;
	int		digits;

	ret = 0;
	digits = 6;
	if (parsing.dot)
	{
		if (parsing.precision)
			digits = parsing.precision;
		else
			digits = 1;
	}
	s1 = NULL;
	if (!parsing.flag || ft_strcmp(parsing.flag, "l") == 0)
		s1 = ft_ftoa(va_arg(ap, double), digits);
	else if (ft_strcmp(parsing.flag, "L") == 0)
		s1 = ft_ftoa(va_arg(ap, long double), digits);
	if (s1)
		ret = print_parsing(s1, &parsing);
	return (ret);
}
