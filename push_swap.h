/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:40:39 by iharile           #+#    #+#             */
/*   Updated: 2022/02/15 18:14:30 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// struct for sort determine min & max
typedef struct sort_helper
{
	int	min;
	int	mid;
	int	max;
}	t_sort;

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
void	sa(t_list **g_stack_b);
void	rra(t_list **g_stack_a);
void	rrb(t_list **g_stack_b);
void	rrr(t_list **g_stack_a, t_list **g_stack_b);
void	ss(t_list **g_stack_a, t_list **g_stack_b);
void	rr(t_list **g_stack_a, t_list **g_stack_b);
// sorting stack
int		check_is_sorted(t_list **g_stack_a);
void	three_sort(t_list **g_stack_a, int i);
void	sort_any_stack(t_list **g_stack_a, t_list **g_stack_b, int i,
			t_sort *stack_checker);
void	put_data(t_list **stack_a, t_sort *stack_checker, int min, int max);
void	down_up(t_list **g_stack_a, int index);
#endif
