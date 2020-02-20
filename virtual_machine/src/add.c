/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 16:39:27 by bbremer        #+#    #+#                */
/*   Updated: 2020/01/23 22:12:06 by biabremer     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static int	check_add_argument_types(t_cursor *cursor)
{
	if (cursor->arguments->types[0] != 1)
		return (0);
	if (cursor->arguments->types[1] != 1)
		return (0);
	if (cursor->arguments->types[2] != 1)
		return (0);
	return (1);
}

void		add(t_cursor *cursor, char *arena)
{
	int	argument_1;
	int	argument_2;
	int argument_3;

	if (!check_add_argument_types(cursor))
		return ;
	argument_1 = arena[(cursor->position + 2) % MEM_SIZE];
	argument_2 = arena[(cursor->position + 3) % MEM_SIZE];
	argument_3 = arena[(cursor->position + 4) % MEM_SIZE];
	if (is_registry(argument_3 - 1) && is_registry(argument_1 - 1) &&
	is_registry(argument_2 - 1))
	{
		cursor->registries[argument_3 - 1] = cursor->registries[argument_1 - 1]
		+ cursor->registries[argument_2 - 1];
		if (cursor->registries[argument_1 - 1] +
		cursor->registries[argument_2 - 1] == 0)
			cursor->carry = 1;
		else
			cursor->carry = 0;
	}
}
