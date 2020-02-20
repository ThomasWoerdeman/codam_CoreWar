/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialise_players.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: twoerdem <twoerdem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 15:35:30 by twoerdem       #+#    #+#                */
/*   Updated: 2020/01/29 18:45:18 by twoerdem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static void		get_player_info(t_player *player)
{
	if (((unsigned char)player->bytecode[0] != 0) ||
	((unsigned char)player->bytecode[1] != 0xea) ||
	((unsigned char)player->bytecode[2] != 0x83) ||
	((unsigned char)player->bytecode[3] != 0xf3))
	{
		ft_printf("error: magic header incorrect\n");
		exit(0);
	}
	player->name = player->bytecode + 4;
	player->comment = player->bytecode + 4 * 3 + PROG_NAME_LENGTH;
	player->exec_code =
	player->bytecode + 4 * 4 + PROG_NAME_LENGTH + COMMENT_LENGTH;
	player->exec_code_size =
	((unsigned char)player->bytecode[PROG_NAME_LENGTH + 8] << 24) |
	((unsigned char)player->bytecode[PROG_NAME_LENGTH + 9] << 16) |
	((unsigned char)player->bytecode[PROG_NAME_LENGTH + 10] << 8) |
	((unsigned char)player->bytecode[PROG_NAME_LENGTH + 11]);
}

static int		check_null(char *code)
{
	int		index;

	index = 4;
	while (index > 0)
	{
		if ((unsigned char)(*code) != 0)
			return (0);
		code++;
		index--;
	}
	return (1);
}

static int		check_bytecode(t_player *player)
{
	if (check_null(&player->bytecode[4 + PROG_NAME_LENGTH]) != 1 ||
	check_null(&player->bytecode[12 + PROG_NAME_LENGTH + COMMENT_LENGTH]) != 1)
	{
		ft_printf("error: .cor file wrong\n");
		return (0);
	}
	if (player->exec_code_size > CHAMP_MAX_SIZE)
	{
		ft_printf("error: exec code size too big\n");
		return (0);
	}
	return (1);
}

int				initialise_players(t_vm *vm)
{
	int		index;
	int		buf_index;
	int		fd;

	index = 0;
	buf_index = 0;
	while (index < vm->n_players)
	{
		fd = open(vm->players[index]->file, O_RDONLY);
		read(fd, vm->players[index]->bytecode,
		16 + PROG_NAME_LENGTH + COMMENT_LENGTH + CHAMP_MAX_SIZE);
		get_player_info(vm->players[index]);
		if (check_bytecode(vm->players[index]) != 1)
			return (0);
		close(fd);
		introduce_player(vm->players[index]);
		index++;
	}
	return (1);
}
