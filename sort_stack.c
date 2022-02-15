/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:04:15 by iharile           #+#    #+#             */
/*   Updated: 2022/02/15 19:13:46 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

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
/*
void	down_up(t_list **g_stack_a, int index)
{
	int	size;
	int	mid;
	int	i;

	size = ft_lstsize(*g_stack_a);
	mid = size / 2;
	i = 0;
	while (i < size)
	{
		if (i <= mid)
		{
			
		}
		else if (i > mid)
		i++;
	}
	
}
*/

void	put_data(t_list **g_stack_a, t_sort *stack_checker, int min, int max)
{
	t_list	*stack_a;
	int		i;
	int		size;
	//int		*tab;
	int		j;

	i = 0;
	j = 0;
	//tab = malloc (sizeof(int) * (max - min));
	stack_a = *g_stack_a;
	size = ft_lstsize(stack_a);
	while (i < size)
	{
		if ((stack_a)->content >= min && (stack_a)->content <= max - 1)
		{
			printf ("%d ", stack_a->content);
			//tab[j] = stack_a->content;
			//j++;
			//down_up(g_stack_a, i);
		}
		i++;
		stack_a = stack_a->next;
	}
	
	printf ("\n");
}

void	sort_any_stack(t_list **g_stack_a, t_list **g_stack_b, int numbers,
		t_sort *stack_checker)
{
	int	sum;
	int	moves;
	int	last_move;
	int	i;
	int	min;

	i = 1;
	min = 0;
	moves = (numbers - 3) / 4;
	sum = moves;
	last_move = (numbers - 3) - (moves * 4);
	if (moves != 0)
	{
		while (i <= 4)
		{
			printf ("this is min = %d  max = %d\n", min , moves);
			put_data (g_stack_a, stack_checker, min, moves);
			min = moves;
			moves += sum;
			i++;
		}
	}
	if (last_move > 0)
	{
		moves = min + last_move;
		printf ("this is min = %d  max = %d\n", min , moves);
		put_data (&(*g_stack_a), stack_checker, min, moves);
	}
}
