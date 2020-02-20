/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 11:36:29 by bbremer        #+#    #+#                */
/*   Updated: 2020/01/29 14:45:47 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static void	get_cursor_data(t_cursor *cursor, t_vm *vm, int argument)
{
	t_cursor	*temp;
	int			i;

	i = 0;
	temp = vm->cursors;
	temp->id = cursor->id;
	temp->carry = cursor->carry;
	temp->opcode = 0;
	temp->last_live = 0;
	temp->wait_cycles = 0;
	temp->position = (cursor->position + argument) % MEM_SIZE;
	if (temp->position < 0)
		temp->position = temp->position + MEM_SIZE;
	temp->jump = 0;
	temp->arguments = (t_argument*)ft_memalloc(sizeof(t_argument));
	temp->arguments->types[0] = 0;
	temp->arguments->types[1] = 0;
	temp->arguments->types[2] = 0;
	vm->n_process++;
	while (i < 16)
	{
		temp->registries[i] = cursor->registries[i];
		i++;
	}
}

static void	allocate_cursor_fork(t_vm *vm)
{
	t_cursor	*new;
	t_cursor	*temp;

	new = (t_cursor*)ft_memalloc(sizeof(t_cursor));
	temp = vm->cursors;
	ft_bzero(new, sizeof(t_cursor));
	new->next = temp;
	vm->cursors = new;
}

void		op_fork(t_cursor *cursor, t_vm *vm)
{
	int	argument;

	argument = get_direct_argument(cursor, vm->arena, 2, 1) % IDX_MOD;
	allocate_cursor_fork(vm);
	get_cursor_data(cursor, vm, argument);
}
