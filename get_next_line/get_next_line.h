/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:40:10 by suhwpark          #+#    #+#             */
/*   Updated: 2022/12/09 14:34:19 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strdup(const char *str);
char		*ft_strchr(const char *str, int c);
char		*ft_substr(char const *src, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);
#endif