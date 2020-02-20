/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_caesarcipher.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 10:47:13 by dfreire        #+#    #+#                */
/*   Updated: 2019/01/25 17:41:14 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	changevalue(char const *str, char *crypt, int n, int i)
{
	if (str[i] >= 'a' && str[i] <= 'z')
	{
		if ((str[i] + n) > 'z')
			crypt[i] -= 26;
		if ((str[i] + n) < 'a')
			crypt[i] += 26;
	}
	else if (str[i] >= 'A' && str[i] <= 'Z')
	{
		if ((str[i] + n) > 'Z')
			crypt[i] -= 26;
		if ((str[i] + n) < 'A')
			crypt[i] += 26;
	}
}

char		*ft_caesarcipher(char const *str, int n)
{
	int		i;
	char	*crypt;

	crypt = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (crypt == NULL)
		return (0);
	if (n < 26)
	{
		i = 0;
		while (str[i] != '\0')
		{
			if ((str[i] >= 'a' && str[i] <= 'z') ||
				(str[i] >= 'A' && str[i] <= 'Z'))
			{
				crypt[i] = str[i] + n;
				changevalue(str, crypt, i, n);
			}
			else
				crypt[i] = str[i];
			i++;
		}
		crypt[i] = '\0';
		return (crypt);
	}
	return (0);
}
