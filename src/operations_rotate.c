/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaciel <hemaciel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:24:43 by hemaciel          #+#    #+#             */
/*   Updated: 2026/01/01 18:24:52 by hemaciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*stack_last(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s->next)
	{
		s = s->next;
	}
	return (s);
}

static void	rotate(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	last = stack_last(*s);
	*s = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra_rb_rr(t_stack **a, t_stack **b, int operation)
{
	if (operation == 1)
	{
		rotate(a);
		ft_putendl_fd("ra", 1);
	}
	else if (operation == 2)
	{
		rotate(b);
		ft_putendl_fd("rb", 1);
	}
	else if (operation == 3)
	{
		rotate(a);
		rotate(b);
		ft_putendl_fd("rr", 1);
	}
}
