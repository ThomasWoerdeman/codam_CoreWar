/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visu.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: twoerdem <twoerdem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 16:36:39 by twoerdem       #+#    #+#                */
/*   Updated: 2020/01/27 16:04:54 by twoerdem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void		visu_keypress(t_vm *vm)
{
	int		ch;

	nodelay(vm->visu->w_stats, 1);
	ch = wgetch(vm->visu->w_stats);
	if (ch == 'w' && vm->visu->cycle_second != 10)
		vm->visu->cycle_second -= 10;
	if (ch == 'e' && vm->visu->cycle_second < 1000)
		vm->visu->cycle_second += 10;
	if (ch == 'r')
		vm->visu->cycle_second = 50;
	if (ch == 't')
		vm->visu->cycle_second = 1000;
	if (ch == 27)
	{
		endwin();
		vm->visu_flag = 0;
	}
	if (ch == ' ' || ch == 's' || vm->visu->step == 1)
		visu_pause(vm);
}

void		visu_update(t_vm *vm)
{
	mvwprintw(vm->visu->w_stats, 2, 67, "[RUNNING]");
	visu_stats_cycle(vm);
	visu_stats_processes(vm);
	visu_stats_players(vm);
	visu_place_cursors(vm);
	visu_keypress(vm);
	usleep(1000000 / vm->visu->cycle_second);
}

void		init_visu(t_vm *vm)
{
	vm->visu = ft_memalloc(sizeof(t_visu));
	vm->visu->cycle_second = 50;
	vm->visu->step = 1;
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	visu_color();
	bkgd(COLOR_PAIR(1));
	visu_stats(vm);
	visu_update(vm);
}
