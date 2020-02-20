/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 14:51:43 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/07 19:09:29 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long int n, int base, char *str)
{
	size_t	size;
	size_t	i;
	char	*tmp;

	size = ft_numlen_base(n, base);
	tmp = (char*)malloc(sizeof(char) * size + 1);
	if (!tmp)
		return (NULL);
	tmp[size] = '\0';
	if (!n)
		tmp[0] = '0';
	i = size - 1;
	while (n)
	{
		tmp[i] = str[n % base];
		n = n / base;
		i--;
	}
	return (tmp);
}
