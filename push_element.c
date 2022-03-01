/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:42:55 by iharile           #+#    #+#             */
/*   Updated: 2022/02/27 15:04:05 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	the_top(t_list **stack_a, t_list **stack_b, t_init *index, int mid)
{
	int	i;

	i = 0;
	while (i < index->index)
	{
		ra(stack_a, 1);
		i++;
	}
	pb(stack_a, stack_b, 1);
	if ((*stack_b)->content < mid)
		rb (stack_b, 1);
	initialize(index, stack_a);
	return (1);
}

int	the_bottom(t_list **stack_a, t_list **stack_b, t_init *index, int mid)
{
	int	i;

	i = 0;
	while (i <= index->index)
	{
		rra(stack_a, 1);
		i++;
	}
	pb(stack_a, stack_b, 1);
	if ((*stack_b)->content < mid)
		rb (stack_b, 1);
	initialize(index, stack_a);
	return (1);
}

void	check_cases(t_list **stack_a)
{
	t_list	*last;

	last = ft_lstlast(*stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a, 1);
	if ((*stack_a)->content == last->content + 1
		&& (*stack_a)->content + 1 == (*stack_a)->next->content)
		rra(stack_a, 1);
	else if (((*stack_a)->content + 3 == (*stack_a)->next->content))
		ra (stack_a, 1);
	else if ((*stack_a)->content + 1 == (*stack_a)->next->content
		&& (*stack_a)->content + 3 == (*stack_a)->next->next->content)
		ra (stack_a, 1);
}

int	the_top_b(t_list **stack_a, t_list **stack_b, int index, t_init *init)
{
	int		i;

	i = 0;
	while (i < index)
	{
		rb(stack_b, 1);
		i++;
	}
	pa(stack_a, stack_b, 1);
	check_cases(stack_a);
	initialize(init, stack_b);
	return (1);
}

int	the_bottom_b(t_list **stack_a, t_list **stack_b, int index, t_init *init)
{
	int		i;
	i = 0;

	while (i <= index)
	{
		rrb(stack_b, 1);
		i++;
	}	
	pa(stack_a, stack_b, 1);
	check_cases(stack_a);
	initialize(init, stack_b);
	return (1);
}
