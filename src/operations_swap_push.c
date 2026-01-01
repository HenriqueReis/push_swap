/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaciel <hemaciel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:25:16 by hemaciel          #+#    #+#             */
/*   Updated: 2026/01/01 18:25:21 by hemaciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **s)
{
	t_stack	*first;
	t_stack	*second;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	second = (*s)->next;
	first->next = second->next;
	second->next = first;
	*s = second;
}

void	sa_sb_ss(t_stack **a, t_stack **b, int operation)
{
	if (operation == 1)
	{
		swap(a);
		ft_putendl_fd("sa", 1);
	}
	else if (operation == 2)
	{
		swap(b);
		ft_putendl_fd("sb", 1);
	}
	else if (operation == 3)
	{
		swap(a);
		swap(b);
		ft_putendl_fd("ss", 1);
	}
}

static void	push(t_stack **from, t_stack **to)
{
	t_stack	*temp;

	if (!from || !*from)
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
}

void	pa_pb(t_stack **a, t_stack **b, int operation)
{
	if (operation == 1)
	{
		push(b, a);
		ft_putendl_fd("pa", 1);
	}
	else if (operation == 2)
	{
		push(a, b);
		ft_putendl_fd("pb", 1);
	}
}
