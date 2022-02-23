/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   above_five_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:34:57 by iharile           #+#    #+#             */
/*   Updated: 2022/02/23 18:33:22 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize(t_init *init, t_list **stack)
{

	init->j = 0;
	init->index = 0;
	init->min = 0;
	init->max = ((ft_lstsize(*stack) - 3) / 4) + 1;
	init->head = (*stack);
	init->last = ft_lstlast(*stack);
}

void	push_to_b(t_list **stack_a, t_list **stack_b, int min, int max)
{
	t_init	init;
	int		i;
	int		mid;

	initialize(&init, stack_a);
	mid = (min + (max - 1)) / 2;
	while (init.head && init.last)
	{
		i = min;
		while (i < max)
		{
			if (init.head->content == i)
			{
				init.j = the_top(stack_a, stack_b, init.index, mid);
				initialize(&init, stack_a);
				init.j = 1;
			}
			else if (init.last->content == i)
			{
				init.j = the_bottom(stack_a, stack_b, init.index, mid);
				initialize(&init, stack_a);
				init.j = 1;
			}
			i++;
		}
		if (init.j == 1)
			initialize(&init, stack_a);
		else
		{
			init.index++;
			init.head = init.head->next;
			init.last = init.last->prev;
		}

	}
}

void	above_five(t_list **stack_a, t_list **stack_b)
{
	t_init	init;
	int		min;
	int		max;

	max = 0;
	/*initialize(&init, stack_a);
	printf ("size == %d\n", init.max);*/
	while (ft_lstsize(*stack_a) > 3)
	{
		initialize(&init, stack_a);
		min = max;
		max += init.max;
		push_to_b(stack_a, stack_b, min, max);
	}
	three_sort(stack_a, 4);
	check_stack_b(stack_a, stack_b);
}
