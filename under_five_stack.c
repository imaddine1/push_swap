/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:57:47 by iharile           #+#    #+#             */
/*   Updated: 2022/02/22 13:22:57 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	three_sort(t_list **stack_a, int i)
{
	t_list	*last;
	int		dt;	
	int		fc;

	fc = (*stack_a)->content;
	last = ft_lstlast(*stack_a);
	dt = (*stack_a)->next->content;
	if (i == 3)
		sa(stack_a);
	else if (fc > dt && dt > last->content && fc > dt)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (fc > dt && dt < last->content && fc > last->content)
		ra(stack_a);
	else if (fc < dt && dt > last->content && fc > last->content)
		rra(stack_a);
	else if (fc > dt && dt < last->content && fc < last->content)
		sa(stack_a);
	else if (fc < dt && dt > last->content && fc < last->content)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

int	location(t_list **g_stack_a, int num)
{
	t_list	*head;
	int		i;

	head = *g_stack_a;
	i = 0;
	while (head)
	{
		if (head->content == num)
		{
			return (i);
		}
		head = head->next;
		i++;
	}
	return (-1);
}

void	four_sort(t_list **g_stack_a, t_list **g_stack_b)
{
	int	index;

	index = location(g_stack_a, 0);
	if (index < 3)
		the_top(g_stack_a, g_stack_b, index, -1);
	else
		the_bottom(g_stack_a, g_stack_b, 0, -1);
	three_sort(g_stack_a, 4);
	pa(g_stack_a, g_stack_b);
}

void	five_sort(t_list **g_stack_a, t_list **g_stack_b, int i)
{
	t_list	*last;
	t_list	*head;
	int		index;

	last = ft_lstlast(*g_stack_a);
	head = *g_stack_a;
	if (i == 5)
		four_sort(g_stack_a, g_stack_b);
	else if (i == 6)
	{
		index = location(g_stack_a, 1);
		if (index < 3)
			the_top(g_stack_a, g_stack_b, index, -1);
		else
			the_bottom(g_stack_a, g_stack_b, 4 - index, -1);
		four_sort(g_stack_a, g_stack_b);
		pa(g_stack_a, g_stack_b);
		sa(g_stack_a);
	}
}
