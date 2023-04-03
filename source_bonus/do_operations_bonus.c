/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:00:53 by lamici            #+#    #+#             */
/*   Updated: 2023/03/10 10:45:48 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_dopush(t_stack **a, t_stack **b, int type)
{
	if (type == 0)
		ft_push(a, b);
	else if (type == 1)
		ft_push(b, a);
}

void	ft_doswap(t_stack **a, t_stack **b, int type)
{
	if (type == 0)
		ft_swap(a);
	else if (type == 1)
		ft_swap(b);
	else if (type == 2)
	{
		ft_swap(a);
		ft_swap(b);
	}
}

void	ft_dorot(t_stack **a, t_stack **b, int type)
{
	if (type == 0)
		ft_rotate(a);
	else if (type == 1)
		ft_rotate(b);
	else if (type == 2)
	{
		ft_rotate(a);
		ft_rotate(b);
	}
}

void	ft_dorevrot(t_stack **a, t_stack **b, int type)
{
	if (type == 0)
		ft_rev_rotate(a);
	else if (type == 1)
		ft_rev_rotate(b);
	else if (type == 2)
	{
		ft_rev_rotate(a);
		ft_rev_rotate(b);
	}
}
