/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:18:55 by gekko             #+#    #+#             */
/*   Updated: 2025/12/23 15:09:18 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"

typedef struct pa_list
{
	int				num;
	int				index;
	struct pa_list	*next;
}	p_list;

void			push_a(p_list **stack_a, p_list **stack_b);
void			push_b(p_list **stack_a, p_list **stack_b);
void			swap_a(p_list **stack_a);
void			rotate_a(p_list **stack_a);
void			reverse_rotate_a(p_list **stack_a);

void			ft_lstadd_front(p_list **lst, p_list *new);
void			ft_lstadd_back(p_list **lst, p_list *new);
p_list			*ft_lstnew(int number);
unsigned long	ft_lstsize(p_list *lst);

long			ft_atol(const char *str);
int				error_handle(int argc, char **argv);
int				non_digit(int argc, char **argv);
int				bigger_than_int(int argc, char **argv);
int				duplicate(p_list *stack);

int				add_node(char *str, p_list **stack);
int				initialize(int argc, char **argv, p_list **stack);
void			bubble_sort(p_list **stack_a);
void			free_stack(p_list **stack_a);
void			assign_index(p_list **stack_copy);
void			index_main_stack_a(p_list **stack_a, p_list **stack_copy);
void			exec_operations(p_list **stack_a, p_list **stack_b, int size);
int				stack_sorted(p_list *stack, int size);

int				is_space(char c);
size_t			word_count(char const *s);
char			**free_arr(char **arr, size_t n);
char			**ft_split_push(char const *s);

void			sort_three(p_list **stack_a, int num);
void			sort_five(p_list **stack_a, p_list **stack_b, int num);

#endif
