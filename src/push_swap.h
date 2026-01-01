/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaciel <hemaciel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:27:05 by hemaciel          #+#    #+#             */
/*   Updated: 2026/01/01 18:27:09 by hemaciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"

# define MAX 2147483647
# define MIN -2147483648

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack	*build_stack_a(int *nums, int size);
void	free_stack(t_stack **stack);

void	error_exit(void);
int		is_space(char c);
void	ft_free_array(char **arr);
int		is_number(const char *s);
long	ft_atol(const char *s);

int		is_int_str(const char *s, int *out);
int		is_duplicate(int *nums, int len, int value);
int		*validate_and_convert(char **nptr, int *size);

t_stack	*parsing_str(const char *s, int *size, int **nums);
t_stack	*parsing_args(char **av, int size, int **nums);

void	sa_sb_ss(t_stack **a, t_stack **b, int operation);
void	pa_pb(t_stack **a, t_stack **b, int operation);
void	ra_rb_rr(t_stack **a, t_stack **b, int operation);
void	rra_rrb_rrr(t_stack **a, t_stack **b, int operation);

int		is_sorted(t_stack *s);
void	sort_small_3(t_stack **a, t_stack **b, int size);
void	sort_small_5(t_stack **a, t_stack **b, int size);

void	sort_radix(t_stack **a, t_stack **b, int size);

void	sort(t_stack **a, int size);
int		*get_idx_nums(int *nums, int size);
void	set_indexes(t_stack*a, int *idx, int size);

#endif
