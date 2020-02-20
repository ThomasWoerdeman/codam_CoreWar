/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 19:40:51 by dfreire       #+#    #+#                 */
/*   Updated: 2019/01/19 18:12:45 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t leng)
{
	char *d1;
	char *d2;

	d1 = s1;
	d2 = (char*)s2;
	while (*d1 != '\0')
		d1++;
	while (*d2 != '\0' && leng > 0)
	{
		*d1 = *d2;
		d1++;
		d2++;
		leng--;
	}
	*d1 = '\0';
	return (s1);
}
