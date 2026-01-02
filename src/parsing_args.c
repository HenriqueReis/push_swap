/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaciel <hemaciel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:25:43 by hemaciel          #+#    #+#             */
/*   Updated: 2026/01/02 20:00:46 by gelt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**split_args(const char *s)
{
	char	**nptr;

	if (!s)
		error_exit();
	nptr = ft_split(s, ' ');
	if (!nptr || !nptr[0])
	{
		ft_free_array(nptr);
		error_exit();
	}
	return (nptr);
}

t_stack	*parsing_str(const char *s, int *size, int **nums)
{
	char	**nptr;
	t_stack	*a;

	nptr = split_args(s);
	*nums = validate_and_convert(nptr, size);
	ft_free_array(nptr);
	a = build_stack_a(*nums, *size);
	return (a);
}

t_stack	*parsing_args(char **av, int size, int **nums)
{
	int		i;
	int		out;
	t_stack	*a;

	*nums = malloc(sizeof(int) * size);
	if (!(*nums))
		error_exit();
	i = 0;
	while (i < size)
	{
		if (!is_number(av[i + 1]) || !is_int_str(av[i + 1], &out)
			|| is_duplicate(*nums, i, out))
		{
			free(*nums);
			error_exit();
		}
		(*nums)[i] = out;
		i++;
	}
	a = build_stack_a(*nums, size);
	return (a);
}
