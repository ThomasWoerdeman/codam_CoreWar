/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ld.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 11:41:17 by lsmienk        #+#    #+#                */
/*   Updated: 2020/01/29 15:06:41 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static int	check_load_argument_types(t_cursor *cursor)
{
	if (cursor->arguments->types[0] != 2 && cursor->arguments->types[0] != 3)
		return (0);
	if (cursor->arguments->types[1] != 1)
		return (0);
	if (cursor->arguments->types[2] != 0)
		return (0);
	return (1);
}

void		ld(t_cursor *cursor, char *arena)
{
	int argument_1;
	int argument_2;

	if (!check_load_argument_types(cursor))
		return ;
	if (cursor->arguments->types[0] == 2)
	{
		argument_1 = get_direct_argument(cursor, arena, 4, 2);
		argument_2 = arena[(cursor->position + 6) % MEM_SIZE];
	}
	else
	{
		argument_1 = get_indirect_argument(cursor, arena, 2);
		argument_1 =
		get_direct_argument(cursor, arena, 4, argument_1 % IDX_MOD);
		argument_2 = arena[(cursor->position + 4) % MEM_SIZE];
	}
	if (is_registry(argument_2 - 1))
		cursor->registries[argument_2 - 1] = argument_1;
	if (argument_1 == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
}
