/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:13:56 by gekko             #+#    #+#             */
/*   Updated: 2025/12/23 15:08:21 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(p_list **stack_a)
{
	p_list	*lst;
	int		temp_num;
	int		temp_index;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	lst = *stack_a;
	temp_num = lst->num;
	temp_index = lst->index;
	lst->num = lst->next->num;
	lst->index = lst->next->index;
	lst->next->num = temp_num;
	lst->next->index = temp_index;
	ft_printf("sa\n");
}

void	push_a(p_list **stack_a, p_list **stack_b)
{
	p_list	*node;

	if (!stack_b || !*stack_b)
		return ;
	node = *stack_b;
	*stack_b = node->next;
	node->next = *stack_a;
	*stack_a = node;
	ft_printf("pa\n");
}

void	push_b(p_list **stack_b, p_list **stack_a)
{
	p_list	*node;

	if (!stack_a || !*stack_a)
		return ;
	node = *stack_a;
	*stack_a = node->next;
	node->next = *stack_b;
	*stack_b = node;
	ft_printf("pb\n");
}

void	rotate_a(p_list **stack_a)
{
	p_list	*temp;
	p_list	*node;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	node = *stack_a;
	*stack_a = (*stack_a)->next;
	while (node->next)
		node = node->next;
	node->next = temp;
	temp->next = NULL;
	ft_printf("ra\n");
}

void	reverse_rotate_a(p_list **stack_a)
{
	p_list	*lst;
	p_list	*node;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	lst = *stack_a;
	while (lst->next->next)
		lst = lst->next;
	node = malloc(sizeof(p_list));
	if (!node)
		return ;
	node->num = lst->next->num;
	node->index = lst->next->index;
	node->next = NULL;
	ft_lstadd_front(stack_a, node);
	free(lst->next);
	lst->next = NULL;
	ft_printf("rra\n");
}
