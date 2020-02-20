/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 08:24:21 by dfreire        #+#    #+#                */
/*   Updated: 2019/01/25 19:28:32 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int len;

	len = ft_strlen(needle);
	if (len == '\0')
		return ((char*)haystack);
	i = 0;
	j = 0;
	while (haystack[i] != '\0')
	{
		if (j != 0 && haystack[i] != needle[j])
		{
			i = i - j;
			j = 0;
		}
		else if (haystack[i] == needle[j])
		{
			j++;
			if (j == len)
				return ((char*)&haystack[i - len + 1]);
		}
		i++;
	}
	return (0);
}
