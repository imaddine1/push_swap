/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:04:15 by iharile           #+#    #+#             */
/*   Updated: 2022/02/20 15:40:54 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	first_to_push(t_list **stack_a, t_list **stack_b, int *tab, int size)
{
	int		i;
	t_init	init;

	initialize(&init, stack_a);
	while (init.head && init.last)
	{
		i = -1;
		while (++i < size)
		{
			if (tab[i] == init.head->content)
			{
				init.j = the_top(stack_a, stack_b, init.index);
				initialize(&init, stack_a);
				init.j = 1;
			}
			else if (tab[i] == init.last->content)
			{
				init.j = the_bottom(stack_a, stack_b, init.index);
				initialize(&init, stack_a);
				init.j = 1;
			}
		}
		init.index++;
		if (ft_lstsize(*stack_a) > 0)
		{
			init.head = init.head->next;
			init.last = init.last->prev;
		}
		if (init.j == 1)
			initialize(&init, stack_a);
	}
	free (tab);
}

void	put_data(t_list **g_stack_a, t_list **g_stack_b, int min, int max)
{
	t_list	*stack_a;
	int		i;
	int		size;
	int		*tab;
	int		j;

	i = 0;
	j = 0;
	tab = malloc (sizeof(int) * (max - min));
	stack_a = *g_stack_a;
	size = ft_lstsize(stack_a);
	while (i < size)
	{
		if ((stack_a)->content >= min && (stack_a)->content <= max - 1)
		{
			tab[j] = stack_a->content;
			j++;
		}
		i++;
		stack_a = stack_a->next;
	}
	first_to_push(g_stack_a, g_stack_b, tab, max - min);
}

void	sort_any_stack(t_list **stack_a, t_list **stack_b, int numbers, int i)
{
	int	sum;
	int	moves;
	int	last_move;
	int	min;

	if (!check_is_sorted(stack_a))
		return ;
	min = 0;
	moves = (numbers - 1) / 4;
	sum = moves;
	last_move = (numbers - 1) - (moves * 4);
	if (moves != 0)
	{
		while (++i <= 4)
		{
			//printf ("the min == %d && max == %d\n", min, moves);
			put_data (stack_a, stack_b, min, moves);
			min = moves;
			moves += sum;
		}
	}
	moves = min + last_move;
	if (last_move > 0)
	{
		//printf ("the min == %d && max == %d\n", min, moves);
		put_data (stack_a, stack_b, min, moves);
	}
	check_stack_b(stack_a, stack_b);
}
