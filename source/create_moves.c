/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:46:44 by lamici            #+#    #+#             */
/*   Updated: 2023/03/08 09:46:46 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_array_a(t_stack *a, t_stack *b)
{
	int	*ar_a;
	int	size;
	int	i;
	int	bnum;

	i = 0;
	size = ft_stack_size(b);
	ar_a = malloc(sizeof(int) * ft_stack_size(b));
	while (i < size)
	{
		bnum = b->n;
		ar_a[i] = ft_findnum(bnum, a);
		ft_rotate(&b);
		i++;
	}
	return (ar_a);
}

int	*ft_array_b(t_stack *b)
{
	int	*ar_b;
	int	size;
	int	i;

	size = ft_stack_size(b);
	i = 0;
	ar_b = malloc(sizeof(int) * size);
	if (size > 0)
	{
		i = 0;
		while (i < (size / 2))
		{
			ar_b[size - i - 1] = (i + 1) * -1;
			i++;
		}
		i = 0;
		while (i < (size / 2) + 1)
		{
			ar_b[i] = i;
			i++;
		}
	}
	return (ar_b);
}

int	ft_minmax(int a, int b)
{
	int	max;

	if (a >= 0 && b >= 0)
	{
		if (a >= b)
			max = a;
		else
			max = b;
	}
	if (a < 0 && b < 0)
	{
		if (a <= b)
			max = a;
		else
			max = b;
	}
	return (max);
}

int	ft_find_move_value(int a, int b)
{
	int	moves;

	moves = 0;
	if (a >= 0 && b >= 0)
		moves = ft_minmax(a, b);
	else if (a < 0 && b < 0)
		moves = (ft_minmax(a, b) * -1);
	else if (a >= 0 && b < 0)
		moves = (b * -1) + a;
	else if (a < 0 && b >= 0)
		moves = (a * -1) + b;
	return (moves);
}

void	ft_arraygaming(t_stack **a, t_stack **b)
{
	int	*ar_a;
	int	*ar_b;
	int	pos;
	int	x;
	int	y;

	ar_b = ft_array_b(*b);
	ar_a = ft_array_a(*a, *b);
	x = 0;
	y = ft_find_move_value(ar_a[x], ar_b[x]);
	pos = 0;
	while (x < ft_stack_size(*b))
	{
		if (ft_find_move_value(ar_a[x], ar_b[x]) < y)
		{
			y = ft_find_move_value(ar_a[x], ar_b[x]);
			pos = x;
		}
		x++;
	}
	ft_execute_moves(a, b, ar_a[pos], ar_b[pos]);
	free(ar_a);
	free(ar_b);
}
