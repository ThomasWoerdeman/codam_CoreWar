/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 19:41:56 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/11 19:41:57 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

t_op g_op_tab[17] =
{
	{"live", 1, {T_DIR, 0, 0}, {0}, 1, 10, "alive", 0, 0, 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG, 0}, {0}, 2, 5, "load", 1, 0, 0, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, {0}, 3, 5, "store", 1, 0, 0, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, {0}, 4, 10, "addition", 1, 0, 0, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, {0}, 5, 10, "soustraction", 1, 0, 0, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, {0}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, 0, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, {0}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, 0, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, {0}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, 0, 0},
	{"zjmp", 1, {T_DIR, 0, 0}, {0}, 9, 20, "jump if zero", 0, 1, 0, 0},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, {0}, 10, 25,
		"load index", 1, 1, 0, 0},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, {0}, 11, 25,
		"store index", 1, 1, 0, 0},
	{"fork", 1, {T_DIR, 0, 0}, {0}, 12, 800, "fork", 0, 1, 0, 0},
	{"lld", 2, {T_DIR | T_IND, T_REG, 0}, {0}, 13, 10, "long load", 1, 0, 0, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, {0}, 14, 50,
		"long load index", 1, 1, 0, 0},
	{"lfork", 1, {T_DIR, 0, 0}, {0}, 15, 1000, "long fork", 0, 1, 0, 0},
	{"aff", 1, {T_REG, 0, 0}, {0}, 16, 2, "aff", 1, 0, 0, 0},
	{0, 0, {0}, {0}, 0, 0, 0, 0, 0, 0, 0}
};
