/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_2to5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:14:06 by abettini          #+#    #+#             */
/*   Updated: 2023/03/10 10:23:50 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_deal_2(t_stack **stack, t_stack **stack2)
{
	if ((*stack)->n > (*stack)->next->n)
		ft_dorot(stack, stack2, 0);
}

void	ft_deal_3(t_stack **stack, t_stack **stack2)
{
	if (!ft_order_check(*stack))
	{
		if ((*stack)->n < (*stack)->next->n)
		{
			ft_dorevrot(stack, stack2, 0);
			if ((*stack)->next->n < (*stack)->n)
				ft_doswap(stack, stack2, 0);
		}
		else if ((*stack)->n > (*stack)->next->n && \
				(*stack)->n > (*stack)->prev->n)
		{
			if ((*stack)->next->n > (*stack)->prev->n)
			{
				ft_doswap(stack, stack2, 0);
				ft_dorevrot(stack, stack2, 0);
			}
			else
				ft_dorot(stack, stack2, 0);
		}
		else if ((*stack)->n > (*stack)->next->n)
			ft_doswap(stack, stack2, 0);
	}
}

void	ft_deal_4_5(t_stack **a, t_stack **b)
{
	int	size_a;
	int	j;

	size_a = ft_stack_size(*a);
	j = size_a;
	while (j-- > 3)
	{
		if (ft_find_smallest_pos(*a) > size_a / 2 + 1)
		{
			while (ft_find_smallest_pos(*a) != 1)
				ft_dorevrot(a, b, 0);
		}
		else
		{
			while (ft_find_smallest_pos(*a) != 1)
				ft_dorot(a, b, 0);
		}
		ft_dopush(a, b, 1);
	}
	ft_deal_3(a, b);
	while (++j < size_a)
		ft_dopush(a, b, 0);
	ft_last_rot(a, b);
}
