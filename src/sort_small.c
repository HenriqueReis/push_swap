/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaciel <hemaciel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:27:50 by hemaciel          #+#    #+#             */
/*   Updated: 2026/01/01 18:27:53 by hemaciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	if (!s || !s->next)
		return (1);
	while (s->next)
	{
		if (s->num > s->next->num)
			return (0);
		s = s->next;
	}
	return (1);
}

static void	get_min_max(t_stack *a, int *min, int *max)
{
	t_stack	*temp;

	if (!a || !min || !max)
		return ;
	temp = a;
	*min = a->num;
	*max = a->num;
	while (temp)
	{
		if (temp->num < *min)
			*min = temp->num;
		if (temp->num > *max)
			*max = temp->num;
		temp = temp->next;
	}
}

static int	get_index_of_value(t_stack *a, int value)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->num == value)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}

void	sort_small_3(t_stack **a, t_stack **b, int size)
{
	int	min;
	int	max;

	if (size == 2)
		sa_sb_ss(a, b, 1);
	else if (size == 3)
	{
		get_min_max(*a, &min, &max);
		if ((*a)->num < (*a)->next->num)
		{
			rra_rrb_rrr(a, b, 1);
			if (!is_sorted(*a))
				sa_sb_ss(a, b, 1);
		}
		else
		{
			if ((*a)->num == max && (*a)->next->num == min)
				ra_rb_rr(a, b, 1);
			else
				sa_sb_ss(a, b, 1);
			if (!is_sorted(*a))
				rra_rrb_rrr(a, b, 1);
		}
	}
}

void	sort_small_5(t_stack **a, t_stack **b, int size)
{
	int	min;
	int	max_dummy;
	int	idx_min;

	while (size > 3)
	{
		get_min_max(*a, &min, &max_dummy);
		idx_min = get_index_of_value(*a, min);
		if (idx_min <= size / 2)
		{
			while ((*a)->num != min)
				ra_rb_rr(a, b, 1);
		}
		else
		{
			while ((*a)->num != min)
				rra_rrb_rrr(a, b, 1);
		}
		pa_pb(a, b, 2);
		size--;
	}
	sort_small_3(a, b, size);
	while (*b)
		pa_pb(a, b, 1);
}
