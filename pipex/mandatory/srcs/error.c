/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:27:35 by suhwpark          #+#    #+#             */
/*   Updated: 2023/02/08 19:58:06 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	error(char *message)
{
	ft_putendl_fd(message, STDERR_FILENO);
	return (EXIT_FAILURE);
}

void	ft_perror(char *e)
{
	perror(e);
	exit(EXIT_FAILURE);
}
