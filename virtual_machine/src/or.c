/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   or.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 14:54:31 by lsmienk        #+#    #+#                */
/*   Updated: 2020/01/23 22:02:23 by biabremer     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

int				check_bitwise_ops_argument_types(t_cursor *cursor)
{
	if (cursor->arguments->types[0] < 1 || cursor->arguments->types[0] > 3)
		return (0);
	if (cursor->arguments->types[1] < 1 || cursor->arguments->types[1] > 3)
		return (0);
	if (cursor->arguments->types[2] != 1)
		return (0);
	return (1);
}

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

void			or(t_cursor *cursor, char *arena)
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
		cursor->registries[argument_3 - 1] = (argument_1 | argument_2);
		if ((argument_1 | argument_2) == 0)
			cursor->carry = 1;
		else
			cursor->carry = 0;
	}
}
