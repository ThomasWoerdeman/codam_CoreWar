/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visu2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: twoerdem <twoerdem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 16:04:16 by twoerdem       #+#    #+#                */
/*   Updated: 2020/01/28 17:29:48 by twoerdem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

int		num_len(int num)
{
	int		length;

	length = 0;
	while (num > 9)
	{
		num = num / 10;
		length++;
	}
	return (length);
}

int		index_to_coord(int index, int hv)
{
	int		horizontal;
	int		vertical;

	vertical = index / 64;
	horizontal = (index % 64) * 3;
	if (hv == 0)
		return (horizontal + 2);
	else
		return (vertical + 1);
}

void	visu_color(void)
{
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_WHITE);
	init_pair(6, COLOR_BLACK, COLOR_CYAN);
	init_pair(7, COLOR_BLACK, COLOR_YELLOW);
	init_pair(8, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(9, COLOR_BLACK, COLOR_RED);
}

void	visu_arena(t_vm *vm)
{
	int		index;

	index = 0;
	vm->visu->w_arena = newwin(64 + 2, 128 + 64 + 3, 0, 0);
	box(vm->visu->w_arena, 0, 0);
	while (index < MEM_SIZE)
	{
		if (vm->arena_color[index] >= 0)
			wattrset(vm->visu->w_arena, COLOR_PAIR(vm->arena_color[index]));
		mvwprintw(vm->visu->w_arena, index_to_coord(index, 1),
		index_to_coord(index, 0), "%02x", (unsigned char)vm->arena[index]);
		index++;
	}
	attroff(0);
}

void	visu_stats(t_vm *vm)
{
	vm->visu->w_stats = newwin(7 + (vm->n_players) * 4, 80, 0, 128 + 64 + 3);
	wmove(vm->visu->w_stats, 2, 0);
	wattrset(vm->visu->w_stats, A_BOLD);
	wattroff(vm->visu->w_stats, A_BOLD);
	box(vm->visu->w_stats, 0, 0);
	wrefresh(vm->visu->w_stats);
}
