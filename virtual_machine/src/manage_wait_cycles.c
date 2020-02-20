/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   manage_wait_cycles.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 17:28:02 by bbremer        #+#    #+#                */
/*   Updated: 2020/01/23 14:08:05 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	get_wait_cycle(t_cursor *cursor)
{
	if (cursor->opcode == 1 || cursor->opcode == 4 || cursor->opcode == 5 ||
	cursor->opcode == 13)
		cursor->wait_cycles = 10;
	else if (cursor->opcode == 2 || cursor->opcode == 3)
		cursor->wait_cycles = 5;
	else if (cursor->opcode == 6 || cursor->opcode == 7 || cursor->opcode == 8)
		cursor->wait_cycles = 6;
	else if (cursor->opcode == 9)
		cursor->wait_cycles = 20;
	else if (cursor->opcode == 10 || cursor->opcode == 11)
		cursor->wait_cycles = 25;
	else if (cursor->opcode == 12)
		cursor->wait_cycles = 800;
	else if (cursor->opcode == 14)
		cursor->wait_cycles = 50;
	else if (cursor->opcode == 15)
		cursor->wait_cycles = 1000;
	else if (cursor->opcode == 16)
		cursor->wait_cycles = 2;
}

void	decrease_wait_cycles(t_cursor *cursor)
{
	cursor->wait_cycles--;
}
