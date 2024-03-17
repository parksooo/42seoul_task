/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:29:03 by suhwpark          #+#    #+#             */
/*   Updated: 2022/12/12 21:06:28 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				fd;
	char			*back_up;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	t_node	*tail;
	t_node	*curr;
	t_node	*before;
	int		nod_count;
}	t_list;

char		*get_next_line(int fd);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strchr(const char *str, int c);
char		*ft_substr(char const *src, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);
char		*remove_fd(t_list *list);
#endif