/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handling_di.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/24 10:46:18 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/07 22:50:27 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handling_di(va_list ap, t_params parsing)
{
	int		ret;
	char	*s1;

	ret = 0;
	s1 = NULL;
	if (!parsing.flag)
		s1 = ft_itoa(va_arg(ap, int));
	else if (ft_strcmp(parsing.flag, "l") == 0)
		s1 = ft_itoa(va_arg(ap, long int));
	else if (ft_strcmp(parsing.flag, "ll") == 0)
		s1 = ft_itoa((long long int)va_arg(ap, long long int));
	else if (ft_strcmp(parsing.flag, "h") == 0)
		s1 = ft_itoa((short int)va_arg(ap, int));
	else if (ft_strcmp(parsing.flag, "hh") == 0)
		s1 = ft_itoa((signed char)va_arg(ap, int));
	else if (ft_strcmp(parsing.flag, "z") == 0)
		s1 = ft_itoa((size_t)va_arg(ap, size_t));
	else if (ft_strcmp(parsing.flag, "j") == 0)
		s1 = ft_itoa((intmax_t)va_arg(ap, uintmax_t));
	if (s1)
		ret = print_parsing(s1, &parsing);
	return (ret);
}

int	handling_upperd(va_list ap, t_params parsing)
{
	int		ret;
	char	*s1;

	ret = 0;
	s1 = ft_itoa(va_arg(ap, long int));
	if (s1)
		ret = print_parsing(s1, &parsing);
	return (ret);
}
