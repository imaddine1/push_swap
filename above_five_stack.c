/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   above_five_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:34:57 by iharile           #+#    #+#             */
/*   Updated: 2022/02/24 11:12:34 by iharile          ###   ########.fr       */
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

void	norm_b_1(t_init *init)
{
	init->index++;
	init->head = init->head->next;
	init->last = init->last->prev;
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
		i = min - 1;
		while (++i < max)
		{
			if (init.head->content == i)
				init.j = the_top(stack_a, stack_b, &init, mid);
			else if (init.last->content == i)
				init.j = the_bottom(stack_a, stack_b, &init, mid);
		}
		if (init.j == 1)
			initialize(&init, stack_a);
		else
			norm_b_1(&init);
	}
}

void	above_five(t_list **stack_a, t_list **stack_b)
{
	t_init	init;
	int		min;
	int		max;

	max = 0;
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
