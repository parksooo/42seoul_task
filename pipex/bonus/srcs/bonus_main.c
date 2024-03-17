/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:18:39 by suhwpark          #+#    #+#             */
/*   Updated: 2023/02/09 15:47:48 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_pipex.h"

static char	**find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (!envp[i])
		return (NULL);
	return (ft_split((envp[i] + 5), ':'));
}

int	main(int argc, char **argv, char **envp)
{
	char	**path;

	if (argc < 5)
		exit(error("Few arguments"));
	path = find_path(envp);
	pipex(argc, path, argv, envp);
	return (0);
}
