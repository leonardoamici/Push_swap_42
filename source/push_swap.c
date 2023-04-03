/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:40:27 by abettini          #+#    #+#             */
/*   Updated: 2023/03/10 10:36:31 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	not_str(char **args)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = ft_matlen(args);
	if (ft_error_deal(i, args))
		write(2, "Error\n", 6);
	else if (i > 1)
	{
		a = ft_fill_stack(args);
		b = NULL;
		ft_putindex(&a);
		if (i <= 5 && !ft_order_check(a))
			ft_deal_4_5(&a, &b);
		else if (!ft_order_check(a))
		{
			ft_deal_6plus(&a, &b);
			ft_push_swap(&a, &b);
		}
		ft_free_stack(a);
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		not_str(av);
		ft_kill_matrix(av);
	}
	else
		not_str(av + 1);
	return (0);
}
