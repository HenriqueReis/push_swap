/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaciel <hemaciel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:26:37 by hemaciel          #+#    #+#             */
/*   Updated: 2026/01/05 08:41:31 by hemaciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	int		size;
	int		*nums;
	int		*idx;

	if (argc == 2)
		a = parsing_str(argv[1], &size, &nums);
	else if (argc > 2)
	{
		size = argc - 1;
		a = parsing_args(argv, size, &nums);
	}
	else
		return (0);
	if (!a)
		return (0);
	idx = get_idx_nums(nums, size);
	set_indexes(a, idx, size);
	free(idx);
	if (!is_sorted(a))
		sort(&a, size);
	free_stack(&a);
	free(nums);
	return (0);
}

void	sort(t_stack **a, int size)
{
	t_stack	*b;

	b = NULL;
	if (size <= 3)
		sort_small_3(a, &b, size);
	else if (size <= 5)
		sort_small_5(a, &b, size);
	else
		sort_radix(a, &b, size);
}

int	*get_idx_nums(int *nums, int size)
{
	int	i;
	int	j;
	int	rank;
	int	*idx;

	idx = malloc(sizeof(int) * size);
	if (!idx)
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		rank = 0;
		while (j < size)
		{
			if (nums[j] < nums[i])
				rank++;
			j++;
		}
		idx[i] = rank;
		i++;
	}
	return (idx);
}

void	set_indexes(t_stack*a, int *idx, int size)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = a;
	while (temp && i < size)
	{
		temp->index = idx[i];
		temp = temp->next;
		i++;
	}
}
