/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekko <gekko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:03:13 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/10/21 23:54:00 by gekko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result >= 3000000000)
			return (result * sign);
		i++;
	}
	return (result * sign);
}

int	bigger_than_int(int argc, char **argv)
{
	int		i;
	long	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > INT_MAX)
			return (write(2, "Error\n", 7), 1);
		else if (num < INT_MIN)
			return (write(2, "Error\n", 7), 1);
		i++;
	}
	return (0);
}

int	non_digit(int argc, char **argv)
{
	int		i;
	int		j;
	char	*trimmed;

	i = 1;
	while (i < argc)
	{
		trimmed = ft_strtrim(argv[i], " ");
		if (!trimmed)
			return (0);
		j = 0;
		while (trimmed[j])
		{
			if (trimmed[j] == '-' || trimmed[j] == '+')
				j++;
			if (!ft_isdigit(trimmed[j]) && !is_space(trimmed[j]))
				return (free(trimmed), write(2, "Error\n", 7), 1);
			j++;
		}
		free(trimmed);
		i++;
	}
	return (0);
}

int	duplicate(t_list *stack)
{
	t_list	*temp_1;
	t_list	*temp_2;

	temp_1 = stack;
	while (temp_1)
	{
		temp_2 = temp_1->next;
		while (temp_2)
		{
			if (temp_1->num == temp_2->num)
				return (0);
			temp_2 = temp_2->next;
		}
		temp_1 = temp_1->next;
	}
	return (1);
}

int	error_handle(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (!word_count(argv[1]))
			return (write(2, "Error\n", 7), 0);
	}
	if (non_digit(argc, argv))
		return (0);
	if (bigger_than_int(argc, argv))
		return (0);
	return (1);
}
