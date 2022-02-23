/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_from_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:36:47 by iharile           #+#    #+#             */
/*   Updated: 2022/02/23 16:10:30 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_list **stack_a, t_list **stack_b, int min, int max)
{
	t_init	init;
	int		i;

	initialize(&init, stack_b);
	while (init.head && init.last)
	{
		i = min;
		while (i <= max)
		{
			if (init.head->content == i)
			{
				init.j = the_top_b(stack_a, stack_b, init.index);
				initialize(&init, stack_b);
				init.j = 1;
			}
			else if (init.last->content == i)
			{
				init.j = the_bottom_b(stack_a, stack_b, init.index);
				initialize(&init, stack_b);
				init.j = 1;
			}
			i++;
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

	while (ft_lstsize(*stack_b) >= 2)
	{
		initialize(&init, stack_b);
		init.max = ft_lstsize(*stack_b) - 1;
		init.min = init.max - 1;
		//printf ("min == %d, max == %d\n", init.min, init.max);
		push_to_a(stack_a, stack_b, init.min, init.max);
	}
	if (ft_lstsize(*stack_b) == 1)
		pa(stack_a, stack_b);
	/*while (ft_lstsize(*stack_b) >= 3)
	{
		initialize(&init, stack_b);
		init.max = ft_lstsize(*stack_b) - 1;
		init.min = init.max - 2;
		printf ("min == %d, max == %d\n", init.min, init.max);
		push_to_a(stack_a, stack_b, init.min, init.max);
	}
	if (ft_lstsize(*stack_b) == 2 && !check_is_sorted(stack_b))
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
