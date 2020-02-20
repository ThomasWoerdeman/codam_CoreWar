/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: twoerdem <twoerdem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 16:02:45 by twoerdem       #+#    #+#                */
/*   Updated: 2020/01/29 19:36:32 by twoerdem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static void	initialise_arena(t_vm *vm)
{
	int		index;
	int		position;

	index = 0;
	position = MEM_SIZE / vm->n_players;
	vm->arena = ft_memalloc(sizeof(char) * MEM_SIZE);
	vm->arena_color = ft_memalloc(sizeof(char) * MEM_SIZE);
	while (index < vm->n_players)
	{
		ft_memcpy(vm->arena + (position * index),\
			vm->players[index]->exec_code, vm->players[index]->exec_code_size);
		ft_memset(vm->arena_color + (position * index),\
			vm->players[index]->id, vm->players[index]->exec_code_size);
		index++;
	}
}

void		display_arena(t_vm *vm)
{
	int		index;

	index = 0;
	while (index < MEM_SIZE)
	{
		if (index % 64 == 0)
			ft_printf("\033[0;3m%02d-- ", index / 64);
		if (vm->arena_color[index] != 0)
			ft_printf("\033[0;3%dm%02x ", vm->arena_color[index],\
			(unsigned char)vm->arena[index]);
		else
			ft_printf("\033[0;3m%02x ", (unsigned char)vm->arena[index]);
		if (index % 64 == 63)
			ft_printf("\033[0;3m--%02d\n", index / 64);
		index++;
	}
	ft_putendl("");
}

int			main(int argc, char **argv)
{
	t_vm	*vm;

	vm = ft_memalloc(sizeof(t_vm));
	if (check_argument_validity(vm, argc, argv) == 0)
		return (0);
	parse_players(vm, argc, argv);
	if (initialise_players(vm) == 0)
		return (0);
	initialise_arena(vm);
	initialise_cursors(vm);
	if (vm->visu_flag == 1)
		init_visu(vm);
	thebattle(vm);
	if (vm->visu_flag == 1)
		endwin();
	if (vm->winner)
		ft_printf("Contestant %i, %s has won!\n", vm->winnerid, vm->winner);
	else
		ft_printf("Contestant %i, %s has won!\n", vm->players[0]->id,
				vm->players[0]->name);
	return (0);
}
