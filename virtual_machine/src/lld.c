/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lld.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:29:59 by bbremer        #+#    #+#                */
/*   Updated: 2020/01/23 21:59:14 by biabremer     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static int		check_lld_argument_types(t_cursor *cursor)
{
	if (cursor->arguments->types[0] < 2 || cursor->arguments->types[0] > 3)
		return (0);
	if (cursor->arguments->types[1] != 1)
		return (0);
	if (cursor->arguments->types[2] != 0)
		return (0);
	return (1);
}

void			lld(t_cursor *cursor, char *arena)
{
	int argument_1;
	int argument_2;

	if (!check_lld_argument_types(cursor))
		return ;
	if (cursor->arguments->types[0] == 2)
	{
		argument_1 = get_direct_argument(cursor, arena, 4, 2);
		argument_2 = arena[(cursor->position + 6) % MEM_SIZE];
	}
	else
	{
		argument_1 = get_indirect_argument(cursor, arena, 2);
		argument_1 = get_direct_argument(cursor, arena, 4,
						(cursor->position + argument_1));
		argument_2 = arena[(cursor->position + 4) % MEM_SIZE];
	}
	if (is_registry(argument_2 - 1))
		cursor->registries[argument_2 - 1] = argument_1;
	if (cursor->position + (argument_1) == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
}
