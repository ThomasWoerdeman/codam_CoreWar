/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: twoerdem <twoerdem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 07:49:53 by twoerdem       #+#    #+#                */
/*   Updated: 2019/12/16 14:45:46 by twoerdem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*get_correct_fd(int fd, t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(list, tmp);
	tmp = *list;
	return (tmp);
}

static int		read_line(t_list *current, char **line)
{
	int			len;

	if (ft_strncmp(current->content, "\n", 1) == 0)
	{
		*line = ft_strdup("\0");
		current->content = ft_memmove(current->content, current->content + 1, \
		ft_strlen(current->content));
		return (1);
	}
	len = ft_strlchr(current->content, '\n');
	if (len == -1)
	{
		*line = ft_strdup(current->content);
		free(current->content);
		current->content = ft_strdup("\0");
		return (1);
	}
	*line = ft_strsub(current->content, 0, len);
	current->content = ft_memmove(current->content, \
		current->content + len + 1, ft_strlen(current->content));
	return (1);
}

static char		*join_string(char *content, char *buf)
{
	char *ret;

	ret = ft_strjoin(content, buf);
	free(content);
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*list;
	t_list			*current;
	int				ret;
	int				c;

	ret = read(fd, buf, BUFF_SIZE);
	if (ret < 0 || line == NULL)
		return (-1);
	current = get_correct_fd(fd, &list);
	while (ret)
	{
		buf[ret] = '\0';
		current->content = join_string(current->content, buf);
		if (ft_strchr(buf, '\n'))
			break ;
		ret = read(fd, buf, BUFF_SIZE);
	}
	if (ret == 0 && ft_strlen(current->content) == 0)
	{
		return (0);
	}
	c = read_line(current, line);
	return (c);
}
