/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lldi.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:31:28 by bbremer        #+#    #+#                */
/*   Updated: 2020/01/29 11:25:34 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static int	check_lldi_argument_types(t_cursor *cursor)
{
	if (cursor->arguments->types[0] < 1 || cursor->arguments->types[0] > 3)
		return (0);
	if (cursor->arguments->types[1] != 1 || cursor->arguments->types[1] != 2)
		return (0);
	if (cursor->arguments->types[2] != 1)
		return (0);
	return (1);
}

static int	check_valid_registries(t_cursor *cursor, int argument_1,
			int argument_3)
{
	if (cursor->arguments->types[0] == 1 && (argument_1 < 1 || argument_1 > 16))
		return (0);
	if (argument_3 < 1 || argument_3 > 16)
		return (0);
	return (1);
}

static int	get_first_argument(t_cursor *cursor, char *arena)
{
	int	argument;

	argument = 0;
	if (cursor->arguments->types[0] == 1)
		argument = arena[(cursor->position + 2) % MEM_SIZE];
	else if (cursor->arguments->types[0] == 2)
		argument = get_direct_argument(cursor, arena, 2, 2);
	else if (cursor->arguments->types[0] == 3)
	{
		argument = get_direct_argument(cursor, arena, 2, 2);
		argument = get_direct_argument(cursor, arena, 4,
		(argument % IDX_MOD));
	}
	return (argument);
}

static int	get_second_argument(t_cursor *cursor, char *arena)
{
	int	argument;
	int	count;

	argument = 0;
	count = 0;
	if (cursor->arguments->types[0] == 1)
		count = 2;
	else if (cursor->arguments->types[0] == 2 ||
	cursor->arguments->types[0] == 3)
		count = 4;
	if (cursor->arguments->types[1] == 1)
		argument = arena[(cursor->position + count) % MEM_SIZE];
	else if (cursor->arguments->types[1] == 2)
		argument = get_direct_argument(cursor, arena, 2, count);
	return (argument);
}

void		lldi(t_cursor *cursor, char *arena)
{
	int	argument_1;
	int	argument_2;
	int	argument_3;
	int	final_value;

	argument_1 = get_first_argument(cursor, arena);
	argument_2 = get_second_argument(cursor, arena);
	argument_3 = arena[(cursor->position + cursor->jump - 1) % MEM_SIZE];
	if (!check_lldi_argument_types(cursor) || !check_valid_registries(cursor,
	argument_1, argument_3))
		return ;
	final_value = get_direct_argument(cursor, arena, 4,
	(argument_1 + argument_2));
	if (is_registry(argument_3 - 1))
		cursor->registries[argument_3 - 1] = final_value;
	if (final_value != 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
}
