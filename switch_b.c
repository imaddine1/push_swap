/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:25:02 by iharile           #+#    #+#             */
/*   Updated: 2022/02/24 13:59:59 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **g_stack_a, t_list **g_stack_b)
{
	t_list	*head;
	t_list	*new;

	if (!*g_stack_a || ft_lstsize(*g_stack_a) < 1)
		return ;
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->content = (*g_stack_a)->content;
	new->next = (*g_stack_b);
	if (*g_stack_b)
		(*g_stack_b)->prev = new;
	(*g_stack_b) = new;
	(*g_stack_b)->prev = NULL;
	head = (*g_stack_a);
	(*g_stack_a) = head->next;
	(*g_stack_a)->prev = NULL;
	free (head);
	write(1, "pb\n", 3);
}

void	rb(t_list **g_stack_b)
{
	t_list	*head;
	t_list	*new;

	if (!*g_stack_b || ft_lstsize((*g_stack_b)) <= 1)
		return ;
	head = *g_stack_b;
	new = ft_lstnew((*g_stack_b)->content);
	ft_lstadd_back(&head, new);
	(*g_stack_b) = (*g_stack_b)->next;
	(*g_stack_b)->prev = NULL;
	free (head);
	write(1, "rb\n", 3);
}

void	sb(t_list **g_stack_b)
{
	t_list	*head;
	t_list	*second;
	int		temp;

	if (!*g_stack_b || ft_lstsize(*g_stack_b) <= 1)
		return ;
	head = (*g_stack_b);
	second = (*g_stack_b)->next;
	temp = head->content;
	head->content = second->content;
	second->content = temp;
	write(1, "sb\n", 3);
}

void	rrb(t_list **g_stack_b)
{
	t_list	*head;
	t_list	*last;
	t_list	*new;

	if (ft_lstsize(*g_stack_b) <= 1)
		return ;
	head = (*g_stack_b);
	last = ft_lstlast((*g_stack_b));
	new = ft_lstnew(last->content);
	ft_lstadd_front(&(*g_stack_b), new);
	while (head->next != NULL)
	{
		last = head;
		head = head->next;
	}
	last->next = NULL;
	free (head);
	write(1, "rrb\n", 4);
}

void	ss(t_list **g_stack_a, t_list **g_stack_b)
{
	sa(&(*g_stack_a));
	sb(&(*g_stack_b));
}
