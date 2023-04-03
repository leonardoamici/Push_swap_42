/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:12:23 by lamici            #+#    #+#             */
/*   Updated: 2023/03/07 09:33:34 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dual_rot(t_stack **a, t_stack **b, int *moves_a, int *moves_b)
{
	while (*moves_a > 0 && *moves_b > 0)
	{
		ft_dorot(a, b, 2);
		(*moves_a)--;
		(*moves_b)--;
	}
}

void	ft_dual_rev_rot(t_stack **a, t_stack **b, int *moves_a, int *moves_b)
{
	while (*moves_a < 0 && *moves_b < 0)
	{
		ft_dorevrot(a, b, 2);
		(*moves_a)++;
		(*moves_b)++;
	}
}

void	ft_do_a(t_stack **a, t_stack **b, int *moves_a)
{
	if (*moves_a > 0)
	{
		while (*moves_a > 0)
		{
			ft_dorot(a, b, 0);
			(*moves_a)--;
		}
	}
	else if (*moves_a < 0)
	{
		while (*moves_a < 0)
		{
			ft_dorevrot(a, b, 0);
			(*moves_a)++;
		}
	}
}

void	ft_do_b(t_stack **a, t_stack **b, int *moves_b)
{
	if (*moves_b > 0)
	{
		while (*moves_b > 0)
		{
			ft_dorot(a, b, 1);
			(*moves_b)--;
		}
	}
	else if (*moves_b < 0)
	{
		while (*moves_b < 0)
		{
			ft_dorevrot(a, b, 1);
			(*moves_b)++;
		}
	}
}

void	ft_execute_moves(t_stack **a, t_stack **b, int moves_a, int moves_b)
{
	ft_dual_rot(a, b, &moves_a, &moves_b);
	ft_dual_rev_rot(a, b, &moves_a, &moves_b);
	ft_do_a(a, b, &moves_a);
	ft_do_b(a, b, &moves_b);
	ft_dopush(a, b, 0);
}
