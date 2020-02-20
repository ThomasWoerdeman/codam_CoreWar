/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   label_direct_value.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 14:56:47 by fblom          #+#    #+#                */
/*   Updated: 2020/01/29 18:23:22 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				label_direct_value(char *label, t_list **head, int position)
{
	t_list		*list;

	list = *head;
	while (list)
	{
		if (ft_strequ(list->content, label))
		{
			while (list->next)
			{
				if (list->content_size == sizeof(t_op))
					return ((((t_op *)list->content))->position - position);
				list = list->next;
			}
		}
		list = list->next;
	}
	error(LABEL_NOT_FOUND);
	return (0);
}
