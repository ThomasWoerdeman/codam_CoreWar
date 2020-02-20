/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handling_c.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/07 11:50:12 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/07 21:41:02 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handling_c(va_list ap, t_params parsing)
{
	int		ret;
	char	*s1;

	ret = 0;
	s1 = ctostr((char)va_arg(ap, int));
	if (s1)
		ret = print_parsing(s1, &parsing);
	return (ret);
}
