/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:04:15 by iharile           #+#    #+#             */
/*   Updated: 2022/02/11 11:43:51 by iharile          ###   ########.fr       */
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
		return (1);
	return (0);
}

void	three_sort(t_list **g_stack_a)
{
	t_list	*last;

	if (check_is_sorted(&(*g_stack_a)))
	{
		last = ft_lstlast(*g_stack_a);
		if ((*g_stack_a)->content == 2 && last->content == 0)
		{
			ra(&(*g_stack_a));
			sa(&(*g_stack_a));
		}
		if ((*g_stack_a)->content == 2 && last->content == 1)
			ra(&(*g_stack_a));
		if ((*g_stack_a)->content == 1 && last->content == 0)
			rra(&(*g_stack_a));
		if ((*g_stack_a)->content == 1 && last->content == 2)
			sa(&(*g_stack_a));
		if ((*g_stack_a)->content == 0 && last->content == 1)
		{
			sa(&(*g_stack_a));
			ra(&(*g_stack_a));
		}
	}
}
