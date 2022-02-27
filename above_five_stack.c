/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   above_five_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:34:57 by iharile           #+#    #+#             */
/*   Updated: 2022/02/27 16:57:15 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize(t_init *init, t_list **stack)
{
	int	x;
	int	size;

	x = 3;
	size = ft_lstsize(*stack);
	init->j = 0;
	init->index = 0;
	init->min = 0;
	if (size > 250)
		x = 5;
	else if (size > 100)
		x = 4;
	else if (size < 50)
		x = 2;
	init->max = ((size - 3) / x) + 1;
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
			if (init.head->content == i)
				init.j = the_top(stack_a, stack_b, &init, mid);
		i = min - 1;
		while (++i < max)
			if (init.last->content == i)
				init.j = the_bottom(stack_a, stack_b, &init, mid);
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
