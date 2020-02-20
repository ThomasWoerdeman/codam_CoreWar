/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zjmp.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 13:54:13 by lsmienk        #+#    #+#                */
/*   Updated: 2020/01/29 11:17:00 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void		zjmp(t_cursor *cursor, char *arena)
{
	short	argument_1;

	argument_1 = get_direct_argument(cursor, arena, 2, 1);
	if (cursor->carry == 1)
	{
		cursor->position = (cursor->position + (argument_1 % IDX_MOD));
		if (cursor->position < 0)
			cursor->position = MEM_SIZE + cursor->position;
		if (cursor->position > MEM_SIZE - 1)
			cursor->position = cursor->position - MEM_SIZE;
		cursor->jump = 0;
	}
}
