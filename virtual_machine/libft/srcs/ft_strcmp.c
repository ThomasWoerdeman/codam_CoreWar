/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 09:00:01 by dfreire        #+#    #+#                */
/*   Updated: 2019/09/18 14:51:50 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] != '\0' && s1[i] == s2[i])
		{
			s1++;
			s2++;
		}
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (-1);
}
