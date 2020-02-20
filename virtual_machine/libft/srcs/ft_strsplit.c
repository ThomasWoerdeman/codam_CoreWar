/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 09:02:19 by dfreire        #+#    #+#                */
/*   Updated: 2019/01/25 20:16:55 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_counter(char const *s, char c)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (*s != '\0')
	{
		if (i == 1 && *s == c)
			i = 0;
		if (i == 0 && *s != c)
		{
			i = 1;
			counter++;
		}
		s++;
	}
	return (counter);
}

static int		word_len(char const *s, char c)
{
	int len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		new_len;
	char	**str;

	i = 0;
	new_len = 0;
	str = 0;
	if (!s)
		return (0);
	new_len = word_counter((const char *)s, c);
	str = (char**)malloc(sizeof(*str) * (word_counter((const char *)s, c) + 1));
	if (str == NULL)
		return (0);
	while (new_len--)
	{
		while (*s == c && *s != '\0')
			s++;
		str[i] = ft_strsub((const char *)s, 0, word_len((const char *)s, c));
		if (str[i] == NULL)
			return (0);
		s = s + word_len(s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
