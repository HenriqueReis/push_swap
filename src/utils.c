/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaciel <hemaciel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:28:59 by hemaciel          #+#    #+#             */
/*   Updated: 2026/01/01 18:29:02 by hemaciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	ft_putendl_fd("Error", 1);
	exit(1);
}

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

void	ft_free_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	is_number(const char *s)
{
	int	i;
	int	digit;

	i = 0;
	digit = 0;
	while (is_space(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (ft_isdigit(s[i]))
	{
		digit = 1;
		i++;
	}
	if (s[i] == '\0' && digit)
		return (1);
	return (0);
}

long	ft_atol(const char *s)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (is_space(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result * sign);
}
