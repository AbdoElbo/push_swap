/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:55:15 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/12/23 15:08:39 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(p_list **stack_copy)
{
	p_list			*copy;
	unsigned long	i;

	bubble_sort(stack_copy);
	i = 0;
	copy = *stack_copy;
	while (i < ft_lstsize(*stack_copy))
	{
		copy->index = i;
		copy = copy->next;
		i++;
	}
}

void	free_stack(p_list **stack)
{
	p_list	*temp;

	if (!(*stack) || !stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	index_main_stack_a(p_list **stack_a, p_list **stack_copy)
{
	p_list	*main;
	p_list	*copy;

	main = *stack_a;
	while (main)
	{
		copy = *stack_copy;
		while (copy)
		{
			if (main->num == copy->num)
				main->index = copy->index;
			copy = copy->next;
		}
		main = main->next;
	}
	free_stack(stack_copy);
}

void	sort_three(p_list **stack_a, int num)
{
	int	first;
	int	second;

	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	if (first == num)
		rotate_a(stack_a);
	else if (second == num)
		reverse_rotate_a(stack_a);
	if (!stack_sorted(*stack_a, 3))
		swap_a(stack_a);
}

void	sort_five(p_list **stack_a, p_list **stack_b, int num)
{
	p_list	*temp;
	int		i;

	i = 0;
	while (i < 2)
	{
		temp = *stack_a;
		while (temp->index != 0 && temp->index != 1)
		{
			rotate_a(stack_a);
			temp = *stack_a;
		}
		push_b(stack_b, stack_a);
		i++;
	}
	sort_three(stack_a, num);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
	if (!stack_sorted(*stack_a, 5))
		swap_a(stack_a);
}
