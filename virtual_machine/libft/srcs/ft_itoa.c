/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 11:05:38 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/08 01:04:42 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(long long int n)
{
	int len;

	len = 1;
	if (n < 0)
		len++;
	while (n /= 10)
		len++;
	return (len);
}

static int	unsigned_len(unsigned long long int n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char		*ft_itoa(long long int n)
{
	char	*fresh;
	int		i;

	i = len(n);
	fresh = ft_strnew(i);
	if (fresh == NULL)
		return (0);
	if (n < 0)
		fresh[0] = '-';
	else
		n = 0 - n;
	while (n / 10)
	{
		fresh[--i] = (0 - (n % 10)) + '0';
		n /= 10;
	}
	fresh[--i] = (0 - (n % 10)) + '0';
	return (fresh);
}

char		*ft_un_itoa(unsigned long long int n)
{
	char	*fresh;
	int		i;

	i = unsigned_len(n);
	fresh = ft_strnew(i);
	if (fresh == NULL)
		return (0);
	while (n / 10)
	{
		fresh[--i] = (n % 10) + '0';
		n /= 10;
	}
	fresh[--i] = (n % 10) + '0';
	return (fresh);
}
