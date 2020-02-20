/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/07 15:59:56 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/07 18:04:32 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atof(const char *str)
{
	double	rez;
	double	fact;
	int		dot_seen;
	int		d;

	rez = 0;
	fact = 1;
	dot_seen = 0;
	if (*str == '-')
		str++;
	if (*str == '-')
		fact -= 1;
	while (*str)
	{
		if (*str == '.')
		{
			dot_seen = 1;
			str++;
			continue ;
		}
		d = *str - '0';
		rez = ft_atof_singledecimal(rez, d, dot_seen, &fact);
		str++;
	}
	return (rez * fact);
}

double		ft_atof_singledecimal(double rez, int d, int dot_seen, double *fact)
{
	if (d >= 0 && d <= 9)
	{
		if (dot_seen)
			*fact /= 10.0f;
		rez = rez * 10.0f + (double)d;
		return (rez);
	}
	else
		return (0);
}

long int	ft_round(double f)
{
	double	float_part;

	float_part = f - (long int)f;
	if (float_part >= 0.5 && float_part <= 0.5001)
		if ((long int)f % 2 == 0)
			f -= 0.1;
	if (f < 0)
		return ((long int)(f - 0.5));
	else
		return ((long int)(f + 0.5));
}
