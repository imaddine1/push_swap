/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:57:47 by iharile           #+#    #+#             */
/*   Updated: 2022/02/18 18:05:54 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	three_sort(t_list **g_stack_a, int i)
{
	t_list	*last;

	if (check_is_sorted(g_stack_a))
	{
		last = ft_lstlast(*g_stack_a);
		if (i == 3)
			sa(g_stack_a);
		else if ((*g_stack_a)->content == 2 && last->content == 0)
		{
			ra(g_stack_a);
			sa(g_stack_a);
		}
		else if ((*g_stack_a)->content == 2 && last->content == 1)
			ra(g_stack_a);
		else if ((*g_stack_a)->content == 1 && last->content == 0)
			rra(g_stack_a);
		else if ((*g_stack_a)->content == 1 && last->content == 2)
			sa(g_stack_a);
		else if ((*g_stack_a)->content == 0 && last->content == 1)
		{
			sa(g_stack_a);
			ra(g_stack_a);
		}
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

	index = location(g_stack_a, 3);
	if (index < 3)
		the_top(g_stack_a, g_stack_b, index);
	else
		the_bottom(g_stack_a, g_stack_b, 0);
	three_sort(g_stack_a, 4);
	pa(g_stack_a, g_stack_b);
	ra(g_stack_a);
}

void	five_sort(t_list **g_stack_a, t_list **g_stack_b, int i)
{
	t_list	*last;
	t_list	*head;
	int		index;

	if (!check_is_sorted(g_stack_a))
		return ;
	last = ft_lstlast(*g_stack_a);
	head = *g_stack_a;
	if (i == 5)
		four_sort(g_stack_a, g_stack_b);
	else if (i == 6)
	{
		index = location(g_stack_a, 4);
		if (index < 3)
			the_top(g_stack_a, g_stack_b, index);
		else
			the_bottom(g_stack_a, g_stack_b, 4 - index);
		four_sort(g_stack_a, g_stack_b);
		pa(g_stack_a, g_stack_b);
		ra(g_stack_a);
	}
}
