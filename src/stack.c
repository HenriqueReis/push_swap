/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaciel <hemaciel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:28:16 by hemaciel          #+#    #+#             */
/*   Updated: 2026/01/01 18:28:22 by hemaciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*stack_new(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->num = value;
	node->next = NULL;
	return (node);
}

static void	stack_add_front(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	new->next = *stack;
	*stack = new;
}

t_stack	*build_stack_a(int *nums, int size)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = size - 1;
	while (i >= 0)
	{
		stack_add_front(&a, stack_new(nums[i]));
		i--;
	}
	return (a);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	*stack = NULL;
}
