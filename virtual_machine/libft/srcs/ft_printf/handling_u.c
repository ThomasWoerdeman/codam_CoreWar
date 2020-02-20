/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handling_u.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/24 10:41:07 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/07 22:56:19 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handling_u(va_list ap, t_params parsing)
{
	int		ret;
	char	*s1;

	ret = 0;
	s1 = NULL;
	if (!parsing.flag)
		s1 = ft_itoa(va_arg(ap, unsigned int));
	else if (ft_strcmp(parsing.flag, "l") == 0)
		s1 = ft_un_itoa(va_arg(ap, unsigned long int));
	else if (ft_strcmp(parsing.flag, "ll") == 0)
		s1 = ft_un_itoa((unsigned long long)va_arg(ap, unsigned long long int));
	else if (ft_strcmp(parsing.flag, "h") == 0)
		s1 = ft_itoa((unsigned short)va_arg(ap, int));
	else if (ft_strcmp(parsing.flag, "hh") == 0)
		s1 = ft_itoa((unsigned char)va_arg(ap, int));
	else if (ft_strcmp(parsing.flag, "z") == 0)
		s1 = ft_un_itoa((size_t)va_arg(ap, size_t));
	else if (ft_strcmp(parsing.flag, "j") == 0)
		s1 = ft_un_itoa((uintmax_t)va_arg(ap, uintmax_t));
	if (s1)
		ret = print_parsing(s1, &parsing);
	return (ret);
}

int	handling_upperu(va_list ap, t_params parsing)
{
	int		ret;
	char	*s1;

	ret = 0;
	s1 = ft_un_itoa(va_arg(ap, unsigned long int));
	if (s1)
		ret = print_parsing(s1, &parsing);
	return (ret);
}
