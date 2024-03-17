/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:22:41 by suhwpark          #+#    #+#             */
/*   Updated: 2023/02/16 17:16:42 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	argv1_process(char **path, char **argv, char **envp, int fd[])
{
	int		infile_fd;

	close(fd[0]);
	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd == -1)
		ft_perror("open error");
	(dup2(infile_fd, STDIN_FILENO), close(infile_fd));
	(dup2(fd[1], STDOUT_FILENO), close(fd[1]));
	execve_path(path, argv[2], envp);
}

static void	argv2_process(char **path, char **argv, char **envp, int fd[])
{
	int		outfile_fd;

	close(fd[1]);
	outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
		ft_perror("open error");
	(dup2(fd[0], STDIN_FILENO), close(fd[0]));
	(dup2(outfile_fd, STDOUT_FILENO), close(outfile_fd));
	execve_path(path, argv[3], envp);
}

void	pipex(char **path, char **argv, char **envp)
{
	pid_t	pid;
	int		i;
	int		status;
	int		fd[2];

	i = 0;
	if (pipe(fd) == -1)
		ft_perror("pipe failed");
	while (++i < 3)
	{
		pid = fork();
		if (pid == -1)
			ft_perror("fork failed");
		if (pid == 0 && i == 1)
			argv1_process(path, argv, envp, fd);
		if (pid == 0 && i == 2)
			argv2_process(path, argv, envp, fd);
	}
	(close(fd[0]), close(fd[1]));
	while (1)
	{
		if (wait(&status) == -1)
			return ;
	}
}
