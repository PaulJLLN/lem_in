/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:12:38 by pauljull          #+#    #+#             */
/*   Updated: 2020/01/28 16:27:19 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static void	ft_slide(t_queue *bfs_queue)
{
	size_t	index;

	index = 1;
	while (index < bfs_queue->index)
	{
		bfs_queue->queue[index - 1] = bfs_queue->queue[index];
		index += 1;
	}
}

static void	ft_slide_down(t_queue *bfs_queue)
{
	size_t	index;

	index = bfs_queue->index;
	while (index > 0)
	{
		bfs_queue->queue[index] = bfs_queue->queue[index - 1];
		index -= 1;
	}
}

t_room		*ft_remove_queue(t_queue *bfs_queue)
{
	t_room	*unqueue;

	unqueue = bfs_queue->queue[0];
	ft_slide(bfs_queue);
	bfs_queue->index -= 1;
	return (unqueue);
}

int			*ft_add_front_queue(t_queue *bfs_queue, t_room *to_add, t_room *current)
{
	to_add->prev = current;
	ft_slide_down(bfs_queue);
	bfs_queue->queue[0] = to_add;
	bfs_queue->index += 1;
	if (to_add->features != IS_START && to_add->features != IS_END)
		to_add->features = QUEUE;
	return ((int *)1);
}

void		ft_swap(t_queue *bfs_queue, int i_1, int i_2)
{
	t_room *tmp;

	tmp = bfs_queue->queue[i_1];
	bfs_queue->queue[i_1] = bfs_queue->queue[i_2];
	bfs_queue->queue[i_2] = tmp;
}

void		ft_reposition(t_queue *bfs_queue)
{
	int		index;

	index = bfs_queue->index - 1;
	while (index > 0 && bfs_queue->queue[index]->time < bfs_queue->queue[index - 1]->time)
	{
		ft_swap(bfs_queue, index, index - 1);
		index -= 1;
	}
}

void		ft_add_queue(t_queue *bfs_queue, t_room *to_add, t_room *current, int time)
{
	if (current && (to_add->features == UNQUEUE || to_add->features == IS_END || to_add->time > (current->time + time)))
	{
		to_add->prev = current;
		to_add->time = current->time + time;
	}
	if (to_add->features == UNQUEUE || to_add->features == IS_END)
	{
		bfs_queue->queue[bfs_queue->index] = to_add;
		bfs_queue->index += 1;
		if (to_add->features != IS_END && to_add->features != IS_START)
			to_add->features = QUEUE;
		ft_reposition(bfs_queue);
	}
}