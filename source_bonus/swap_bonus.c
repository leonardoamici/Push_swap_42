/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:32:34 by abettini          #+#    #+#             */
/*   Updated: 2023/03/10 10:47:18 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*temp;

	if (*stack && (*stack) != (*stack)->next)
	{
		if ((*stack)->next == (*stack)->prev)
			(*stack) = (*stack)->next;
		else
		{
			temp = (*stack)->prev;
			(*stack)->prev = (*stack)->next;
			(*stack)->next = (*stack)->next->next;
			(*stack)->next->prev = (*stack);
			temp->next = (*stack)->prev;
			temp->next->prev = temp;
			temp->next->next = (*stack);
			(*stack) = temp->next;
		}
	}
}
