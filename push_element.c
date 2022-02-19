/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:42:55 by iharile           #+#    #+#             */
/*   Updated: 2022/02/19 16:14:13 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	the_top(t_list **g_stack_a, t_list **g_stack_b, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		ra(g_stack_a);
		i++;
	}
	pb(g_stack_a, g_stack_b);
	return (1);
}

int	the_bottom(t_list **g_stack_a, t_list **g_stack_b, int index)
{
	int	i;

	i = 0;
	while (i <= index)
	{
		rra(g_stack_a);
		i++;
	}
	pb(g_stack_a, g_stack_b);
	return (1);
}

int	the_top_b(t_list **g_stack_a, t_list **g_stack_b, int index)
{
	int		i;
	t_list	*head;

	i = 0;
	head = (*g_stack_a);
	while (i < index)
	{
		rb(g_stack_a);
		i++;
	}
	pa(g_stack_a, g_stack_b);
	return (1);
}

int	the_bottom_b(t_list **g_stack_a, t_list **g_stack_b, int index)
{
	int		i;
	t_list	*head;

	i = 0;
	head = (*g_stack_a);
	while (i <= index)
	{
		rrb(g_stack_a);
		i++;
	}	
	pa(g_stack_a, g_stack_b);
	return (1);
}
