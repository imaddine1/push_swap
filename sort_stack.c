/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:04:15 by iharile           #+#    #+#             */
/*   Updated: 2022/02/16 15:38:53 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

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

void	first_to_push(t_list **g_stack_a, t_list **stack_b, int *tab, int size)
{
	int		i;
	int		index;
	t_list	*last;
	t_list	*head;
	int		j;

	index = 0;
	j = 0;
	printf("im here\n");
	last = ft_lstlast(*g_stack_a);
	head = *g_stack_a;
	while (head && last->prev)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] == head->content)
				j = the_top(g_stack_a, stack_b, index);
			else if (tab[i] == last->content)
				j = the_bottom(g_stack_a, stack_b, index);
			i++;
		}
		//printf ("im here %d\n", j);
		index++;
		head = head->next;
		last = last->prev;
		if (j == 1)
		{
			j = 0;
			head = *g_stack_a;
			last = ft_lstlast(*g_stack_a);
			index = 0;
			//printf ("this is begin %d this is end %d\n", head->content, last->content);
		}
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
			printf ("%d ", stack_a->content);
			tab[j] = stack_a->content;
			j++;
		}
		i++;
		stack_a = stack_a->next;
	}
	printf ("\n");
	first_to_push(g_stack_a, g_stack_b, tab, max - min);
}

void	sort_any_stack(t_list **g_stack_a, t_list **g_stack_b, int numbers)
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
			put_data (g_stack_a, g_stack_b, min, moves);
			min = moves;
			moves += sum;
			i++;
		}
	}
	if (last_move > 0)
	{
		moves = min + last_move;
		printf ("this is min = %d  max = %d\n", min , moves);
		put_data (g_stack_a, g_stack_a, min, moves);
	}
}
