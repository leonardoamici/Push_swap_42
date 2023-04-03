/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:10:47 by lamici            #+#    #+#             */
/*   Updated: 2023/03/30 15:26:10 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_real_lis_pos(int *lis_pos, int i, int size)
{
	int	temp;
	int	*real_lis_pos;
	int	j;

	real_lis_pos = malloc(sizeof(int) * size);
	temp = i;
	j = 0;
	while (j < size)
	{
		real_lis_pos[j] = temp;
		temp = lis_pos[temp];
		j++;
	}
	free(lis_pos);
	return (real_lis_pos);
}

void	ft_lis(t_stack *stack, int **lis_len, int **lis_pos)
{
	int		i;
	int		j;
	int		size;

	size = ft_stack_size(stack);
	ft_intset(lis_pos, -1, size);
	(*lis_len)[0] = 1;
	i = 1;
	while (i < size)
	{
		(*lis_len)[i] = 1;
		j = 0;
		while (j < i)
		{
			if (ft_n_at_pos(stack, i + 1) > ft_n_at_pos(stack, j + 1) \
				&& (*lis_len)[i] <= (*lis_len)[j] + 1)
			{
				(*lis_len)[i] = (*lis_len)[j] + 1;
				(*lis_pos)[i] = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_push_not_lis(t_stack **a, t_stack **b, int *lis, int lis_size)
{
	int			size_1;
	t_stack		*temp;

	size_1 = ft_stack_size(*a);
	while (size_1 - lis_size > 0)
	{
		temp = *a;
		while (ft_find_int(lis, temp->n, lis_size))
			temp = temp->next;
		if (ft_pos_with_n(*a, temp->n) > size_1 / 2)
		{
			while (ft_pos_with_n(*a, temp->n) != 1)
				ft_dorevrot(a, b, 0);
		}
		else
		{
			while (ft_pos_with_n(*a, temp->n) != 1)
				ft_dorot(a, b, 0);
		}
		ft_dopush(a, b, 1);
		size_1--;
	}
}

int	*ft_lis_n(t_stack *s, int *lis_pos, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		lis_pos[i] = ft_n_at_pos(s, lis_pos[i] + 1);
		i++;
	}
	return (lis_pos);
}

void	ft_deal_6plus(t_stack **s1, t_stack **s2)
{
	int	*lis_len;
	int	*lis_pos;
	int	max_i;
	int	size;

	size = ft_stack_size(*s1);
	lis_len = malloc(sizeof(int) * size);
	lis_pos = malloc(sizeof(int) * size);
	ft_lis(*s1, &lis_len, &lis_pos);
	max_i = ft_find_max_i(lis_len, size);
	lis_pos = ft_real_lis_pos(lis_pos, max_i, lis_len[max_i]);
	lis_pos = ft_lis_n(*s1, lis_pos, lis_len[max_i]);
	ft_push_not_lis(s1, s2, lis_pos, lis_len[max_i]);
	free(lis_len);
	free(lis_pos);
}
