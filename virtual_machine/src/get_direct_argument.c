/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_direct_argument.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 10:26:50 by lsmienk        #+#    #+#                */
/*   Updated: 2020/01/28 18:39:46 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

int	get_direct_argument(t_cursor *cursor, char *arena, int amount, int count)
{
	int	i;
	int	pos;
	int result;

	i = 0;
	pos = cursor->position + count;
	result = 0;
	if (amount == 4)
	{
		result = (unsigned char)arena[pos % MEM_SIZE] << 24;
		result += (unsigned char)arena[(pos + 1) % MEM_SIZE] << 16;
		result += (unsigned char)arena[(pos + 2) % MEM_SIZE] << 8;
		result += (unsigned char)arena[(pos + 3) % MEM_SIZE];
	}
	else if (amount == 2)
	{
		result = (unsigned char)arena[pos % MEM_SIZE] << 8;
		result += (unsigned char)arena[(pos + 1) % MEM_SIZE];
		return ((short)result);
	}
	return (result);
}
