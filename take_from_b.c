/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_from_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:36:47 by iharile           #+#    #+#             */
/*   Updated: 2022/02/22 17:30:53 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_list **stack_a, t_list **stack_b, int min, int max)
{
	t_init	init;

	initialize(&init, stack_b);
	printf ("this is the first three %d, %d\n", min, max);
	while (init.head && init.last)
	{
		init.min = min;
		while (init.min <= max)
		{
			if (init.head->content == init.min)
				init.j = the_top_b(stack_a, stack_b, init.index, init);
			else if (init.last->content == init.min)
				init.j = the_bottom_b(stack_a, stack_b, init.index, init);
			init.min++;
		}
		if (init.j == 1)
			initialize(&init, stack_b);
		else
		{
			init.index++;
			init.head = init.head->next;
			init.last = init.last->prev;
		}
	}
}


void	check_stack_b(t_list **stack_a, t_list **stack_b)
{
	t_init	init;

	initialize(&init, stack_b);
	init.max = ft_lstsize(*stack_b) - 1;
	init.min = init.max - 2;
	while (ft_lstsize(*stack_b) >= 3)
	{
		push_to_a(stack_a, stack_b, init.min, init.max);
		init.max = init.min - 1;
		init.min = init.max - 2;
	}
/*	if (ft_lstsize(*stack_b) == 2 && !check_is_sorted(stack_b))
	{
		sb(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else if (ft_lstsize(*stack_b) == 2 && check_is_sorted(stack_b))
	{
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else
		pa(stack_a, stack_b);*/
}
