/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 14:50:42 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/03 14:59:26 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen_base(unsigned long int n, int base)
{
	size_t	i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}
