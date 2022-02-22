/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:40:39 by iharile           #+#    #+#             */
/*   Updated: 2022/02/22 17:22:11 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// create structure for intialize some variables
typedef struct initialize
{
	int		j;
	int		min;
	int		max;
	int		index;
	t_list	*head;
	t_list	*last;
}	t_init;
// check inputs
int		check_double(char **str);
int		max_int(char *str);
int		check_int(char **str);
// sorting fun
void	sort_tab(int *arr, int lb, int ub);
void	merge(int *arr, int lb, int mid, int ub);

// pb pa ra rb sa sb rra rrb rrr rr ss
void	pb(t_list **g_stack_a, t_list **g_stack_b);
void	pa(t_list **g_stack_a, t_list **g_stack_b);
void	ra(t_list **g_stack_a);
void	rb(t_list **g_stack_b);
void	sa(t_list **g_stack_a);
void	sb(t_list **g_stack_b);
void	rra(t_list **g_stack_a);
void	rrb(t_list **g_stack_b);
void	rrr(t_list **g_stack_a, t_list **g_stack_b);
void	ss(t_list **g_stack_a, t_list **g_stack_b);
void	rr(t_list **g_stack_a, t_list **g_stack_b);
// sorting stack
// sorting stacl that under five numbers
int		check_is_sorted(t_list **g_stack_a);
void	three_sort(t_list **g_stack_a, int i);
void	five_sort(t_list **g_stack_a, t_list **g_stack_b, int i);
// sorting above five numbers;
void	above_five(t_list **stack_a, t_list **stack_b);
//void	sort_any_stack(t_list **stack_a, t_list **stack_b, int numbers, int i);
//void	put_data(t_list **stack_a, t_list **g_stack_b, int min, int max);
//void	first_to_push(t_list **g_stack_a, t_list **stack_b, int *tab, int size);
int		the_top(t_list **g_stack_a, t_list **g_stack_b, int index, int mid);
int		the_bottom(t_list **g_stack_a, t_list **g_stack_b, int index, int mid);
int		the_top_b(t_list **stack_a, t_list **stack_b, int index, t_init i);
int		the_bottom_b(t_list **stack_a, t_list **stack_b, int index, t_init i);
void	initialize(t_init *initialize, t_list **stack);
void	check_stack_b(t_list **stack_a, t_list **stack_b);
#endif
