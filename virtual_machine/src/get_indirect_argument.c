/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_indirect_argument.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 10:29:36 by lsmienk        #+#    #+#                */
/*   Updated: 2020/01/28 18:39:59 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

int	get_indirect_argument(t_cursor *cursor, char *arena, int count)
{
	int	i;
	int shift;
	int	pos;
	int	result;

	i = 0;
	pos = cursor->position + count;
	result = 0;
	shift = 32;
	while (i < 2)
	{
		result = result << shift;
		result += arena[pos];
		pos++;
		i++;
		shift -= 8;
	}
	return ((short)result);
}
