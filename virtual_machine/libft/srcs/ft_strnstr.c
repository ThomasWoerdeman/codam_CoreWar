/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 08:54:35 by dfreire       #+#    #+#                 */
/*   Updated: 2019/01/22 16:45:29 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	if (*needle == '\0')
		return ((char*)haystack);
	i = 0;
	while (*haystack && i < len)
	{
		if (*haystack == *needle)
		{
			while (*(haystack + i) == *(needle + i) && len - i)
			{
				i++;
				if (*(needle + i) == '\0')
					return ((char*)haystack);
			}
		}
		len--;
		haystack++;
	}
	return (0);
}
