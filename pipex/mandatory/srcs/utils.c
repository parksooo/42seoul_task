/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:23:21 by suhwpark          #+#    #+#             */
/*   Updated: 2023/02/20 14:57:16 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	check_vaild_command(char *argv)
{
	int	i;
	int	len;

	len = ft_strlen(argv) - 1;
	i = 5;
	while (argv[i] && argv[i] != '{')
		i++;
	if (argv[i - 1] != '\'' && argv[i - 1] != '\"' && argv[i - 1] != ' ')
		return (FALSE);
	return (TRUE);
}

static void	awk_get_pos(int *p, char *argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (argv[i] == '{')
			p[0] = i;
		if (argv[i] == '}')
			p[1] = i;
	}
}

static void	awk_execve(char **path, char *argv, char **envp)
{
	char	**cmd;
	char	**tmp;
	char	*v_p;
	int		p[2];

	if (!check_vaild_command(argv))
		ft_perror("invalided command");
	tmp = ft_split(argv, ' ');
	if (!tmp)
		ft_perror("allocated failed");
	v_p = get_cmd_path(path, tmp[0]);
	if (!v_p)
		ft_perror("path error");
	awk_get_pos(p, argv);
	cmd = (char **)ft_safe_malloc(sizeof(char *) * 3);
	cmd[0] = ft_strdup(tmp[0]);
	cmd[1] = ft_substr(argv, p[0], (p[1] - p[0] + 1));
	cmd[2] = NULL;
	ft_free(tmp);
	execve(v_p, cmd, envp);
}

char	*get_cmd_path(char **path, char *cmd)
{
	int		i;
	int		fd;
	char	*cmd_path;
	char	*tmp;

	cmd_path = ft_strjoin("/", cmd);
	i = -1;
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], cmd_path);
		fd = access(tmp, X_OK);
		if (fd != -1)
		{
			free(cmd_path);
			return (tmp);
		}
		close(fd);
		free(tmp);
	}
	free(cmd_path);
	return (NULL);
}

void	execve_path(char **path, char *argv, char **envp)
{
	char	**cmd;
	char	*v_p;

	if (!ft_strncmp(argv, "awk ", 4))
		awk_execve(path, argv, envp);
	if (!ft_strncmp(argv, "sed ", 4))
		sed_execve(path, argv, envp);
	cmd = ft_split(argv, ' ');
	if (!cmd)
		exit(error("allocated failed"));
	v_p = get_cmd_path(path, cmd[0]);
	if (!v_p)
		ft_perror("path error");
	execve(v_p, cmd, envp);
}
