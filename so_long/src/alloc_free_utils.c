/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_free_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:09:13 by suhwpark          #+#    #+#             */
/*   Updated: 2023/01/29 17:22:32 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/queue.h"

void	*safe_malloc(size_t	size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
	{
		ft_putendl_fd("malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	return (ret);
}

void	ft_free(int **p)
{
	int	i;

	i = 0;
	while (p[i])
		free(p[i++]);
	free(p);
}

void	free_t_visit(t_visit *visit_info)
{
	ft_free(visit_info->visited);
	free(visit_info);
}
