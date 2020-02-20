/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_int.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 15:32:08 by bbremer        #+#    #+#                */
/*   Updated: 2019/05/06 19:49:52 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_int(char const *s)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (s[i] != '\0')
	{
		ret = ret + ft_putchar_int(s[i]);
		i++;
	}
	return (ret);
}
