/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visu3.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: twoerdem <twoerdem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 16:04:45 by twoerdem       #+#    #+#                */
/*   Updated: 2020/01/28 17:30:29 by twoerdem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void		visu_stats_players(t_vm *vm)
{
	int		index;

	index = 0;
	while (index < vm->n_players)
	{
		wattrset(vm->visu->w_stats, A_BOLD);
		mvwprintw(vm->visu->w_stats, 2 + 4 * (index + 1), 4,
			"Player -%d : ", index + 1);
		wattrset(vm->visu->w_stats, COLOR_PAIR(index + 1) | A_BOLD);
		wprintw(vm->visu->w_stats, "%s", vm->players[index]->name);
		wattrset(vm->visu->w_stats, A_BOLD);
		mvwprintw(vm->visu->w_stats, 3 + 4 * (index + 1), 6,
			"Last Live :\t\t\t%d", vm->players[index]->lives);
		mvwprintw(vm->visu->w_stats, 4 + 4 * (index + 1), 6,
			"Lives In Current Period :\t\t%d", 0);
		index++;
	}
	wattroff(vm->visu->w_stats, A_BOLD);
	box(vm->visu->w_stats, 0, 0);
	wrefresh(vm->visu->w_stats);
}

void		visu_stats_processes(t_vm *vm)
{
	wattrset(vm->visu->w_stats, A_BOLD);
	mvwprintw(vm->visu->w_stats, 4, 4, "Processes : %d", vm->n_process);
	wattroff(vm->visu->w_stats, A_BOLD);
	box(vm->visu->w_stats, 0, 0);
	wrefresh(vm->visu->w_stats);
}

void		visu_stats_cycle(t_vm *vm)
{
	wattrset(vm->visu->w_stats, A_BOLD);
	mvwprintw(vm->visu->w_stats, 2, 4, "Cycle : %d", vm->n_cycles);
	wattroff(vm->visu->w_stats, A_BOLD);
	mvwprintw(vm->visu->w_stats, 3, 53 - num_len(vm->visu->cycle_second),
		"  Cycles pers second: %d", vm->visu->cycle_second);
	box(vm->visu->w_stats, 0, 0);
	wrefresh(vm->visu->w_stats);
}

void		visu_place_cursors(t_vm *vm)
{
	t_cursor	*cursor;
	int			index;

	visu_arena(vm);
	cursor = vm->cursors;
	while (cursor)
	{
		index = cursor->position;
		wattrset(vm->visu->w_arena,
			COLOR_PAIR(vm->arena_color[index] + 5) | A_BOLD);
		mvwprintw(vm->visu->w_arena, index_to_coord(index, 1),
			index_to_coord(index, 0), "%02x", (unsigned char)vm->arena[index]);
		attroff(0);
		cursor = cursor->next;
	}
	wrefresh(vm->visu->w_arena);
}

void		visu_pause(t_vm *vm)
{
	int		ch;

	ch = 0;
	mvwprintw(vm->visu->w_stats, 2, 67, " [PAUSED]");
	wrefresh(vm->visu->w_stats);
	vm->visu->step = 0;
	while (ch != ' ')
	{
		ch = wgetch(vm->visu->w_stats);
		if (ch == 's')
		{
			vm->visu->step = 1;
			break ;
		}
	}
	wrefresh(vm->visu->w_stats);
}
