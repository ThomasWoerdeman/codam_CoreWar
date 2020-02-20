/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 08:55:38 by dfreire       #+#    #+#                 */
/*   Updated: 2019/01/22 16:38:09 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *len;

	len = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			len = (char*)s;
		s++;
	}
	if (*s == '\0' && c == '\0')
		len = (char*)s;
	return (len);
}
