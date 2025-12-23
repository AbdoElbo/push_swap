/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:13:43 by gekko             #+#    #+#             */
/*   Updated: 2025/12/23 15:11:14 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(p_list *stack_a)
{
	p_list	*temp;
	int		bit;

	ft_printf("\nStack_a:\n");
	temp = stack_a;
	while (temp)
	{
		bit = 10;
		ft_printf("%d, %d (index bits: ", temp->num, temp->index);
		while (bit >= 0)
		{
			ft_printf("%d", (temp->index >> bit) & 1);
			bit--;
		}
		ft_printf(")\n");
		temp = temp->next;
	}
}

int	main(int argc, char *argv[])
{
	p_list	*stack_a;
	p_list	*stack_b;
	p_list	*copy;
	size_t	size_a;

	stack_a = NULL;
	stack_b = NULL;
	copy = NULL;
	if (!error_handle(argc, argv))
		return (1);
	if (!initialize(argc, argv, &stack_a) || !initialize(argc, argv, &copy))
		return (free_stack(&stack_a), free_stack(&copy), 0);
	assign_index(&copy);
	index_main_stack_a(&stack_a, &copy);
	size_a = ft_lstsize(stack_a);
	if (size_a == 1)
		return (free_stack(&stack_a), free_stack(&stack_b), 0);
	if (size_a == 3)
		sort_three(&stack_a, 2);
	else if (size_a == 5)
		sort_five(&stack_a, &stack_b, 4);
	else
		exec_operations(&stack_a, &stack_b, size_a);
	return (free_stack(&stack_a), free_stack(&stack_b), 0);
}
