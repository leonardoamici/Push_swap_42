/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:31:33 by abettini          #+#    #+#             */
/*   Updated: 2023/03/10 10:46:45 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_self_link(t_stack **stack)
{
	(*stack)->next = *stack;
	(*stack)->prev = *stack;
}

void	ft_push(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if (*src)
	{
		temp = *src;
		if (ft_stack_size(*src) >= 2)
		{
			(*src)->next->prev = (*src)->prev;
			(*src)->prev->next = (*src)->next;
			*src = (*src)->next;
		}
		else
			*src = NULL;
		if (*dest)
		{
			temp->next = *dest;
			temp->prev = (*dest)->prev;
			(*dest)->prev->next = temp;
			(*dest)->prev = temp;
		}
		else
			ft_self_link(&temp);
		*dest = temp;
	}
}
