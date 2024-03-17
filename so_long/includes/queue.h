/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:00:39 by suhwpark          #+#    #+#             */
/*   Updated: 2023/01/29 17:23:40 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>
# include "so_long.h"

typedef struct s_visit
{
	int	**visited;
	int	collect_cnt;
	int	exit_cnt;
}	t_visit;

typedef struct s_node
{
	int				x;
	int				y;
	struct s_node	*next;
}	t_node;

typedef struct s_queue
{
	t_node	*front;
	t_node	*rear;
}	t_queue;

t_queue	*init_queue(void);
t_node	*enqueue(t_queue *queue, int x, int y);
t_node	*dequeue(t_queue *queue);
int		is_empty(t_queue *queue);
void	clear_queue(t_queue *queue);
void	*safe_malloc(size_t	size);
void	visit_left(t_info *info, t_visit *visit_info,
			t_queue *queue, t_node *point);
void	visit_right(t_info *info, t_visit *visit_info,
			t_queue *queue, t_node *point);
void	visit_down(t_info *info, t_visit *visit_info,
			t_queue *queue, t_node *point);			
void	visit_up(t_info *info, t_visit *visit_info,
			t_queue *queue, t_node *point);
void	ft_free(int **p);
void	free_t_visit(t_visit *visit_info);
#endif