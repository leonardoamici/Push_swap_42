/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:34:15 by abettini          #+#    #+#             */
/*   Updated: 2023/03/10 10:47:07 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
