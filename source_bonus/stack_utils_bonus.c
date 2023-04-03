/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:07:29 by abettini          #+#    #+#             */
/*   Updated: 2023/03/10 10:47:13 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_stack_size(t_stack *stack)
{
	t_stack	*temp;
	int		size;

	size = 0;
	if (stack)
	{
		size++;
		temp = stack;
		while (temp->next != stack)
		{
			temp = temp->next;
			size++;
		}
	}
	return (size);
}

int	ft_order_check(t_stack *stack)
{
	int		size;

	size = ft_stack_size(stack);
	if (stack)
	{
		while (size > 1)
		{
			if (stack->n > stack->next->n)
				return (0);
			stack = stack->next;
			size--;
		}
		return (1);
	}
	return (-1);
}

int	ft_find_smallest_pos(t_stack *stack)
{
	t_stack	*smallest;
	int		size;
	int		pos;
	int		j;

	pos = 0;
	if (stack)
	{
		pos++;
		smallest = stack;
		size = ft_stack_size(stack);
		j = 0;
		while (j < size)
		{
			if (stack->n < smallest->n)
			{
				pos = j + 1;
				smallest = stack;
			}
			stack = stack->next;
			j++;
		}
	}
	return (pos);
}

int	ft_find_shortest_path(t_stack *pos, t_stack *dest)
{
	t_stack	*temp;
	int		y;
	int		x;
	int		path;

	temp = pos;
	path = temp->index;
	while (path != dest->index)
	{
		temp = temp->next;
		path = temp->index;
		x++;
	}
	temp = pos;
	path = temp->index;
	while (path != dest->index)
	{
		temp = temp->prev;
		path = temp->index;
		y++;
	}
	if (y >= x)
		return (ROT);
	return (RROT);
}
