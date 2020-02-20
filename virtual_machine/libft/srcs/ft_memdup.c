/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 16:54:06 by dfreire        #+#    #+#                */
/*   Updated: 2019/01/23 17:19:43 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memdup(void const *content, size_t content_size)
{
	void *fresh;

	fresh = malloc(sizeof(unsigned char) * content_size);
	if (fresh == NULL)
		return (0);
	ft_memcpy(fresh, content, content_size);
	return (fresh);
}
