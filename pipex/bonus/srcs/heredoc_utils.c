/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:42:44 by suhwpark          #+#    #+#             */
/*   Updated: 2023/02/14 20:54:11 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_pipex.h"

int	is_here_doc(char *argv)
{
	if (ft_strlen(argv) != 8)
		return (FALSE);
	if (ft_strncmp(argv, "here_doc", ft_strlen(argv)) != 0)
		return (FALSE);
	return (TRUE);
}

void	here_doc(char *limiter)
{
	int		fd;
	char	*line;

	fd = open(".here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		ft_perror("here_doc failed");
	while (1)
	{
		write(1, "here doc> ", 10);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL || ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
	fd = open(".here_doc", O_RDONLY);
	if (fd == -1)
	{
		unlink(".here_doc");
		ft_perror("here_doc failed");
	}
	dup2(fd, STDIN_FILENO);
}
