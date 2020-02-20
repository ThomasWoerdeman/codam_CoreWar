/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   live.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 16:34:40 by bbremer        #+#    #+#                */
/*   Updated: 2020/01/29 11:27:00 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	live(t_cursor *cursor, t_vm *vm)
{
	int	argument;

	argument = get_direct_argument(cursor, vm->arena, 4, 1);
	cursor->last_live = vm->n_cycles;
	vm->n_lives_check++;
	argument = argument * -1;
	if (argument < 5 && argument > -1 && vm->players[argument - 1])
	{
		vm->players[argument - 1]->lives = vm->n_cycles;
		vm->winner = vm->players[argument - 1]->name;
		vm->winnerid = vm->players[argument - 1]->id;
	}
}
