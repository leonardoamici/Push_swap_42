/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:43:02 by lamici            #+#    #+#             */
/*   Updated: 2023/03/10 10:24:08 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(t_stack *first, t_stack *moveman)
{
	int		x;
	int		count;
	int		countrev;
	t_stack	*temp;

	temp = moveman;
	count = 0;
	countrev = 0;
	x = first->n;
	while (x != temp->n)
	{
		ft_rotate(&temp);
		count++;
	}
	temp = moveman;
	while (x != temp->n)
	{
		ft_rev_rotate(&temp);
		countrev--;
	}
	if ((countrev * -1) < count)
		return (countrev);
	return (count);
}

t_stack	*ft_findsmallest(t_stack *a)
{
	int		x;
	int		n;
	t_stack	*temp;

	temp = a;
	x = ft_stack_size(a);
	if (!a)
		return (NULL);
	n = a->n;
	while (x--)
	{
		if (a->n < n)
		{
			temp = a;
			n = a->n;
		}
		ft_rotate(&a);
	}
	return (temp);
}

int	ft_findnum(int x, t_stack *a)
{
	int		bnum;
	int		size;
	int		i;
	t_stack	*temp;

	i = 0;
	size = ft_stack_size(a);
	temp = a;
	bnum = ft_count(ft_findsmallest(temp), a);
	while (i < size)
	{
		if (temp->n > x && temp->prev->n < x)
		{
			if (i > (size / 2 + 1))
				bnum = i - size;
			else
				bnum = i;
		}
		ft_rotate(&temp);
		i++;
	}
	return (bnum);
}

void	ft_push_swap(t_stack **a, t_stack **b)
{
	int	x;
	int	y;
	int	z;

	z = ft_stack_size(*b);
	while (z--)
	{
		y = ft_order_check(*a);
		x = ft_order_check(*b);
		if (y == 1 && x == -1)
			break ;
		ft_arraygaming(a, b);
	}
	ft_last_rot(a, b);
}
