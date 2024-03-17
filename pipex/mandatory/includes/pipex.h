/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:20:15 by suhwpark          #+#    #+#             */
/*   Updated: 2023/02/20 14:57:20 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# define FALSE 0
# define TRUE 1

int		error(char *message);
char	*get_cmd_path(char **path, char *cmd);
void	pipex(char **path, char **argv, char **envp);
void	ft_perror(char *e);
void	execve_path(char **path, char *argv, char **envp);
void	sed_execve(char **path, char *argv, char **envp);
#endif