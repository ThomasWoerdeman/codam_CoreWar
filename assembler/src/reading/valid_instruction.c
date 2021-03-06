/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_instruction.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/14 12:54:01 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/14 12:54:01 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					valid_instruction(char c)
{
	if (c == '%' || c == ':' || ft_isspace(c))
		return (1);
	return (0);
}
