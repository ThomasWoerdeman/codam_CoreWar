/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ctostr.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/24 09:34:28 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/06 20:18:58 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ctostr(char c)
{
	char *str;

	str = (char*)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}
