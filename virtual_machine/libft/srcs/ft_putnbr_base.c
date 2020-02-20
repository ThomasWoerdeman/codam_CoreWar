/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 13:46:45 by dfreire        #+#    #+#                */
/*   Updated: 2019/04/30 14:58:13 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	find_base(long n, char *base, int *p)
{
	int base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
		find_base(n / base_len, base, p);
	*p = *p + ft_putchar_int(base[n % base_len]);
}

int			ft_putnbr_base(long n, char *base)
{
	int p;

	p = 0;
	if (n < 0)
	{
		ft_putchar('-');
		p = p + 1;
		n *= 1;
	}
	find_base(n, base, &p);
	return (p);
}
