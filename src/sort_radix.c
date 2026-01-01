/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaciel <hemaciel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:27:32 by hemaciel          #+#    #+#             */
/*   Updated: 2026/01/01 18:27:36 by hemaciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *a)
{
	int	max;
	int	max_bits;

	max = a->index;
	max_bits = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_radix(t_stack **a, t_stack **b, int size)
{
	int	i;
	int	j;
	int	max_bits;

	if (!a || !*a || size <= 1)
		return ;
	max_bits = get_max_bits(*a);
	i = 0;
	while (i < max_bits && !is_sorted(*a))
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pa_pb(a, b, 2);
			else
				ra_rb_rr(a, b, 1);
			j++;
		}
		while (*b)
			pa_pb(a, b, 1);
		i++;
	}
}
