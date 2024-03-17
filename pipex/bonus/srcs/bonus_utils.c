/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:23:21 by suhwpark          #+#    #+#             */
/*   Updated: 2023/02/20 14:59:17 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_pipex.h"

int	check_vaild_command(char *argv)
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
