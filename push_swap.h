/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekko <gekko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:18:55 by gekko             #+#    #+#             */
/*   Updated: 2025/10/21 23:53:47 by gekko            ###   ########.fr       */
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

typedef struct s_list
{
	int				num;
	int				index;
	struct s_list	*next;
}	t_list;

void			push_a(t_list **stack_a, t_list **stack_b);
void			push_b(t_list **stack_a, t_list **stack_b);
void			swap_a(t_list **stack_a);
void			rotate_a(t_list **stack_a);
void			reverse_rotate_a(t_list **stack_a);

void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstnew(int number);
unsigned long	ft_lstsize(t_list *lst);

long			ft_atol(const char *str);
int				error_handle(int argc, char **argv);
int				non_digit(int argc, char **argv);
int				bigger_than_int(int argc, char **argv);
int				duplicate(t_list *stack);

int				add_node(char *str, t_list **stack);
int				initialize(int argc, char **argv, t_list **stack);
void			bubble_sort(t_list **stack_a);
void			free_stack(t_list **stack_a);
void			assign_index(t_list **stack_copy);
void			index_main_stack_a(t_list **stack_a, t_list **stack_copy);
void			exec_operations(t_list **stack_a, t_list **stack_b, int size);
int				stack_sorted(t_list *stack, int size);

int				is_space(char c);
size_t			word_count(char const *s);
char			**free_arr(char **arr, size_t n);
char			**ft_split_push(char const *s);

void			sort_three(t_list **stack_a, int num);
void			sort_five(t_list **stack_a, t_list **stack_b, int num);

#endif
