/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:51:57 by suhwpark          #+#    #+#             */
/*   Updated: 2023/01/29 17:22:57 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/queue.h"

void	visit_left(t_info *info, t_visit *visit_info,
	t_queue *queue, t_node *point)
{
	if ((info->map)[point->y][point->x - 1] != '1' &&
		(info->map)[point->y][point->x - 1] != 'E')
	{
		enqueue(queue, point->x - 1, point->y);
		visit_info->visited[point->y][point->x - 1] = 1;
	}
	if ((info->map)[point->y][point->x - 1] == 'C')
		visit_info->collect_cnt++;
	if ((info->map)[point->y][point->x - 1] == 'E')
	{
		visit_info->visited[point->y][point->x - 1] = 1;
		visit_info->exit_cnt++;
	}
}

void	visit_right(t_info *info, t_visit *visit_info,
	t_queue *queue, t_node *point)
{
	if ((info->map)[point->y][point->x + 1] != '1' &&
		(info->map)[point->y][point->x + 1] != 'E')
	{
		enqueue(queue, point->x + 1, point->y);
		visit_info->visited[point->y][point->x + 1] = 1;
	}
	if ((info->map)[point->y][point->x + 1] == 'C')
		visit_info->collect_cnt++;
	if ((info->map)[point->y][point->x + 1] == 'E')
	{
		visit_info->visited[point->y][point->x + 1] = 1;
		visit_info->exit_cnt++;
	}
}

void	visit_down(t_info *info, t_visit *visit_info,
	t_queue *queue, t_node *point)
{
	if ((info->map)[point->y - 1][point->x] != '1' &&
		(info->map)[point->y - 1][point->x] != 'E')
	{
		enqueue(queue, point->x, point->y - 1);
		visit_info->visited[point->y - 1][point->x] = 1;
	}
	if ((info->map)[point->y - 1][point->x] == 'C')
		visit_info->collect_cnt++;
	if ((info->map)[point->y - 1][point->x] == 'E')
	{
		visit_info->visited[point->y - 1][point->x] = 1;
		visit_info->exit_cnt++;
	}
}

void	visit_up(t_info *info, t_visit *visit_info,
	t_queue *queue, t_node *point)
{
	if ((info->map)[point->y + 1][point->x] != '1' &&
		(info->map)[point->y + 1][point->x] != 'E')
	{
		enqueue(queue, point->x, point->y + 1);
		visit_info->visited[point->y + 1][point->x] = 1;
	}
	if ((info->map)[point->y + 1][point->x] == 'C')
		visit_info->collect_cnt++;
	if ((info->map)[point->y + 1][point->x] == 'E')
	{
		visit_info->visited[point->y + 1][point->x] = 1;
		visit_info->exit_cnt++;
	}
}
