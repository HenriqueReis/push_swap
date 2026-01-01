/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaciel <hemaciel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:26:06 by hemaciel          #+#    #+#             */
/*   Updated: 2026/01/01 18:26:09 by hemaciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int_str(const char *s, int *out)
{
	long	num;

	num = ft_atol(s);
	if (num > MAX || num < MIN)
		return (0);
	*out = (int)num;
	return (1);
}

static int	*alloc_int_array(char **nptr, int *size)
{
	int	i;
	int	*nums;

	i = 0;
	while (nptr[i])
		i++;
	if (i == 0)
		error_exit();
	*size = i;
	nums = malloc(sizeof(int) * i);
	if (!nums)
		error_exit();
	return (nums);
}

int	is_duplicate(int *nums, int len, int value)
{
	int	j;

	j = 0;
	while (j < len)
	{
		if (nums[j] == value)
			return (1);
		j++;
	}
	return (0);
}

int	*validate_and_convert(char **nptr, int *size)
{
	int	*nums;
	int	i;
	int	out;

	nums = alloc_int_array(nptr, size);
	i = 0;
	while (nptr[i])
	{
		if (!is_number(nptr[i]) || !is_int_str(nptr[i], &out)
			|| is_duplicate(nums, i, out))
		{
			free(nums);
			error_exit();
		}
		nums[i] = out;
		i++;
	}
	return (nums);
}
