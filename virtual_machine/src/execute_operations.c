/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_operations.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 13:27:43 by bbremer        #+#    #+#                */
/*   Updated: 2020/01/29 14:34:50 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static void		do_operation_2(t_cursor *cursor, t_vm *vm)
{
	if (cursor->opcode == 10)
		ldi(cursor, vm->arena);
	else if (cursor->opcode == 11)
		sti(cursor, vm);
	else if (cursor->opcode == 12)
		op_fork(cursor, vm);
	else if (cursor->opcode == 13)
		lld(cursor, vm->arena);
	else if (cursor->opcode == 14)
		lldi(cursor, vm->arena);
	else if (cursor->opcode == 15)
		lfork(cursor, vm);
	else if (cursor->opcode == 16)
		aff(cursor, vm->arena);
}

void			do_operation(t_cursor *cursor, t_vm *vm)
{
	if (cursor->opcode == 1)
		live(cursor, vm);
	else if (cursor->opcode == 2)
		ld(cursor, vm->arena);
	else if (cursor->opcode == 3)
		st(cursor, vm);
	else if (cursor->opcode == 4)
		add(cursor, vm->arena);
	else if (cursor->opcode == 5)
		sub(cursor, vm->arena);
	else if (cursor->opcode == 6)
		and(cursor, vm->arena);
	else if (cursor->opcode == 7)
		or(cursor, vm->arena);
	else if (cursor->opcode == 8)
		xor(cursor, vm->arena);
	else if (cursor->opcode == 9)
		zjmp(cursor, vm->arena);
	else
		do_operation_2(cursor, vm);
}
