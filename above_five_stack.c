/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   above_five_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:42:30 by iharile           #+#    #+#             */
/*   Updated: 2022/02/19 16:39:33 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	first_to_return(t_list **stack_a, t_list **stack_b, int *tab, int size)
{
	int		i;
	t_init	init;

	initialize(&init, stack_b);
	while (init.head && init.last)
	{
		i = -1;
		while (++i <= size)
		{
			if (tab[i] == init.head->content)
				init.j = the_top_b(stack_a, stack_b, init.index);
			else if (tab[i] == init.last->content)
				init.j = the_bottom_b(stack_a, stack_b, init.index);
		}
		init.index++;
		init.head = init.head->next;
		init.last = init.last->prev;
		if (init.j == 1)
			initialize(&init, stack_b);
	}
	free (tab);
}

void	take_data_b(t_list **stack_a, t_list **stack_b, int min, int max)
{
	int		*tab;
	int		size;
	int		i;
	t_list	*head;
	int		j;

	tab = malloc (sizeof(int) * ((max - min) + 1));
	size = ft_lstsize(*stack_b);
	i = 0;
	j = 0;
	head = *stack_b;
	while (i < size)
	{
		if (head->content >= min && head->content <= max)
		{
			tab[j] = head->content;
			j++;
		}
		i++;
		head = head->next;
	}
	first_to_return(stack_a, stack_b, tab, max - min);
}
/*
void	sort_of_two(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	first = (*stack_a);
	second = first->next;
	if (first->content > second->content)
		sa(stack_a);
	if (check_is_sorted(stack_a))
		rra(stack_a);
}
*/
void	check_stack_b(t_list **stack_a, t_list **stack_b)
{
	int		max;
	int		min;
	t_list	*last;

	max = ft_lstsize(*stack_b) - 1;
	min = max - 2;
	while (ft_lstsize(*stack_b) >= 3)
	{
		take_data_b(stack_a, stack_b, min, max);
		//sort_of_two(stack_a);
		max = min - 1;
		min = max - 2;
	}
}
