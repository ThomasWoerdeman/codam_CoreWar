/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_binary.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 10:18:33 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/01 10:20:06 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_binary(int n)
{
	int	i;

	i = 0;
	if (n >= 2)
	{
		i = n % 2;
		n = n / 2;
		ft_put_binary(n);
	}
	else if (n > 0)
	{
		i = n % 2;
		n = n / 2;
	}
	ft_putchar(i + '0');
}
