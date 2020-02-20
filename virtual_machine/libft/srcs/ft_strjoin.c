/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 19:21:24 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/07 21:00:55 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_s2(char *s1, char *s2)
{
	int		len;
	char	*fresh;

	len = 0;
	fresh = 0;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		fresh = ft_strnew(len);
		if (fresh == NULL)
			return (0);
		ft_strcpy(fresh, s1);
		ft_strcat(fresh, s2);
		ft_strdel(&s2);
		return (fresh);
	}
	return (0);
}

char	*ft_strjoin_s1(char *s1, char *s2)
{
	int		len;
	char	*fresh;

	len = 0;
	fresh = 0;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		fresh = (char*)malloc(sizeof(*fresh) * (len + 1));
		if (fresh == NULL)
			return (0);
		ft_strcpy(fresh, s1);
		ft_strcat(fresh, s2);
		ft_strdel(&s1);
		return (fresh);
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*fresh;

	len = 0;
	fresh = 0;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		fresh = (char*)malloc(sizeof(*fresh) * (len + 1));
		if (fresh == NULL)
			return (0);
		ft_strcpy(fresh, s1);
		ft_strcat(fresh, s2);
		return (fresh);
	}
	return (0);
}
