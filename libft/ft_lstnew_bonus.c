/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 08:57:30 by iharile           #+#    #+#             */
/*   Updated: 2022/02/16 09:00:12 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*x;

	x = malloc (sizeof(t_list));
	if (!x)
		return (0);
	x->prev = NULL;
	x->content = content;
	x->next = NULL;
	return (x);
}
