/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialise_cursors.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: biabremer <biabremer@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 20:17:00 by biabremer      #+#    #+#                */
/*   Updated: 2020/01/29 15:06:26 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void		allocate_cursors(t_vm *vm)
{
	t_cursor	*new;

	new = (t_cursor *)ft_memalloc(sizeof(t_cursor));
	ft_bzero(new, sizeof(t_cursor));
	if (vm->cursors)
		new->next = vm->cursors;
	vm->cursors = new;
}

static void	initialise_registry(t_vm *vm, int cursor)
{
	int index;

	index = 0;
	vm->cursors->registries[index] = vm->players[cursor]->id * -1;
	index++;
	while (index < REG_NUMBER)
	{
		vm->cursors->registries[index] = 0;
		index++;
	}
}

static void	get_cursor_position(t_vm *vm, int cursor)
{
	int	position;

	position = MEM_SIZE / vm->n_players;
	vm->cursors->position = position * (cursor);
	if (vm->cursors->position < 0)
		vm->cursors->position = vm->cursors->position + MEM_SIZE;
}

void		initialise_cursors(t_vm *vm)
{
	int	index;

	index = 0;
	while (index < vm->n_players)
	{
		allocate_cursors(vm);
		vm->cursors->carry = 0;
		vm->cursors->id = (index + 1) * -1;
		vm->cursors->last_live = 0;
		vm->cursors->wait_cycles = 0;
		get_cursor_position(vm, index);
		initialise_registry(vm, index);
		vm->cursors->arguments = (t_argument*)ft_memalloc(sizeof(t_argument));
		vm->cursors->arguments->types[0] = 0;
		vm->cursors->arguments->types[1] = 0;
		vm->cursors->arguments->types[2] = 0;
		index++;
	}
	vm->n_process = vm->n_players;
	vm->n_lives = 0;
}
