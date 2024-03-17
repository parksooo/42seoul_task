/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:59:37 by suhwpark          #+#    #+#             */
/*   Updated: 2023/01/29 17:23:16 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/queue.h"

static int	**allocated_visited(int row, int column)
{
	int	**visited;
	int	i;

	visited = (int **)malloc(sizeof(int *) * (column + 1));
	i = -1;
	while (++i < column)
		visited[i] = (int *)ft_calloc(sizeof(int), row);
	visited[i] = NULL;
	return (visited);
}

static t_visit	*init_visit_info(int row, int column)
{
	t_visit	*visit;

	visit = (t_visit *)safe_malloc(sizeof(t_visit));
	visit->visited = allocated_visited(row, column);
	visit->collect_cnt = 0;
	visit->exit_cnt = 0;
	return (visit);
}

static void	start_visit(t_info *info, t_queue *queue, t_visit *visit_info)
{
	t_node	*point;

	while (!is_empty(queue))
	{
		point = dequeue(queue);
		if (point->x - 1 >= 0)
			if (visit_info->visited[point->y][point->x - 1] == 0)
				visit_left(info, visit_info, queue, point);
		if (point->x + 1 < info->width)
			if (visit_info->visited[point->y][point->x + 1] == 0)
				visit_right(info, visit_info, queue, point);
		if (point->y - 1 >= 0)
			if (visit_info->visited[point->y - 1][point->x] == 0)
				visit_down(info, visit_info, queue, point);
		if (point->y + 1 < info->height)
			if (visit_info->visited[point->y + 1][point->x] == 0)
				visit_up(info, visit_info, queue, point);
		free(point);
	}
}

int	bfs(t_info *info)
{
	t_queue	*queue;
	t_visit	*visit_info;

	queue = init_queue();
	visit_info = init_visit_info(info->width, info->height);
	enqueue(queue, info->pos[1], info->pos[0]);
	visit_info->visited[info->pos[0]][info->pos[1]] = 1;
	start_visit(info, queue, visit_info);
	clear_queue(queue);
	free_t_visit(visit_info);
	if (visit_info->collect_cnt != info->collect || visit_info->exit_cnt != 1)
		return (0);
	return (1);
}
