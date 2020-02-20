/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_players.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: twoerdem <twoerdem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 17:39:54 by twoerdem       #+#    #+#                */
/*   Updated: 2020/01/29 18:58:20 by twoerdem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	add_no_nbr_players(t_vm *vm, t_player *no_nbr_players)
{
	int			index;
	int			nnp_index;

	index = 0;
	nnp_index = 0;
	while (index < vm->n_players)
	{
		if (vm->players[index]->file == NULL)
		{
			vm->players[index]->file = no_nbr_players[nnp_index].file;
			nnp_index++;
		}
		vm->players[index]->id = index + 1;
		index++;
	}
}

void	allocate_players(t_vm *vm)
{
	int			index;

	index = 0;
	vm->players = ft_memalloc(sizeof(t_player) * vm->n_players);
	while (index < vm->n_players)
	{
		vm->players[index] = ft_memalloc(sizeof(t_player));
		index++;
	}
}

void	parse_players(t_vm *vm, int argc, char **argv)
{
	t_player	no_nbr_players[vm->n_players];
	int			index;
	int			nnp_index;

	index = 1;
	nnp_index = 0;
	allocate_players(vm);
	while (index < argc)
	{
		if (ft_strcmp(argv[index], "-n") == 0)
		{
			vm->players[argv[index + 1][0] - '1']->file = argv[index + 2];
			index = index + 2;
		}
		else if ((ft_strcmp(argv[index],
		"-dump") == 0 || ft_strcmp(argv[index], "-d") == 0))
			index++;
		else if (ft_strstr(argv[index], ".cor"))
		{
			no_nbr_players[nnp_index].file = argv[index];
			nnp_index++;
		}
		index++;
	}
	add_no_nbr_players(vm, no_nbr_players);
}
