/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ftoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 17:47:08 by bbremer        #+#    #+#                */
/*   Updated: 2019/05/08 10:31:53 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	while_digits(char **f_decimals, int digits)
{
	char *bye_decimals;

	while (ft_strlen(*f_decimals) < (size_t)digits)
	{
		bye_decimals = *f_decimals;
		*f_decimals = ft_strjoin(*f_decimals, "0");
		ft_strdel(&bye_decimals);
	}
	return ;
}

char	*ft_ftoa(long double f, unsigned long digits)
{
	signed long int decimals;
	signed long int integers;
	char			*f_integers;
	char			*f_total;
	char			*f_decimals;

	integers = (signed long int)f;
	f_integers = ft_itoa(integers);
	f_total = ft_strjoin(f_integers, ".");
	f -= integers;
	f *= 1000000;
	if (f < 0)
		f *= -1;
	decimals = (signed long int)(f + 0.5);
	f_decimals = ft_itoa(decimals);
	while_digits(&f_decimals, digits);
	while (ft_strlen(f_decimals) > digits)
		f_decimals[ft_strlen(f_decimals) - 1] = '\0';
	f_total = ft_strjoin(f_total, f_decimals);
	ft_strdel(&f_decimals);
	return (f_total);
}
