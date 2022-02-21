/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:59:57 by iharile           #+#    #+#             */
/*   Updated: 2022/02/21 18:07:35 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **g_stack_a, t_list **g_stack_b)
{
	t_list	*head;
	t_list	*new;

	if (!*g_stack_b || ft_lstsize(*g_stack_b) < 1)
		return ;
	head = (*g_stack_b);
	new = malloc (sizeof(t_list));
	if (!new)
		return ;
	new->content = (*g_stack_b)->content;
	new->next = (*g_stack_a);
	(*g_stack_a) = new;
	head = (*g_stack_b);
	(*g_stack_b) = (*g_stack_b)->next;
	free(head);
	write(1, "pa\n", 3);
}

void	ra(t_list **g_stack_a)
{
	t_list	*head;
	t_list	*new;
	t_list	*last;

	if (!*g_stack_a || ft_lstsize((*g_stack_a)) <= 1)
		return ;
	head = *g_stack_a;
	new = ft_lstnew((*g_stack_a)->content);
	ft_lstadd_back(&head, new);
	(*g_stack_a) = (*g_stack_a)->next;
	(*g_stack_a)->prev = NULL;
	free (head);
	write(1, "ra\n", 3);
}

void	sa(t_list **g_stack_a)
{
	t_list	*head;
	t_list	*second;
	int		temp;

	if (ft_lstsize(*g_stack_a) <= 1)
		return ;
	head = (*g_stack_a);
	second = (*g_stack_a)->next;
	temp = head->content;
	head->content = second->content;
	second->content = temp;
	write(1, "sa\n", 3);
}

void	rra(t_list **g_stack_a)
{
	t_list	*head;
	t_list	*last;
	t_list	*new;

	if (ft_lstsize(*g_stack_a) <= 1)
		return ;
	head = (*g_stack_a);
	last = ft_lstlast((*g_stack_a));
	new = ft_lstnew(last->content);
	ft_lstadd_front(&(*g_stack_a), new);
	while (head->next != NULL)
	{
		last = head;
		head = head->next;
	}
	//(*g_stack_a)->prev = NULL;
	last->next = NULL;
	free (head);
	write(1, "rra\n", 4);
}

void	rrr(t_list **g_stack_a, t_list **g_stack_b)
{
	rra(&(*g_stack_a));
	rrb(&(*g_stack_b));
}
