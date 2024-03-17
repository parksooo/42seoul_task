/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:28:31 by suhwpark          #+#    #+#             */
/*   Updated: 2022/12/12 21:04:15 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	t_node	*find_fd(t_list *list, int fd)
{
	int	i;

	if (!list->tail)
		return (NULL);
	i = 0;
	while (i < list->nod_count)
	{
		if (list->curr->fd == fd)
			return (list->curr);
		list->before = list->curr;
		list->curr = list->curr->next;
		i++;
	}
	return (NULL);
}

static int	add_list_fd(t_list *list, int fd)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (-1);
	new->fd = fd;
	new->back_up = (char *)malloc(1);
	if (!new->back_up)
	{
		free(new);
		return (-1);
	}
	*(new->back_up) = '\0';
	if (!list->tail)
	{
		list->tail = new;
		new->next = new;
	}
	new->next = list->tail->next;
	list->tail->next = new;
	list->before = list->tail;
	list->tail = new;
	list->curr = new;
	(list->nod_count)++;
	return (0);
}

char	*read_files(t_list *list, char *buf)
{
	int		read_byte;
	char	*tmp;

	while (1)
	{
		read_byte = read(list->curr->fd, buf, BUFFER_SIZE);
		if (read_byte == 0)
			break ;
		if (read_byte == -1)
			return (NULL);
		buf[read_byte] = '\0';
		tmp = list->curr->back_up;
		list->curr->back_up = ft_strjoin(list->curr->back_up, buf);
		free(tmp);
		if (!list->curr->back_up)
			return (NULL);
		if (ft_strchr(list->curr->back_up, '\n'))
			break ;
	}
	if (list->curr->back_up[0] == '\0')
		return (NULL);
	free(buf);
	return (list->curr->back_up);
}

char	*substring_line(t_list *list)
{
	char	*line;
	char	*back_up;
	char	*tmp;
	int		i;

	back_up = list->curr->back_up;
	i = 0;
	while (back_up[i] != '\n' && back_up[i] != '\0')
		i++;
	line = ft_substr(back_up, 0, i + 1);
	if (line && back_up[i] == '\n' && back_up[i + 1] != '\0')
	{
		tmp = ft_substr(back_up, i + 1, ft_strlen(back_up) - i - 1);
		if (!tmp)
		{
			free(line);
			return (remove_fd(list));
		}
		free(list->curr->back_up);
		list->curr->back_up = tmp;
	}
	else
		remove_fd(list);
	return (line);
}

char	*get_next_line(int fd)
{
	char			*buf;
	char			*line;
	static t_list	list;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!find_fd(&list, fd))
	{
		if (add_list_fd(&list, fd) == -1)
			return (NULL);
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (remove_fd(&list));
	if (!read_files(&list, buf))
	{
		free(buf);
		return (remove_fd(&list));
	}
	line = substring_line(&list);
	return (line);
}
