/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 17:29:58 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/11 17:29:58 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void			error(char *message)
{
	ft_printf("%s\n", message);
	exit(0);
}
