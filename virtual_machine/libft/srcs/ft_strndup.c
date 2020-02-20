/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 13:36:01 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/07 23:13:11 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = ft_strnew(sizeof(char) * n);
	if (s2 == NULL)
		return (0);
	while (i < n && s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strndup_free(char *s1, size_t n)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = ft_strnew(sizeof(char) * n);
	if (s2 == NULL)
		return (0);
	while (i < n && s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	ft_strdel(&s1);
	return (s2);
}
