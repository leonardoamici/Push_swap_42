/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_index_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:26:26 by lamici            #+#    #+#             */
/*   Updated: 2023/03/10 10:45:42 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_findindex(t_stack **stack)
{
	int	x;
	int	z;
	int	ret;

	ret = 1;
	x = ft_stack_size(*stack);
	z = (*stack)->n;
	while (x > 0)
	{
		(*stack) = (*stack)->next;
		if (z > (*stack)->n)
			ret++;
		x--;
	}
	return (ret);
}

void	ft_putindex(t_stack **stack)
{
	int		x;

	x = ft_stack_size(*stack);
	while (x > 0)
	{
		(*stack)->index = ft_findindex(stack);
		(*stack) = (*stack)->next;
		x--;
	}
}
