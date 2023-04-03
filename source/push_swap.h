/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:12:56 by abettini          #+#    #+#             */
/*   Updated: 2023/03/10 10:31:11 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
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

//errors / create and print lists
int		ft_error_deal(int ac, char **av);
t_stack	*ft_fill_stack(char **av);
void	ft_putindex(t_stack **stack);
void	ft_print_stack(t_stack *stack);
void	ft_rev_print_stack(t_stack *stack);
void	ft_print_index(t_stack *stack);
//operations
void	ft_swap(t_stack **stack);
void	ft_push(t_stack **dest, t_stack **src);
void	ft_rotate(t_stack **stack);
void	ft_rev_rotate(t_stack **stack);
//print operations
void	ft_dopush(t_stack **a, t_stack **b, int type);
void	ft_doswap(t_stack **a, t_stack **b, int type);
void	ft_dorot(t_stack **a, t_stack **b, int type);
void	ft_dorevrot(t_stack **a, t_stack **b, int type);
//lis
void	ft_deal_6plus(t_stack **s1, t_stack **s2);
int		ft_count(t_stack *first, t_stack *moveman);
int		ft_findnum(int x, t_stack *a);
//utils
int		ft_stack_size(t_stack *stack);
int		ft_order_check(t_stack *stack);
int		ft_find_smallest_pos(t_stack *stack);
int		ft_find_shortest_path(t_stack *pos, t_stack *dest);
void	ft_last_rot(t_stack **a, t_stack **b);
//utils 2
void	ft_intset(int **arr, int value, int size);
int		ft_n_at_pos(t_stack *stack, int pos);
int		ft_pos_with_n(t_stack *stack, int n);
int		ft_find_max_i(int *arr, int size);
int		ft_find_int(int *arr, int value, int size);
//arrays & moves
int		*ft_array_b(t_stack *a);
int		*ft_array_a(t_stack *a, t_stack *b);
int		ft_minmax(int a, int b);
int		ft_find_move_value(int a, int b);
void	ft_arraygaming(t_stack **a, t_stack **b);
t_stack	*ft_findsmallest(t_stack *a);
//push_swap
void	ft_deal_2(t_stack **stack, t_stack **stack2);
void	ft_deal_3(t_stack **stack, t_stack **stack2);
void	ft_deal_4_5(t_stack **a, t_stack **b);
void	ft_push_swap(t_stack **a, t_stack **b);
void	ft_execute_moves(t_stack **a, t_stack **b, int moves_a, int moves_b);
void	ft_free_stack(t_stack *celso);

#endif
