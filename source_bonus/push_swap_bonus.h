/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:12:56 by abettini          #+#    #+#             */
/*   Updated: 2024/01/23 12:25:17 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../Libft/libft.h"

# ifndef RROT
#  define RROT 1 
# endif
# ifndef ROT
#  define ROT 0
# endif

typedef struct s_stack
{
	int					index;
	int					n;
	struct s_stack		*prev;
	struct s_stack		*next;
}	t_stack;

t_stack	*ft_fill_stack(char **av);
int		ft_error_deal(int ac, char **av);
int		ft_stack_size(t_stack *stack);
int		ft_order_check(t_stack *stack);
int		ft_find_smallest_pos(t_stack *stack);
void	ft_print_stack(t_stack *stack);
void	ft_rev_print_stack(t_stack *stack);
void	ft_swap(t_stack **stack);
void	ft_push(t_stack **dest, t_stack **src);
void	ft_rotate(t_stack **stack);
void	ft_rev_rotate(t_stack **stack);
void	ft_dopush(t_stack **a, t_stack **b, int type);
void	ft_doswap(t_stack **a, t_stack **b, int type);
void	ft_dorot(t_stack **a, t_stack **b, int type);
void	ft_dorevrot(t_stack **a, t_stack **b, int type);
int		ft_findstart(t_stack *a);
void	ft_putindex(t_stack **stack);
void	ft_print_index(t_stack *stack);
void	ft_check_op_1(char *op, t_stack **a, t_stack **b);
void	ft_check_op_2(char *op, t_stack **a, t_stack **b);
int		ft_close(t_stack **a, t_stack **b);
void	ft_free_stack(t_stack *stack);

#endif
