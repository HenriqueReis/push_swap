/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaciel <hemaciel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:18:00 by hemaciel          #+#    #+#             */
/*   Updated: 2026/01/03 09:35:11 by hemaciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*second_last_node(t_stack *s)
{
	if (!s || !s->next)
		return (NULL);
	while (s->next && s->next->next)
		s = s->next;
	return (s);
}

static void	reverse_rotate(t_stack **s)
{
	t_stack	*last_node;
	t_stack	*second_last;

	if (!s || !*s || !(*s)->next)
		return ;
	second_last = second_last_node(*s);
	last_node = second_last->next;
	second_last->next = NULL;
	last_node->next = *s;
	*s = last_node;
}

void	rra_rrb_rrr(t_stack **a, t_stack **b, int operation)
{
	if (operation == 1)
	{
		reverse_rotate(a);
		ft_putendl_fd("rra", 1);
	}
	else if (operation == 2)
	{
		reverse_rotate(b);
		ft_putendl_fd("rrb", 1);
	}
	else if (operation == 3)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		ft_putendl_fd("rrr", 1);
	}
}
