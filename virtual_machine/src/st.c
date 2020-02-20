/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   st.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 16:28:10 by bbremer        #+#    #+#                */
/*   Updated: 2020/01/29 11:24:12 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static int	check_st_argument_types(t_cursor *cursor)
{
	if (cursor->arguments->types[0] != 1)
		return (0);
	if (cursor->arguments->types[1] != 1 && cursor->arguments->types[1] != 3)
		return (0);
	if (cursor->arguments->types[2] != 0)
		return (0);
	return (1);
}

void		st(t_cursor *cursor, t_vm *vm)
{
	int	argument_1;
	int	argument_2;
	int	registry;
	int	count;

	count = 2;
	registry = vm->arena[(cursor->position + count) % MEM_SIZE];
	if (!is_registry(registry - 1))
		return ;
	argument_1 = cursor->registries[registry - 1];
	count += 1;
	if (!check_st_argument_types(cursor))
		return ;
	if (cursor->arguments->types[1] == 1)
	{
		argument_2 = vm->arena[(cursor->position + count) % MEM_SIZE];
		if (is_registry(argument_2 - 1))
			cursor->registries[argument_2 - 1] = argument_1;
	}
	if (cursor->arguments->types[1] == 3)
	{
		argument_2 = get_direct_argument(cursor, vm->arena, 2, 3);
		put_bytes_in_arena(vm, cursor->position + (argument_2 % IDX_MOD),
		argument_1, cursor);
	}
}
