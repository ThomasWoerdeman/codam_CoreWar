/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_pointer.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 14:59:33 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/08 00:22:31 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_put_pointer(unsigned long long n)
{
	char	*tmp;

	if (n == 0)
	{
		tmp = ft_strnew(3);
		ft_strcpy(tmp, "0x0");
	}
	else
		tmp = ft_strjoin_s2("0x", ft_itoa_base(n, 16, "0123456789abcdef"));
	return (tmp);
}
