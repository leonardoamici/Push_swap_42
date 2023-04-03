/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:25:11 by abettini          #+#    #+#             */
/*   Updated: 2023/03/10 10:32:31 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack *celso)
{
	int		size;
	int		i;
	t_stack	*temp;

	size = ft_stack_size(celso);
	if (size > 0)
	{
		temp = celso->next;
		i = 0;
		while (i < size)
		{
			free(celso);
			celso = temp;
			i++;
			if (i < size)
				temp = temp->next;
		}
	}
}

t_stack	*ft_new_node(t_stack *prev, int n)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->n = n;
	node->prev = prev;
	node->next = NULL;
	return (node);
}

t_stack	*ft_fill_stack(char **av)
{
	t_stack	*stack;
	t_stack	*temp;
	int		j;
	int		ac;

	stack = ft_new_node(NULL, ft_atoi(av[0]));
	temp = stack;
	j = 1;
	ac = ft_matlen(av);
	while (j < ac)
	{
		temp->next = ft_new_node(temp, ft_atoi(av[j]));
		temp = temp->next;
		j++;
	}
	temp->next = stack;
	stack->prev = temp;
	return (stack);
}
