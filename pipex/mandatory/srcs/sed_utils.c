/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:44:54 by suhwpark          #+#    #+#             */
/*   Updated: 2023/02/16 17:55:29 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	sed_get_pos(int *p, char *argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (argv[i] == '\"')
		{
			p[0] = i + 1;
			break ;
		}
	}
	i = -1;
	while (argv[++i + p[0]])
	{
		if (argv[++i + p[0]] == '\"')
		{
			p[1] = i + p[0] - 1;
			break ;
		}
	}
}

void	sed_execve(char **path, char *argv, char **envp)
{
	char	**cmd;
	char	**tmp;
	char	*v_p;
	int		p[2];

	tmp = ft_split(argv, ' ');
	if (!tmp)
		ft_perror("allocated failed");
	v_p = get_cmd_path(path, tmp[0]);
	if (!v_p)
		ft_perror("path error");
	sed_get_pos(p, argv);
	cmd = (char **)ft_safe_malloc(sizeof(char *) * 3);
	cmd[0] = ft_strdup(tmp[0]);
	cmd[1] = ft_substr(argv, p[0], (p[1] - p[0] + 1));
	cmd[2] = NULL;
	ft_free(tmp);
	execve(v_p, cmd, envp);
}
