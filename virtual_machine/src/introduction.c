/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   introduction.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: twoerdem <twoerdem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 15:39:49 by twoerdem       #+#    #+#                */
/*   Updated: 2019/12/18 21:16:11 by biabremer     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	introduce_player(t_player *player)
{
	ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", player->id\
		, player->exec_code_size, player->name, player->comment);
}
