/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aff.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:32:13 by bbremer        #+#    #+#                */
/*   Updated: 2020/01/23 21:54:59 by biabremer     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static int	check_aff_argument_types(t_cursor *cursor)
{
	if (cursor->arguments->types[0] != 1)
		return (0);
	if (cursor->arguments->types[1] != 0)
		return (0);
	if (cursor->arguments->types[2] != 0)
		return (0);
	return (1);
}

void		aff(t_cursor *cursor, char *arena)
{
	int	argument;
	int	registry;

	if (!check_aff_argument_types(cursor))
		return ;
	registry = arena[(cursor->position + 2) % MEM_SIZE];
	if (registry - 1 >= 0 && registry - 1 <= 15)
	{
		argument = cursor->registries[registry - 1];
		ft_printf("Aff: %c\n", (char)argument);
	}
}
