/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handling_p.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 15:02:58 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/08 10:46:25 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handling_p(va_list ap, t_params parsing)
{
	int		ret;
	char	*s1;

	ret = 0;
	s1 = ft_put_pointer(va_arg(ap, unsigned long int));
	if (s1)
		ret = print_parsing(s1, &parsing);
	return (ret);
}
