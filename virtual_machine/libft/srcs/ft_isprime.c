/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprime.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 13:50:37 by bbremer        #+#    #+#                */
/*   Updated: 2020/01/29 15:53:35 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprime(int number)
{
	int		prime;
	float	remain;

	remain = 0;
	prime = 2;
	while (prime < number)
	{
		remain = number % prime;
		if (remain == 0)
			return (0);
		prime++;
	}
	return (1);
}
