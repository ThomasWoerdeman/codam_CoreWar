/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handling_x.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/24 10:24:01 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/07 21:40:30 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handling_x(va_list ap, t_params parsing)
{
	int		ret;
	char	*s1;

	ret = 0;
	s1 = NULL;
	if (!parsing.flag)
		s1 = ft_itoa_base(va_arg(ap, unsigned int), 16, TYPE_X);
	else if (ft_strcmp(parsing.flag, "l") == 0)
		s1 = ft_itoa_base(va_arg(ap, unsigned long int), 16, TYPE_X);
	else if (ft_strcmp(parsing.flag, "ll") == 0)
		s1 = ft_itoa_base(va_arg(ap, unsigned long long int), 16, TYPE_X);
	else if (ft_strcmp(parsing.flag, "h") == 0)
		s1 = ft_itoa_base((unsigned short int)va_arg(ap, int), 16, TYPE_X);
	else if (ft_strcmp(parsing.flag, "hh") == 0)
		s1 = ft_itoa_base((unsigned char)va_arg(ap, int), 16, TYPE_X);
	else if (ft_strcmp(parsing.flag, "z") == 0)
		s1 = ft_itoa_base((size_t)va_arg(ap, size_t), 16, TYPE_X);
	else if (ft_strcmp(parsing.flag, "j") == 0)
		s1 = ft_itoa_base((uintmax_t)va_arg(ap, uintmax_t), 16, TYPE_X);
	if (s1)
		ret = print_parsing(s1, &parsing);
	return (ret);
}

int	handling_upperx(va_list ap, t_params parsing)
{
	int		ret;
	char	*s1;

	ret = 0;
	s1 = NULL;
	if (!parsing.flag)
		s1 = ft_itoa_base(va_arg(ap, unsigned int), 16, UPPER_X);
	else if (ft_strcmp(parsing.flag, "l") == 0)
		s1 = ft_itoa_base(va_arg(ap, unsigned long int), 16, UPPER_X);
	else if (ft_strcmp(parsing.flag, "ll") == 0)
		s1 = ft_itoa_base(va_arg(ap, unsigned long long int), 16, UPPER_X);
	else if (ft_strcmp(parsing.flag, "h") == 0)
		s1 = ft_itoa_base((unsigned short int)va_arg(ap, int), 16, UPPER_X);
	else if (ft_strcmp(parsing.flag, "hh") == 0)
		s1 = ft_itoa_base((unsigned char)va_arg(ap, int), 16, UPPER_X);
	else if (ft_strcmp(parsing.flag, "z") == 0)
		s1 = ft_itoa_base((size_t)va_arg(ap, size_t), 16, UPPER_X);
	else if (ft_strcmp(parsing.flag, "j") == 0)
		s1 = ft_itoa_base((uintmax_t)va_arg(ap, uintmax_t), 16, UPPER_X);
	if (s1)
		ret = print_parsing(s1, &parsing);
	return (ret);
}
