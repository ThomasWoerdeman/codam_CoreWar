/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   xor.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 16:06:14 by lsmienk        #+#    #+#                */
/*   Updated: 2020/01/23 22:13:06 by biabremer     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static int		get_argument(t_cursor *cursor, char *arena, int count, int arg)
{
	int reg;

	reg = arena[(cursor->position + count) % MEM_SIZE];
	if (cursor->arguments->types[arg] == 1)
		arg = cursor->registries[reg - 1];
	else if (cursor->arguments->types[arg] == 2)
		arg = get_direct_argument(cursor, arena, 4, count);
	else
	{
		arg = get_indirect_argument(cursor, arena, count);
		arg = get_direct_argument(cursor, arena, 4, arg % IDX_MOD);
	}
	return (arg);
}

static int		get_count(t_cursor *cursor, int count, int arg)
{
	if (cursor->arguments->types[arg] == 1)
		count += 1;
	else if (cursor->arguments->types[arg] == 2)
		count += 4;
	else
		count += 2;
	return (count);
}

void			xor(t_cursor *cursor, char *arena)
{
	int argument_1;
	int argument_2;
	int argument_3;
	int count;

	count = 2;
	if (!check_bitwise_ops_argument_types(cursor))
		return ;
	argument_1 = get_argument(cursor, arena, count, 0);
	count = get_count(cursor, count, 0);
	argument_2 = get_argument(cursor, arena, count, 1);
	count = get_count(cursor, count, 1);
	argument_3 = arena[(cursor->position + count) % MEM_SIZE];
	if (is_registry(argument_3 - 1))
	{
		cursor->registries[argument_3 - 1] = (argument_1 ^ argument_2);
		if ((argument_1 ^ argument_2) == 0)
			cursor->carry = 1;
		else
			cursor->carry = 0;
	}
}
