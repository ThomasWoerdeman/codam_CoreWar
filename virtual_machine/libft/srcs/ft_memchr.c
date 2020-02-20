/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 19:25:38 by dfreire       #+#    #+#                 */
/*   Updated: 2019/01/20 12:02:47 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((char*)s)[i] == (char)c)
			return (char*)(s + i);
		i++;
	}
	return (NULL);
}
