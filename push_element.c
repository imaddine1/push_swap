/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:42:55 by iharile           #+#    #+#             */
/*   Updated: 2022/02/22 17:25:57 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	the_top(t_list **g_stack_a, t_list **g_stack_b, int index, int mid)
{
	int	i;

	i = 0;
	while (i < index)
	{
		ra(g_stack_a);
		i++;
	}
	pb(g_stack_a, g_stack_b);
	if ((*g_stack_b)->content < mid)
		rb (g_stack_b);
	return (1);
}

int	the_bottom(t_list **g_stack_a, t_list **g_stack_b, int index, int mid)
{
	int	i;

	i = 0;
	while (i <= index)
	{
		rra(g_stack_a);
		i++;
	}
	pb(g_stack_a, g_stack_b);
	if ((*g_stack_b)->content < mid)
		rb (g_stack_b);
	return (1);
}
/*
void	check_cases(t_list *head, t_list **stack_a)
{
	static int	i;
	static int	j;

	i = i + 1;
	if (head->content == (*stack_a)->content + 3)
	{	
		ra(stack_a);
		j = 1;
		printf ("----i do it\n");
	}
	else if (head->content < (*stack_a)->content)
	{
		printf ("------swap\n");
		sa(stack_a);
	}
	if (i == 3 && j == 1)
	{
		printf ("--------i need to go %d && %d\n", i, j);
		rra(stack_a);
		i = 0;
		j = 0;
	}
	else if (i == 3)
		i = 0;
}
*/

void	check_cases(t_list *head, t_list **stack_a)
{
	static int	i;
	static int	j;
	static int	node;

	i++;
	if (node == 0)
		node = (*stack_a)->content;
	if (node == (*stack_a)->content + 3)
	{
		j = 1;
		ra (stack_a);
	}
	else if (head->content < (*stack_a)->content)
		sa(stack_a);
	if (i == 3 && j == 1)
		rra(stack_a);
	if (i == 3)
	{
		i = 0;
		node = (*stack_a)->content;
	}
}

int	the_top_b(t_list **stack_a, t_list **stack_b, int index, t_init init)
{
	int		i;
	t_list	*head;

	i = 0;
	head = (*stack_a);
	while (i < index)
	{
		rb(stack_b);
		i++;
	}
	pa(stack_a, stack_b);
	initialize(&init, stack_b);
	check_cases(head, stack_a);
	return (1);
}

int	the_bottom_b(t_list **stack_a, t_list **stack_b, int index, t_init init)
{
	int		i;
	t_list	*head;

	i = 0;
	head = (*stack_a);
	while (i <= index)
	{
		rrb(stack_b);
		i++;
	}	
	pa(stack_a, stack_b);
	initialize(&init, stack_b);
	check_cases(head, stack_a);
	return (1);
}
