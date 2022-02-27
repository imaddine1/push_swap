/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:40:39 by iharile           #+#    #+#             */
/*   Updated: 2022/02/27 15:58:21 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <unistd.h>
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
// put it on array
int		*array_of_int(char **av, int ac);
void	content_to_index(t_list *new, int *arr);
// pb pa ra rb sa sb rra rrb rrr rr ss
void	pb(t_list **g_stack_a, t_list **g_stack_b, int i);
void	pa(t_list **g_stack_a, t_list **g_stack_b, int i);
void	ra(t_list **g_stack_a, int i);
void	rb(t_list **g_stack_b, int i);
void	sa(t_list **g_stack_a, int i);
void	sb(t_list **g_stack_b, int i);
void	rra(t_list **g_stack_a, int i);
void	rrb(t_list **g_stack_b, int i);
void	rrr(t_list **g_stack_a, t_list **g_stack_b, int i);
void	ss(t_list **g_stack_a, t_list **g_stack_b, int i);
void	rr(t_list **g_stack_a, t_list **g_stack_b, int i);
// sorting stack
// sorting stack that under five numbers
int		check_is_sorted(t_list **g_stack_a);
void	three_sort(t_list **g_stack_a, int i);
// four numbers sort
void	four_sort(t_list **stack_a, t_list **stack_b);
// five numbers sort
void	five_sort(t_list **g_stack_a, t_list **g_stack_b, int j);
// sorting above five numbers;
void	above_five(t_list **stack_a, t_list **stack_b);
//void	sort_any_stack(t_list **stack_a, t_list **stack_b, int numbers, int i);
//void	put_data(t_list **stack_a, t_list **g_stack_b, int min, int max);
//void	first_to_push(t_list **g_stack_a, t_list **stack_b, int *tab, int size);
int		the_top(t_list **stack_a, t_list **stack_b, t_init *index, int mid);
int		the_bottom(t_list **stack_a, t_list **stack_b, t_init *index, int mid);
/// return to stack a
int		the_top_b(t_list **stack_a, t_list **stack_b, int index, t_init *init);
int		the_bottom_b(t_list **stack_a, t_list **st_b, int index, t_init *init);
void	initialize(t_init *initialize, t_list **stack);
void	check_stack_b(t_list **stack_a, t_list **stack_b);
// checker
void	valid_instruction(char *str, t_list **stack_a, t_list **stack_b);
// fucking norm
void	norm_25(t_list **stack);
#endif
