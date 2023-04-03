/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:06:39 by lamici            #+#    #+#             */
/*   Updated: 2023/03/07 09:07:26 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dopush(t_stack **a, t_stack **b, int type)
{
	if (type == 0)
	{
		ft_push(a, b);
		ft_printf("pa\n");
	}
	else if (type == 1)
	{
		ft_push(b, a);
		ft_printf("pb\n");
	}
}

void	ft_doswap(t_stack **a, t_stack **b, int type)
{
	if (type == 0)
	{
		ft_swap(a);
		ft_printf("sa\n");
	}
	else if (type == 1)
	{
		ft_swap(b);
		ft_printf("sb\n");
	}
	else if (type == 2)
	{
		ft_swap(a);
		ft_swap(b);
		ft_printf("ss\n");
	}
}

void	ft_dorot(t_stack **a, t_stack **b, int type)
{
	if (type == 0)
	{
		ft_rotate(a);
		ft_printf("ra\n");
	}
	else if (type == 1)
	{
		ft_rotate(b);
		ft_printf("rb\n");
	}
	else if (type == 2)
	{
		ft_rotate(a);
		ft_rotate(b);
		ft_printf("rr\n");
	}
}

void	ft_dorevrot(t_stack **a, t_stack **b, int type)
{
	if (type == 0)
	{
		ft_rev_rotate(a);
		ft_printf("rra\n");
	}
	else if (type == 1)
	{
		ft_rev_rotate(b);
		ft_printf("rrb\n");
	}
	else if (type == 2)
	{
		ft_rev_rotate(a);
		ft_rev_rotate(b);
		ft_printf("rrr\n");
	}
}
