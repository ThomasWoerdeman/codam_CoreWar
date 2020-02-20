/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialise_varargs.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 14:04:13 by dfreire        #+#    #+#                */
/*   Updated: 2019/04/19 14:09:13 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialise_varargs(t_params *parsing)
{
	parsing->hashtag = 0;
	parsing->zero = 0;
	parsing->minus = 0;
	parsing->plus = 0;
	parsing->space = 0;
	parsing->dot = 0;
	parsing->width = 0;
	parsing->precision = 0;
	parsing->type = 0;
	parsing->flag = 0;
	parsing->flag_chart = 0;
	parsing->flag_error = 0;
}
