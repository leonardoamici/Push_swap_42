/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:57:02 by lamici            #+#    #+#             */
/*   Updated: 2023/03/10 10:46:27 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_check_op_2(char *op, t_stack **a, t_stack **b)
{
	if (op)
	{
		if (!ft_strcmp(op, "rra\n"))
			ft_dorevrot(a, b, 0);
		else if (!ft_strcmp(op, "rrb\n"))
			ft_dorevrot(a, b, 1);
		else if (!ft_strcmp(op, "rrr\n"))
			ft_dorevrot(a, b, 2);
		else if (!ft_strcmp(op, "sa\n"))
			ft_doswap(a, b, 0);
		else if (!ft_strcmp(op, "sb\n"))
			ft_doswap(a, b, 1);
		else if (!ft_strcmp(op, "ss\n"))
			ft_doswap(a, b, 2);
		else
			ft_close();
	}
}

void	ft_check_op_1(char *op, t_stack **a, t_stack **b)
{
	if (op)
	{
		if (!ft_strcmp(op, "ra\n"))
			ft_dorot(a, b, 0);
		else if (!ft_strcmp(op, "rb\n"))
			ft_dorot(a, b, 1);
		else if (!ft_strcmp(op, "rr\n"))
			ft_dorot(a, b, 2);
		else if (!ft_strcmp(op, "pa\n"))
			ft_dopush(a, b, 0);
		else if (!ft_strcmp(op, "pb\n"))
			ft_dopush(a, b, 1);
		else
			ft_check_op_2(op, a, b);
	}
}
