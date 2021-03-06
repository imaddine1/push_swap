/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:18:44 by iharile           #+#    #+#             */
/*   Updated: 2022/02/27 17:11:54 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>

int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
typedef struct s_list
{
	struct s_list	*prev;
	int				content;
	struct s_list	*next;
}	t_list;
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
//void	ft_lstdelone(t_list *lst, void (*del)(int));
//void	ft_lstclear(t_list **lst, void (*del)(int));
//void	ft_lstiter(t_list *lst, void (*f)(int));
//t_list	*ft_lstmap(t_list *lst, int (*f)(int), int (*del)(int));
#endif
