/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   corewar_vm.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: twoerdem <twoerdem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 15:47:36 by twoerdem       #+#    #+#                */
/*   Updated: 2020/01/29 19:29:14 by twoerdem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VM_H
# define COREWAR_VM_H
# include <curses.h>
# include "../libft/includes/libft.h"
# include "op.h"

typedef struct		s_player
{
	int				id;
	char			*name;
	char			*comment;
	char			*exec_code;
	int				exec_code_size;
	char			bytecode[2874];
	char			*file;
	int				lives;
}					t_player;

typedef struct		s_argument
{
	int				types[3];
}					t_argument;

typedef struct		s_cursor
{
	int				id;
	int				carry;
	int				opcode;
	int				last_live;
	int				wait_cycles;
	int				position;
	int				jump;
	int				registries[REG_NUMBER];
	t_argument		*arguments;
	struct s_cursor	*next;
}					t_cursor;

typedef struct		s_visu
{
	char			step;
	int				cycle_second;
	WINDOW			*w_arena;
	WINDOW			*w_stats;
}					t_visu;

typedef struct		s_vm
{
	t_player		**players;
	t_cursor		*cursors;
	t_visu			*visu;
	char			*winner;
	int				winnerid;
	int				n_players;
	int				n_cycles;
	int				n_process;
	int				n_lives;
	int				n_lives_check;
	int				dump_flag;
	int				dump_cycle;
	int				visu_flag;
	int				*used;
	char			*arena;
	char			*arena_color;
}					t_vm;

/*
**	visu
*/
void				visu_stats_players(t_vm *vm);
void				visu_stats_processes(t_vm *vm);
void				visu_stats_cycle(t_vm *vm);
void				visu_place_cursors(t_vm *vm);
void				visu_pause(t_vm *vm);
int					num_len(int num);
int					index_to_coord(int index, int hv);
void				visu_color(void);
void				visu_arena(t_vm *vm);
void				visu_stats(t_vm *vm);
void				visu_keypress(t_vm *vm);
void				visu_update(t_vm *vm);
void				init_visu(t_vm *vm);

/*
**	check_argument_validity.c
*/
int					check_n_flags(t_vm *vm, int argc, char **argv);
int					check_argument_validity(t_vm *vm, int argc, char **argv);

/*
**	parse_players.c
*/
void				add_no_nbr_players(t_vm *vm, t_player *no_nbr_players);
void				parse_players(t_vm *vm, int argc, char **argv);

/*
**	initialise_players.c
*/
int					initialise_players(t_vm *vm);

/*
**	initialise_cursors.c
*/
void				initialise_cursors(t_vm *vm);
void				allocate_cursors(t_vm *vm);

/*
**	introduction.c
*/
void				introduce_player(t_player *player);

/*
**	the game
*/

void				thebattle(t_vm *vm);

/*
**	manage_wait_cycles.c
*/
void				get_wait_cycle(t_cursor *cursor);
void				decrease_wait_cycles(t_cursor *cursor);

/*
**	supporting_funcions.c
*/
int					get_arguments_number(int opcode);
int					is_registry(int registry);
void				run_temp(t_cursor **tmp, t_cursor **previous);
void				manage_dump_flag(t_vm *vm);

/*
**	get_arguments.c
*/
void				get_argument_types(t_vm *vm, t_cursor *cursor);
int					get_direct_argument(t_cursor *cursor, char *arena,
					int amount, int count);
int					get_indirect_argument(t_cursor *cursor, char *arena,
					int count);
void				put_bytes_in_arena(t_vm *vm, int position,
					int argument_1, t_cursor *cursor);

/*
** operations
*/
int					check_bitwise_ops_argument_types(t_cursor *cursor);
void				add(t_cursor *cursor, char *arena);
void				aff(t_cursor *cursor, char *arena);
void				and(t_cursor *cursor, char *arena);
void				op_fork(t_cursor *cursor, t_vm *vm);
void				ld(t_cursor *cursor, char *arena);
void				lld(t_cursor *cursor, char *arena);
void				ldi(t_cursor *cursor, char *arena);
void				lfork(t_cursor *cursor, t_vm *vm);
void				live(t_cursor *cursor, t_vm *vm);
void				lldi(t_cursor *cursor, char *arena);
void				or(t_cursor *cursor, char *arena);
void				st(t_cursor *cursor, t_vm *vm);
void				sti(t_cursor *cursor, t_vm *vm);
void				sub(t_cursor *cursor, char *arena);
void				xor(t_cursor *cursor, char *arena);
void				zjmp(t_cursor *cursor, char *arena);

void				display_arena(t_vm *vm);

/*
** execute_operations.c
*/

void				do_operation(t_cursor *cursor, t_vm *vm);
void				execute_each_cursor(t_vm *vm, t_cursor *cursors);

#endif
