/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   supporting_functions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 14:34:27 by bbremer        #+#    #+#                */
/*   Updated: 2020/01/29 15:14:24 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

int		get_arguments_number(int opcode)
{
	if (opcode == 1 || opcode == 9 || opcode == 12 || opcode == 15 ||
	opcode == 16)
		return (1);
	else if (opcode == 2 || opcode == 3 || opcode == 13)
		return (2);
	else if (opcode == 4 || opcode == 5 || opcode == 6 || opcode == 7 ||
	opcode == 8 || opcode == 10 || opcode == 11 || opcode == 14)
		return (3);
	else
		return (0);
}

int		is_registry(int registry)
{
	if (registry > -1 && registry < 16)
		return (1);
	return (0);
}

void	run_temp(t_cursor **tmp, t_cursor **previous)
{
	*previous = *tmp;
	*tmp = (*tmp)->next;
}

void	manage_dump_flag(t_vm *vm)
{
	if (vm->visu_flag == 1)
		endwin();
	display_arena(vm);
	exit(0);
}
