/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 17:53:09 by dfreire        #+#    #+#                */
/*   Updated: 2019/01/25 20:14:22 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t start;
	size_t end;

	start = 0;
	end = 0;
	if (s)
	{
		end = ft_strlen(s) - 1;
		if (s == NULL)
			return (0);
		while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			start++;
		if (s[start] == '\0')
			return (ft_strnew(0));
		while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			end--;
	}
	return (ft_strsub(s, start, end - start + 1));
}
