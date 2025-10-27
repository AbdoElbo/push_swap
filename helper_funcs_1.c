/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekko <gekko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:29:50 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/10/21 23:55:08 by gekko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_list **stack_a)
{
	int		change;
	int		temp;
	t_list	*lst;

	if (!(*stack_a))
		return ;
	change = 1;
	while (change)
	{
		lst = *stack_a;
		change = 0;
		while (lst && lst->next)
		{
			if (lst->num > lst->next->num)
			{
				temp = lst->num;
				lst->num = lst->next->num;
				lst->next->num = temp;
				change = 1;
			}
			lst = lst->next;
		}
	}
}

int	add_node(char *str, t_list **stack)
{
	int		number;
	t_list	*new_node;

	number = ft_atoi(str);
	new_node = ft_lstnew(number);
	if (!new_node)
		return (0);
	ft_lstadd_back(stack, new_node);
	return (1);
}

int	initialize(int argc, char **argv, t_list **stack)
{
	int		i;
	int		n;
	char	**array;

	i = 1;
	while (i < argc)
	{
		array = ft_split_push(argv[i]);
		if (!array)
			return (0);
		n = 0;
		while (array[n])
		{
			if (!add_node(array[n], stack))
				return (free_arr(array, word_count(argv[i])), 0);
			n++;
		}
		free_arr(array, word_count(argv[i]));
		i++;
	}
	if (!duplicate(*stack))
		return (write(2, "Error DUP\n", 10), 0);
	return (1);
}

int	stack_sorted(t_list *stack, int size)
{
	t_list	*temp;
	int		size_2;

	temp = stack;
	while (temp && temp->next)
	{
		if (temp->index > temp->next->index)
			return (0);
		temp = temp->next;
	}
	size_2 = ft_lstsize(stack);
	if (size != size_2)
		return (0);
	return (1);
}

void	exec_operations(t_list **stack_a, t_list **stack_b, int size)
{
	int		bit;
	int		i;

	bit = 0;
	while (bit < 32 && !stack_sorted(*stack_a, size))
	{
		i = 0;
		while (i < size)
		{
			if ((((*stack_a)->index >> bit) & 1) == 1)
				rotate_a(stack_a);
			else
				push_b(stack_b, stack_a);
			i++;
		}
		while (*stack_b)
			push_a(stack_a, stack_b);
		bit++;
	}
}
