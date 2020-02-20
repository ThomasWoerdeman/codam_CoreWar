/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sqrt.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 21:07:59 by dfreire        #+#    #+#                */
/*   Updated: 2019/01/25 21:09:14 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int sq;

	sq = 1;
	if (nb <= 0)
		return (0);
	while (sq * sq < nb)
		sq++;
	if (sq * sq == nb)
		return (sq);
	else
		return (0);
}
