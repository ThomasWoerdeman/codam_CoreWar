/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 18:16:58 by dfreire        #+#    #+#                */
/*   Updated: 2019/01/25 20:05:44 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*fresh;

	i = 0;
	fresh = 0;
	if (s && f)
	{
		while (s[i] != '\0')
			i++;
		fresh = (char*)malloc(sizeof(char) * (i + 1));
		if (fresh == NULL)
			return (0);
		i = 0;
		while (s[i] != '\0')
		{
			fresh[i] = f(i, s[i]);
			i++;
		}
		fresh[i] = '\0';
	}
	return (fresh);
}
