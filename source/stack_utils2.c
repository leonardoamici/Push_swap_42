/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:28:13 by lamici            #+#    #+#             */
/*   Updated: 2023/03/08 09:28:15 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_intset(int **arr, int value, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		(*arr)[i] = value;
		i++;
	}
}

int	ft_n_at_pos(t_stack *stack, int pos)
{
	while (--pos > 0 && stack)
		stack = stack->next;
	if (stack)
		return (stack->n);
	return (0);
}

int	ft_pos_with_n(t_stack *stack, int n)
{
	int	pos;
	int	size;

	pos = 0;
	if (stack)
	{
		pos++;
		size = ft_stack_size(stack);
		while (stack->n != n && pos < size)
		{
			pos++;
			stack = stack->next;
		}
		if (stack->n == n)
			return (pos);
	}
	return (0);
}

int	ft_find_max_i(int *arr, int size)
{
	int	i;
	int	max_i;
	int	temp;

	temp = arr[0];
	max_i = 0;
	i = 0;
	while (i < size)
	{
		if (arr[i] > temp)
		{
			temp = arr[i];
			max_i = i;
		}
		i++;
	}
	return (max_i);
}

int	ft_find_int(int *arr, int value, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (1);
		i++;
	}
	return (0);
}
