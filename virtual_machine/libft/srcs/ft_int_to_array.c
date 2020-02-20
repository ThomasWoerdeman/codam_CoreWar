/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_int_to_array.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 09:58:43 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/23 11:54:17 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_int_to_array(int *array, int size)
{
	int i;

	i = 0;
	if (size > 0)
		ft_putchar('[');
	while (i < size)
	{
		if (i + 1 == size)
		{
			ft_putnbr(array[i]);
			ft_putstr("]\n");
		}
		else
		{
			ft_putnbr(array[i]);
			ft_putstr(", ");
		}
		i++;
	}
}
