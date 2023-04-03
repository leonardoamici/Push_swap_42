/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:34:15 by abettini          #+#    #+#             */
/*   Updated: 2023/02/13 16:34:17 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	if (*stack)
		*stack = (*stack)->next;
}

void	ft_rev_rotate(t_stack **stack)
{
	if (*stack)
		*stack = (*stack)->prev;
}
