/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sti.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:26:14 by bbremer        #+#    #+#                */
/*   Updated: 2020/01/29 13:20:54 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static int		check_sti_argument_types(t_cursor *cursor)
{
	if (cursor->arguments->types[0] != 1)
		return (0);
	if (cursor->arguments->types[1] < 1 && cursor->arguments->types[1] > 3)
		return (0);
	if (cursor->arguments->types[2] != 1 && cursor->arguments->types[2] != 2)
		return (0);
	return (1);
}

static int		get_argument(t_cursor *cursor, char *arena, int count, int arg)
{
	int reg;

	reg = arena[(cursor->position + count) % MEM_SIZE];
	if (cursor->arguments->types[arg] == 1)
		arg = cursor->registries[reg - 1];
	else if (cursor->arguments->types[arg] == 2)
		arg = get_direct_argument(cursor, arena, 2, count);
	else
		arg = get_indirect_argument(cursor, arena, count);
	return (arg);
}

static int		get_count(t_cursor *cursor, int count, int arg)
{
	if (cursor->arguments->types[arg] == 1)
		count += 1;
	else if (cursor->arguments->types[arg] == 2)
		count += 2;
	else
		count += 2;
	return (count);
}

void			put_bytes_in_arena(t_vm *vm, int position, int argument_1,
				t_cursor *cursor)
{
	unsigned char	*new;

	new = (unsigned char *)ft_memalloc(4 * sizeof(unsigned char));
	new[0] = (argument_1 >> 24) & 255;
	new[1] = (argument_1 >> 16) & 255;
	new[2] = (argument_1 >> 8) & 255;
	new[3] = argument_1 & 255;
	if (position < 0)
		position = position + MEM_SIZE;
	vm->arena_color[((position) % MEM_SIZE)] = cursor->id * -1;
	vm->arena_color[((position + 1) % MEM_SIZE)] = cursor->id * -1;
	vm->arena_color[((position + 2) % MEM_SIZE)] = cursor->id * -1;
	vm->arena_color[((position + 3) % MEM_SIZE)] = cursor->id * -1;
	if (position > MEM_SIZE)
		position = position % MEM_SIZE;
	ft_memcpy(vm->arena + position, new, 4);
	free(new);
	new = NULL;
}

void			sti(t_cursor *cursor, t_vm *vm)
{
	int	argument_1;
	int	argument_2;
	int	argument_3;
	int	registry;
	int	count;

	count = 2;
	registry = vm->arena[(cursor->position + count) % MEM_SIZE];
	if (!is_registry(registry - 1) || !check_sti_argument_types(cursor))
		return ;
	argument_1 = cursor->registries[registry - 1];
	count += 1;
	argument_2 = get_argument(cursor, vm->arena, count, 1);
	count = get_count(cursor, count, 1);
	argument_3 = get_argument(cursor, vm->arena, count, 2);
	if (cursor->arguments->types[1] == 3)
	{
		argument_2 = get_direct_argument(cursor, vm->arena, count, 2);
		put_bytes_in_arena(vm, cursor->position + (argument_2 + argument_3 %
		IDX_MOD), argument_1, cursor);
	}
	else
		put_bytes_in_arena(vm, cursor->position +
		((argument_2 + argument_3) % IDX_MOD), argument_1, cursor);
}
