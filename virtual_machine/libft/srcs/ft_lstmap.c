/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 20:23:16 by dfreire        #+#    #+#                */
/*   Updated: 2019/01/24 17:56:23 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;
	t_list *tmp;
	t_list *new;

	if (!lst || !f)
		return (0);
	new = f(lst);
	if ((fresh = ft_lstnew(new->content, new->content_size)))
	{
		tmp = fresh;
		lst = lst->next;
		while (lst != NULL)
		{
			new = f(lst);
			if (!(tmp->next = ft_lstnew(new->content, new->content_size)))
				return (0);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (fresh);
}
