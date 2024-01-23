/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:44:41 by lamici            #+#    #+#             */
/*   Updated: 2024/01/23 12:36:17 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_check_stacks(t_stack **a, t_stack **b)
{
	int	x;

	x = 0;
	if (ft_stack_size(*b) != 0)
		x = 1;
	if (ft_order_check(*a) != 1)
		x = -1;
	return (x);
}

int	ft_close(t_stack **stack_a, t_stack **stack_b)
{
	ft_free_stack(*stack_a);
	ft_free_stack(*stack_b);
	write(2, "command does not exist\n", 23);
	exit(1);
}

void	ft_checker(t_stack **a, t_stack **b)
{
	char	*str;
	int		x;
	int		z;

	z = 1;
	str = NULL;
	while (str != 0 || z == 1)
	{
		z = 0;
		str = get_next_line(0);
		ft_check_op_1(str, a, b);
		if (str)
			free(str);
	}
	x = ft_check_stacks(a, b);
	if (x == -1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

void	not_str(char **args)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = ft_matlen(args);
	if (ft_error_deal(i, args))
		write(2, "Error\n", 6);
	else
	{
		a = ft_fill_stack(args);
		b = NULL;
		ft_checker(&a, &b);
		ft_putindex(&a);
		if (a)
			ft_free_stack(a);
		if (b)
			ft_free_stack(b);
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
