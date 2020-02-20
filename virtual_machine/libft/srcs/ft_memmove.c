/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 14:16:21 by dfreire       #+#    #+#                 */
/*   Updated: 2019/01/19 18:06:56 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*x;
	const unsigned char	*y;

	x = (unsigned char*)dst;
	y = (unsigned char*)src;
	if (y < x)
	{
		x += len;
		y += len;
		while (len > 0)
		{
			len--;
			x--;
			y--;
			*x = *y;
		}
	}
	else
		while (len > 0)
		{
			len--;
			*x++ = *y++;
		}
	return (dst);
}
