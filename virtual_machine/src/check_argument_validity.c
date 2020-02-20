/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_argument_validity.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: twoerdem <twoerdem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 17:39:03 by twoerdem       #+#    #+#                */
/*   Updated: 2020/01/29 19:30:03 by twoerdem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

int		is_int(char *str)
{
	int		i;
	int		value;
	int		neg;

	i = 0;
	value = 0;
	neg = 0;
	if (str[i] == '-')
	{
		neg++;
		i++;
	}
	while (str[i] != 0)
	{
		if (!ft_isdigit(str[i]) || value > 214748364 ||
			(value == 214748364 && str[i] - 48 > 7 + neg))
			return (0);
		value *= 10;
		value += str[i] - 48;
		i++;
	}
	if (i - neg > 10)
		return (0);
	return (value);
}

void	get_dump_flag(t_vm *vm, char *dump_cycle)
{
	int		int_dump_cycle;

	int_dump_cycle = is_int(dump_cycle);
	if (int_dump_cycle > 0)
	{
		vm->dump_flag = 1;
		vm->dump_cycle = int_dump_cycle;
	}
	else
		vm->dump_flag = 0;
}

int		check_n_flags(t_vm *vm, int argc, char **argv)
{
	int		index;

	vm->used = (int *)ft_memalloc(sizeof(int) * 4);
	index = 1;
	while (index < argc)
	{
		if (ft_strcmp(argv[index], "-n") == 0)
		{
			if (is_int(argv[index + 1]) > 0)
			{
				if (ft_atoi(argv[index + 1]) < 1 || ft_atoi(argv[index + 1]) >
					vm->n_players ||
					vm->used[ft_atoi(argv[index + 1]) - 1] == 1)
					return (0);
				vm->used[ft_atoi(argv[index + 1]) - 1] = 1;
			}
			else
				return (0);
			if (ft_strstr(argv[index + 2], ".cor") == NULL)
				return (0);
		}
		index++;
	}
	return (1);
}

int		flag_count(t_vm *vm, int argc, char **argv)
{
	int		n_flag;
	int		index;

	n_flag = 0;
	index = 1;
	while (index < argc)
	{
		if (ft_strstr(argv[index], ".cor"))
			if (ft_strlen(ft_strstr(argv[index], ".cor")) ==
				4 && ft_strlen(argv[index]) != 4)
				vm->n_players++;
		if (ft_strcmp(argv[index], "-n") == 0 && index + 2 < argc)
			n_flag++;
		if ((ft_strcmp(argv[index], "-dump") == 0 ||
			ft_strcmp(argv[index], "-d") == 0) && argv[index + 1])
			get_dump_flag(vm, argv[index + 1]);
		if (ft_strcmp(argv[index], "-v") == 0)
			vm->visu_flag++;
		index++;
	}
	return (n_flag);
}

int		check_argument_validity(t_vm *vm, int argc, char **argv)
{
	int		n_flag;

	n_flag = flag_count(vm, argc, argv);
	if (n_flag > 4 || vm->n_players > 4 || vm->n_players == 0 ||
		(vm->n_players - n_flag) + (n_flag * 3) + vm->visu_flag +
		(vm->dump_flag * 2) != argc - 1 || vm->dump_flag > 1 ||
		vm->visu_flag > 1)
	{
		ft_printf("usage %s [-n num(1-4)] file.cor \
[-dump num | -d num | -v]\n", argv[0]);
		return (0);
	}
	if (check_n_flags(vm, argc, argv) == 0)
	{
		ft_printf("usage: %s [-n num(1-4)] file.cor\n", argv[0]);
		return (0);
	}
	return (1);
}
