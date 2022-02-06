/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:52:27 by iharile           #+#    #+#             */
/*   Updated: 2022/02/06 14:18:12 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*current;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		current = *lst;
		(*del)((*lst)->content);
		*lst = (*lst)->next;
		free (current);
	}
}
