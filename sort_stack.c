/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:04:15 by iharile           #+#    #+#             */
/*   Updated: 2022/02/15 13:55:45 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	check_is_sorted(t_list **g_stack_a)
{
	t_list	*head;
	t_list	*consecutive;
	t_list	*last;
	int		i;

	i = 1;
	last = ft_lstlast((*g_stack_a));
	head = (*g_stack_a);
	consecutive = (*g_stack_a)->next;
	while (consecutive)
	{
		if (head->content < consecutive->content)
			i++;
		head = head->next;
		consecutive = consecutive->next;
	}
	if (i == ft_lstsize((*g_stack_a)))
		return (0);
	return (1);
}

void	three_sort(t_list **g_stack_a, int i)
{
	t_list	*last;

	if (check_is_sorted(&(*g_stack_a)))
	{
		last = ft_lstlast(*g_stack_a);
		if (i == 3)
			sa(&(*g_stack_a));
		else if ((*g_stack_a)->content == 2 && last->content == 0)
		{
			ra(&(*g_stack_a));
			sa(&(*g_stack_a));
		}
		else if ((*g_stack_a)->content == 2 && last->content == 1)
			ra(&(*g_stack_a));
		else if ((*g_stack_a)->content == 1 && last->content == 0)
			rra(&(*g_stack_a));
		else if ((*g_stack_a)->content == 1 && last->content == 2)
			sa(&(*g_stack_a));
		else if ((*g_stack_a)->content == 0 && last->content == 1)
		{
			sa(&(*g_stack_a));
			ra(&(*g_stack_a));
		}
	}
}

void	put_data(t_list **stack_a, t_sort *stack_checker, int min, int max)
{
	int	size;

	size = ft_lstsize(&(*stack_a));
	stack_checker->min = min;
	stack_checker->max = max - 1;
	stack_checker->mid = (ft_lstsize(&(*stack_a)) - 1) / 2;
}

void	sort_any_stack(t_list **g_stack_a, t_list **g_stack_b, int numbers,
		t_sort *stack_checker)
{
	int	check;
	int	moves;
	int	last_move;
	int	i;
	int	min;

	i = 1;
	min = 0;
	check = numbers - 3;
	moves = check / 4;
	last_move = (check) - (moves * 4);
	while (i <= 4)
	{
		put_data (&(*g_stack_a), stack_checker, min, moves);
		min = moves;
		moves += moves;
		i++;
	}
	if (last_move > 0)
	{
		moves = min + last_move;
		put_data (&(*g_stack_a), stack_checker, min, moves);
	}
}
