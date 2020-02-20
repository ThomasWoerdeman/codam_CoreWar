/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_argument_types.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 13:29:26 by bbremer        #+#    #+#                */
/*   Updated: 2020/01/28 18:39:19 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

/*
** Type 1 = T_REG
** Type 2 = DIR
** Type 3 = IND
*/

static void	get_types(unsigned char encoding_byte, t_cursor *cursor)
{
	int	i;
	int	byte;

	i = 2;
	byte = encoding_byte;
	if ((encoding_byte & 3) != 0)
	{
		cursor->arguments->types[0] = -1;
		return ;
	}
	while (i >= 0)
	{
		encoding_byte = encoding_byte >> 2;
		if ((encoding_byte & 3) == 1)
			cursor->arguments->types[i] = 1;
		else if ((encoding_byte & 3) == 2)
			cursor->arguments->types[i] = 2;
		else if ((encoding_byte & 3) == 3)
			cursor->arguments->types[i] = 3;
		i--;
	}
}

static int	direct_is_2_bytes(int opcode)
{
	if (opcode == 9 || opcode == 10 || opcode == 11 || opcode == 12 ||
	opcode == 14 || opcode == 15)
		return (1);
	else
		return (0);
}

static void	get_jump(t_cursor *cursor)
{
	int	jump;
	int	index;

	jump = 1;
	index = 0;
	if (cursor->opcode != 1 || cursor->opcode != 9 ||
	cursor->opcode != 12 || cursor->opcode != 15)
		jump++;
	while (index < 3)
	{
		if (cursor->arguments->types[index] == 1)
			jump++;
		else if (cursor->arguments->types[index] == 2 &&
		!direct_is_2_bytes(cursor->opcode))
			jump = jump + 4;
		else if (cursor->arguments->types[index] == 3 ||
		(cursor->arguments->types[index] == 2 &&
		direct_is_2_bytes(cursor->opcode)))
			jump = jump + 2;
		index++;
	}
	cursor->jump = jump;
}

void		get_argument_types(t_vm *vm, t_cursor *cursor)
{
	unsigned char	encoding_byte;

	if (cursor->opcode == 1 || cursor->opcode == 9 || cursor->opcode == 12 ||
	cursor->opcode == 15)
	{
		cursor->arguments->types[0] = 2;
		if (cursor->opcode == 1)
			cursor->jump = 5;
		else
			cursor->jump = 3;
		return ;
	}
	encoding_byte = vm->arena[(cursor->position + 1) % MEM_SIZE];
	get_types(encoding_byte, cursor);
	get_jump(cursor);
}
