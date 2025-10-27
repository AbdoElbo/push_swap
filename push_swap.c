/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:13:43 by gekko             #+#    #+#             */
/*   Updated: 2025/10/24 18:08:10 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack_a)
{
	t_list	*temp;
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

int	main()
{
	printf("%d---\n", ft_printf("%d"));
	printf("%d\n", printf("%d"));
	return (0);
}
