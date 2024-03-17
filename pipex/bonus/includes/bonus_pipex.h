/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipex.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:20:15 by suhwpark          #+#    #+#             */
/*   Updated: 2023/02/20 14:58:32 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PIPEX_H
# define BONUS_PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "get_next_line.h"
# define FALSE 0
# define TRUE 1

int		error(char *message);
char	*get_cmd_path(char **path, char *cmd);
void	pipex(int argc, char **path, char **argv, char **envp);
void	ft_perror(char *e);
void	execve_path(char **path, char *argv, char **envp);
int		is_here_doc(char *argv);
void	here_doc(char *limiter);
int		check_vaild_command(char *argv);
#endif