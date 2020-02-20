/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 16:18:20 by dfreire        #+#    #+#                */
/*   Updated: 2019/01/25 20:02:43 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*fresh;

	i = 0;
	fresh = 0;
	if (s && f)
	{
		fresh = ft_strdup((const char*)s);
		if (fresh == NULL)
			return (0);
		while (s[i] != '\0')
		{
			fresh[i] = f(s[i]);
			i++;
		}
		fresh[i] = '\0';
	}
	return (fresh);
}
