/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   above_five_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:34:57 by iharile           #+#    #+#             */
/*   Updated: 2022/02/21 20:46:28 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize(t_init *init, t_list **stack_a)
{

	init->index = 0;
	init->min = 0;
	init->max = (ft_lstsize(*stack_a) - 3) / 4 + 1;
	init->mid = (init->min + init->max) / 2;
}

void	push_to_b(t_list **stack_a, t_list **stack_b, int min, int max)
{
	t_list	*last;
	t_list	*head;
	int		index;

	head = (*stack_a);
	last = ft_lstlast(*stack_a);
	index = 0;
	while (head && last)
	{
		if (head->content >= min && head->content < max)
			the_top(stack_a, stack_b, index);
		else if (last->content >= min && last->content < max)
			the_bottom(stack_a, stack_b, index);
		index++;
		head = head->next;
		last = last->prev;
	}
}

void	above_five(t_list **stack_a, t_list **stack_b)
{
	t_init	init;
	int		min;
	int		max;

	initialize(&init, stack_a);
	min = init.min;
	max = init.max;
	while (ft_lstsize(*stack_a) > 3)
	{
		min = max;
		initialize(&init, stack_a);
		max += init.max;
	}
}
