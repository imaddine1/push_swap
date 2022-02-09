/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:59:57 by iharile           #+#    #+#             */
/*   Updated: 2022/02/09 16:20:19 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	pb(void)
{
	t_list	*head;
	t_list	*new;

	if (!g_stack_a)
		return ;
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->content = g_stack_a->content;
	new->next = g_stack_b;
	g_stack_b = new;
	head = g_stack_a;
	g_stack_a = head->next;
	free (head);
}

void	pa(void)
{
	t_list	*head;
	t_list	*new;

	if (!g_stack_b)
		return ;
	head = g_stack_b;
	new = malloc (sizeof(t_list));
	if (!new)
		return ;
	new->content = g_stack_b->content;
	new->next = g_stack_a;
	g_stack_a = new;
	head = g_stack_b;
	g_stack_b = g_stack_b->next;
	free(head);
}
